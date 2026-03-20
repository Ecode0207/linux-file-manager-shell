# Linux File Manager + Custom Shell

## Features
- File create, delete, read, write
- Custom shell
- Pipe support
- Background execution
- Command history

## Tech
- C++
- Linux system calls


## ⚠️ Note on Running the Project (Linux vs Windows)

This project is developed and tested in a Linux environment.

* The source code files (`.cpp`) can be opened on any system (Windows/Linux).
* The compiled executables (`fm`, `shell`) are Linux binaries (ELF format) and will **not work on Windows**.

### ❗ Common Issue

If you try to open compiled files like `fm` or `shell` in Windows VS Code, you may see:

> "The file is not displayed in the text editor because it is either binary or uses an unsupported text encoding."

This happens because these files are not text files, but compiled binaries.

### ✅ Recommended Setup

* Use Linux terminal or WSL
* Open project using:

  ```bash
  code .
  ```
* Always open `.cpp` files (source code), not compiled executables

### 🧠 Key Takeaway

```
.cpp files → portable (can open anywhere)
compiled binaries → platform-specific (Linux only)
```
