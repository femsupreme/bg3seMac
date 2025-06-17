#include <iostream>

extern "C" int bg3se_stub()
{
    std::cerr << "BG3 Script Extender is not yet supported on macOS Sequoia 15.5" << std::endl;
    return -1;
}
