import os
import platform
import subprocess
import tkinter as tk
from tkinter import messagebox


SCRIPT_PATH = os.path.abspath(
    os.path.join(os.path.dirname(__file__), os.pardir, "Generate BG3 Diagnostic.bat")
)


def run_diagnostic():
    if platform.system() != "Windows":
        messagebox.showinfo(
            "Unsupported",
            "Diagnostic script is only available on Windows.",
        )
        return
    if not os.path.exists(SCRIPT_PATH):
        messagebox.showerror("Error", f"Script not found: {SCRIPT_PATH}")
        return
    try:
        subprocess.run(["cmd", "/c", SCRIPT_PATH], check=True)
        messagebox.showinfo(
            "Finished",
            "Diagnostic completed. Check your TEMP folder for 'BG3 Diagnostic Data.txt'.",
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
