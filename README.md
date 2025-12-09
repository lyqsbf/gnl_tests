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
* **Buffer Size:** Testing with different BUFFER_SIZE values (small, large, 1, and the file size itself).
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

Ensure your `get_next_line` function and any necessary helper functions are compiled. Its prototype must be available in a header file named **`get_next_line.h`**. Both files must be located in the **root directory** of this test repository.

### 2. Compilation

```bash
cc -Wall -Wextra -Werror (all the files you need).c main_you_want_to_use.c -o test_runner
```
In case that you want to change the BUFFER_SIZE you need to compile with the following rule:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=`number` (all the files you need).c main_you_want_to_use.c -o test_runner
```

**⚠️ Replace** `main_you_want_to_use.c` with the name of the main you want to execute (e.g., `mainbonus.c`).
**⚠️ Replace** `number` with the value of the BUFFER_SIZE you want to assign (e.g., `42`).

Note: There's a short explanaition in each main that explains its implementation
Note: If you try to assing BUFFER_SIZE a negative value it should still compile, but in that case your function should return `NULL`.

---
### 3. Execution

After compiling, execute the genereted test program:

```bash
./test_runner test_file1 test_file2 test_file3
```
**⚠️ Replace** `test_file1` `test_file2` `test_file3` with the name of the files you want to execute (e.g., `2_long_lines` `nothing` `no_new_line`).

---
### 4. Memory leaks

If you want to check if any memory leak is generated during the execution of your program, you can use the following command:

```bash
valgrind --leak-check=full ./test_runner test_file1 test_file2 test_file3
```
**⚠️ Replace** `test_file1` `test_file2` `test_file3` with the name of the files you want to execute (e.g., `2_long_lines` `nothing` `no_new_line`).

---
## 🤝 Contributions (Reporting Issues)

Contributions are highly welcome and are crucial for improving the quality of this test suite!
If you encounter any issue, please **open an issue** in this repository.

---
### How to Contribute

1.  **Report an Issue:** Open a new *Issues* tab on GitHub and describe the error you found, including the **exact test case** that is failing or missing.
2.  **Submit a Pull Request (Optional):** If you have created a new test to fix the problem, you can directly submit a *Pull Request* for us to review and integrate.

**Your collaboration ensures that this test suite is as robust and complete as possible for the entire community.**
