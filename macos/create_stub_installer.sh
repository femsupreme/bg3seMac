#!/usr/bin/env bash
# Build the bg3se stub and generate a .pkg installer for macOS.
# The installer places libbg3se.dylib into the standard BG3 application folder.
set -euo pipefail

BUILD_DIR="$(pwd)/build"
INSTALL_ROOT="$(pwd)/macos/pkgroot"
PKG_NAME="bg3se_stub_installer.pkg"

rm -rf "$BUILD_DIR" "$INSTALL_ROOT" "$PKG_NAME"
mkdir -p "$BUILD_DIR" "$INSTALL_ROOT/Applications/Baldur's Gate 3.app/Contents/MacOS"

# Build the stub
pushd "$BUILD_DIR" >/dev/null
cmake ..
make
popd >/dev/null

# Copy stub into pkg root
cp "$BUILD_DIR/libbg3se.dylib" "$INSTALL_ROOT/Applications/Baldur's Gate 3.app/Contents/MacOS/"

pkgbuild \
    --identifier "dev.norbyte.bg3se.stub" \
    --version "1.0" \
    --root "$INSTALL_ROOT" \
    "bg3se_stub_component.pkg"

productbuild \
    --package "bg3se_stub_component.pkg" \
    "$PKG_NAME"

rm -f bg3se_stub_component.pkg

cat <<EOM
Created installer: $PKG_NAME
This package installs libbg3se.dylib into /Applications/Baldur's Gate 3.app/Contents/MacOS/
EOM

