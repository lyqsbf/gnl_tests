# 🧪 get_next_line Tester

A **Spanish** version of the README is also available (see document `README_es.md`)
---
This is a **robust and constantly growing test suite** designed to verify the accuracy, memory handling, and behavior of your `get_next_line` function implementation for reading lines from a file descriptor.

---

## 🎯 Test Coverage

The goal of this suite is to ensure your `get_next_line` is **100% functional** and complies with all subject requirements, including correct return values, memory management, and behavior under various file conditions.

### 1. Core Functionality

The following scenarios are exhaustively tested:

* **Standard Files:** Reading from regular text files.
* **Variable Line Lengths:** Files containing short, long, and extremely long lines.
* **Buffer Size ($BUFFER\_SIZE$):** Testing with different $BUFFER\_SIZE$ values (small, large, 1, and the file size itself).
* **Multiple File Descriptors:** Simultaneous reading from several open file descriptors.
* **Line Endings:** Correctly handling lines ending with `\n`, lines without `\n`, and an empty file.

### 2. Edge Cases and Error Handling

Critical situations are evaluated to ensure robustness:
* **Invalid File Descriptors:** Passing non-existent or closed file descriptors (e.g., -1, 42).
* **Reading from Standard Input (FD 0):** Ensuring the function works interactively.
* **Binary Files:** Checking for correct behavior when reading non-text data.
* **Memory Leaks:** Rigorous checks to confirm no memory is lost during execution, especially when $get\_next\_line$ is called repeatedly or encounters an error.

---

## ⚙️ Usage and Integration

### 1. Requirements

Ensure your `get_next_line` function and any necessary helper functions are compiled into a static library named **`libgnl.a`** (or similar, depending on your structure). Its prototype must be available in a header file named **`get_next_line.h`**. Both files must be located in the **root directory** of this test repository.

> **Note:** The exact names (`libgnl.a`, `get_next_line.h`) should match the names your `Makefile` or project structure uses.

### 2. Compilation and Linking

#### 2.1. Library Preparation

Make sure you have previously run the `make` command in your `get_next_line` repository to generate the **`libgnl.a`** file.

#### 2.2. Linking the Tests

Once `libgnl.a` is ready, you can compile the test file and **link** it with your library using the following command:

```bash
cc test_file_name.c -L. -lgnl -o test_runner
