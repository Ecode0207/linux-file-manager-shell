# 📁 File Manager (C++ - Filesystem Based)

A simple **File Manager** built using **C++17 and std::filesystem**.
This project allows users to perform basic file operations through a **menu-driven interface** without using system calls.

---

## 🚀 Features

* 📄 Create File
* ❌ Delete File
* 📂 List Files in Directory
* 📖 Read File Content
* ✍️ Write to File (Append Mode)
* 🔄 Rename File
* 📁 Create Folder
* 🔍 Search File (Recursive)

---

## 🛠️ Technologies Used

* C++17
* `std::filesystem`
* File Handling (`fstream`)

---

## 📂 Project Structure

```
project/
│
├── main.cpp
├── README.md
```

---

## ⚙️ How to Compile & Run

### 🔹 Step 1: Compile

```bash
g++ -std=c++17 main.cpp -o filemanager
```

### 🔹 Step 2: Run

```bash
./filemanager
```

---

## 🖥️ Sample Output

```
===== File Manager =====
1. Create File
2. Delete File
3. List Files
4. Read File
5. Write File
6. Rename File
7. Create Folder
8. Search File
9. Exit
Enter choice:
```

---

## 💡 How It Works

* Uses `std::filesystem` for file operations
* Uses `fstream` for reading/writing files
* Menu-driven system handles user interaction
* No use of system calls like `fork()` or `exec()`

---

## ⚠️ Limitations

* No GUI (Command-line only)
* No copy/move functionality
* Limited error handling

---

## 🚀 Future Improvements

* Add Copy (`cp`) and Move (`mv`)
* Add colored terminal UI
* Add command-based shell mode
* Add file permissions handling

---

## 👨‍💻 Author

* Vishnu Kumhar

---

## 📜 License

This project is open-source and free to use.
