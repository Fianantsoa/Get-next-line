*This project has been created as part of the 42 curriculum by finoment.*

## Description

`get_next_line` is a project in the 42 curriculum that aims to implement a function capable of reading a file **line by line**.

The main goal is to create a function:

```c
char *get_next_line(int fd);
```

This function returns a complete line read from a file descriptor (`fd`), including the newline character (`\n`) if present. Each call retrieves the next line until the end of the file is reached or an error occurs.

This project helps you understand and master:

* Reading from a file descriptor using `read()`
* Dynamic memory management
* Buffer usage and manipulation
* Handling multiple files simultaneously (bonus version)
* Optimizing and managing edge cases (EOF, errors, empty files, etc.)

In summary, `get_next_line` is a fundamental C systems programming exercise that develops rigor in memory management and data stream handling.

---

## Instructions

### Installation

First, clone the repository:

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-5916f39c-6256-41de-a41d-0258fff90513-7286879-finoment GNL
cd GNL
```

> Note: The repository URL may change depending on the project or user.
> The general format is:

```bash
git clone <repository_url> <folder_name>
cd <folder_name>
```

### Usage

Include the header in your C files:

```c
#include "get_next_line.h"
```

Example usage with `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

and file `test.txt`:

```txt
Hello world
This is a test
42 project
```

Compile your project with:

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
```

> Note: `BUFFER_SIZE` defines the number of bytes read per call to `read()`.
> A small value (e.g., 4) reads in small chunks, while a large value reads more data at once.
> This affects performance but should not change the function’s behavior.
> The `-D BUFFER_SIZE=42` sets the macro at compilation without modifying the header file.

Example:

```bash
-D BUFFER_SIZE=42
```
This generates a compiled binary named `a.out`.
Run the program in the terminal:
```bash
./a.out
```
Output:
```bash
Hello world
This is a test
42 project
```

## Resources

### Classic References

* Linux manual pages (`man free`, `man read`, `man malloc`)
* W3Schools — C programming tutorials https://www.w3schools.com/c/
* Tutorialspoint C https://www.tutorialspoint.com/cprogramming/index.htm

### AI Usage

AI is used solely as an educational tool to understand how `get_next_line` works and to structure documentation. It does not implement the code or make technical decisions.

* Helps explain line-by-line reading from a file
* Assists in understanding buffer and memory management
* Clarifies concepts or documents sections

In short: AI explains and guides, but all code remains 100% manual.

---

## Algorithm and Data Structure Explanation

### 🧩 Algorithm Explanation

#### Algorithm Structure

1. **Reading the file**:

   * `get_next_line(int fd)` reads the file using `read()` with a size defined by `BUFFER_SIZE`.
   * The read data is stored temporarily in a **buffer**.

2. **Data accumulation**:

   * Read content is added to a **stash** (static storage) to preserve data between calls.
   * The stash is **static** so its value persists across function calls.

3. **Line extraction**:

   * Once a `\n` is found or the end of the file is reached, the complete line is extracted from the stash.
   * The stash is then updated to remove the portion already returned.

4. **Utility functions**:

   * Operations like concatenation (`ft_strjoin()`), newline search (`ft_strchr()`), and memory allocation are implemented in `get_next_line_utils.c` to keep the main function clean and readable.
   * Prototypes and variables are defined in `get_next_line.h`.

---

#### Algorithm Justification

* **Simplicity**: A single function `get_next_line()` handles reading and line extraction, making it easy to use.
* **Memory safety**: The static stash preserves read data without losing memory or rereading the file unnecessarily.
* **Flexibility**: Buffer-based reading adapts to different `BUFFER_SIZE` values and handles very large files efficiently.
* **Modularity**: Utility functions separate secondary operations, making the code clearer, testable, and maintainable.
* **Compliance with 42 standards**: The algorithm meets project constraints (line-by-line reading, dynamic memory management, handling EOF and errors).

---

#### Simplified Algorithm Diagram

```
[fd] ---> read(buffer) ---> stash (static)
                       └──> search for '\n'
                       └──> extract line
                       └──> update stash
return line
```

---
