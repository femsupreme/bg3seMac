import os
import platform
import subprocess
import tkinter as tk
from tkinter import messagebox


BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))
WINDOWS_SCRIPT_PATH = os.path.join(BASE_DIR, "Generate BG3 Diagnostic.bat")
MAC_SCRIPT_PATH = os.path.join(BASE_DIR, "Generate BG3 Diagnostic.sh")


def run_diagnostic():
    system = platform.system()

    if system == "Windows":
        script = WINDOWS_SCRIPT_PATH
        cmd = ["cmd", "/c", script]
        out_dir = os.getenv("TEMP", os.getcwd())
    elif system == "Darwin":
        script = MAC_SCRIPT_PATH
        cmd = ["bash", script]
        out_dir = os.getenv("TMPDIR", "/tmp")
    else:
        messagebox.showinfo(
            "Unsupported",
            "Diagnostic script is only available on Windows or macOS.",
        )
        return

    if not os.path.exists(script):
        messagebox.showerror("Error", f"Script not found: {script}")
        return
    try:
        subprocess.run(cmd, check=True)
        messagebox.showinfo(
            "Finished",
            f"Diagnostic completed. Check {out_dir} for 'BG3 Diagnostic Data.txt'.",
        )
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "Diagnostic script failed.")


def main():
    root = tk.Tk()
    root.title("BG3 Extender Test Helper")
    tk.Label(
        root,
        text="Click the button below to run diagnostics for BG3 Extender.",
        wraplength=300,
    ).pack(padx=10, pady=10)
    tk.Button(root, text="Run Diagnostic", command=run_diagnostic).pack(pady=5)
    tk.Button(root, text="Quit", command=root.quit).pack(pady=5)
    root.mainloop()


if __name__ == "__main__":
    main()
