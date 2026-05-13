*This project has been created as part of the 42 curriculum by pboucher*

# Libft

## Description

**Libft** is the foundational C project of the 42 Common Core. The goal is to reimplement from scratch a curated set of standard C library functions — and to add extra utility functions not found in the standard library — building a personal static library (`libft.a`) that will be reused throughout all future 42 projects.

The project is split into three parts:

1. **Libc reimplementations** — faithful replicas of standard functions (`ft_strlen`, `ft_memcpy`, `ft_atoi`, etc.) that behave identically to their originals.
2. **Additional utility functions** — functions absent from the standard library but useful in practice (`ft_substr`, `ft_split`, `ft_itoa`, `ft_strmapi`, etc.).
3. **Bonus — linked list** — a generic singly-linked list (`t_list`) with a full set of manipulation functions.

## Library

### Character checks & conversions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns non-zero if `c` is an alphabetic character |
| `ft_isdigit` | Returns non-zero if `c` is a decimal digit |
| `ft_isalnum` | Returns non-zero if `c` is alphanumeric |
| `ft_isascii` | Returns non-zero if `c` is a 7-bit ASCII character |
| `ft_isprint` | Returns non-zero if `c` is a printable character |
| `ft_toupper` | Converts a lowercase letter to its uppercase equivalent |
| `ft_tolower` | Converts an uppercase letter to its lowercase equivalent |

### String functions

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a null-terminated string |
| `ft_strlcpy` | Copies `src` into `dst` with a size limit; returns `strlen(src)` |
| `ft_strlcat` | Appends `src` to `dst` with a size limit; returns combined length |
| `ft_strchr` | Returns a pointer to the first occurrence of `c` in the string |
| `ft_strrchr` | Returns a pointer to the last occurrence of `c` in the string |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_strnstr` | Locates `little` inside `big`, searching at most `len` bytes |
| `ft_strdup` | Returns a malloc'd duplicate of the string |
| `ft_substr` | Returns a malloc'd substring of `s` starting at `start` |
| `ft_strjoin` | Returns a malloc'd concatenation of `s1` and `s2` |
| `ft_strtrim` | Returns a malloc'd copy of `s1` with leading/trailing `set` chars removed |
| `ft_split` | Returns a malloc'd array of strings split by delimiter `c` |
| `ft_strmapi` | Applies `f` to each character; returns the resulting malloc'd string |
| `ft_striteri` | Applies `f` to each character of `s` in-place, passing the index |

### Number conversions

| Function | Description |
|---|---|
| `ft_atoi` | Converts the string representation of an integer to an `int` |
| `ft_itoa` | Converts an `int` to its malloc'd string representation |

### Memory functions

| Function | Description |
|---|---|
| `ft_memset` | Fills `n` bytes of memory area `s` with constant byte `c` |
| `ft_bzero` | Sets `n` bytes of memory area `s` to zero |
| `ft_memcpy` | Copies `n` bytes from `src` to `dest` (no overlap) |
| `ft_memmove` | Copies `n` bytes from `src` to `dest` (overlap-safe) |
| `ft_memchr` | Scans `n` bytes of `s` for the first occurrence of byte `c` |
| `ft_memcmp` | Compares the first `n` bytes of two memory areas |
| `ft_calloc` | Allocates `nmemb * size` bytes, zero-initialised |

### File descriptor output

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd` | Writes string `s` to file descriptor `fd` |
| `ft_putendl_fd` | Writes string `s` followed by a newline to file descriptor `fd` |
| `ft_putnbr_fd` | Writes integer `n` to file descriptor `fd` |

### Bonus — Linked list (`t_list`)

```c
typedef struct s_list
{
    void         *content;
    struct s_list *next;
} t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates and returns a new node with `content` |
| `ft_lstadd_front` | Prepends a node to the list |
| `ft_lstadd_back` | Appends a node to the list |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstdelone` | Frees a single node using the `del` function |
| `ft_lstclear` | Deletes and frees all nodes of the list |
| `ft_lstiter` | Applies function `f` to the content of every node |
| `ft_lstmap` | Applies `f` to every node and builds a new list from the results |

## Instructions

### Requirements

- `cc` compiler (clang or gcc)
- GNU `make`
- No external libraries required

### Compilation

```bash
# Build the static library (libft.a)
make

# Build including bonus linked-list functions
make bonus

# Clean compiled object files
make clean

# Remove object files and the library
make fclean

# Full rebuild from scratch
make re
```

### Running the test suite

```bash
# Compile the library then the test main
make && cc -Wall -Wextra -Werror main.c -L. -lft -I include -o test_libft

# Execute
./test_libft
```

### Using the library in another project

```c
#include "libft.h"
```

```bash
cc your_file.c -L/path/to/libft -lft -I/path/to/libft/include -o your_program
```

## Resources

### Documentation & references

- [GNU C Library manual](https://www.gnu.org/software/libc/manual/html_node/index.html) — reference for the standard functions being reimplemented
- [cppreference — C standard library](https://en.cppreference.com/w/c) — function signatures and behaviour
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — introductory C programming guide
- [man7.org](https://man7.org/linux/man-pages/) — Linux man pages for every libc function

### AI usage

GitHub Copilot (Claude Sonnet 4.6) was used during this project for the following tasks:

- **`main.c`** — generating the test suite that exercises every function in the library.
- **`README.md`** — generating the initial structure and content of this file, which was then reviewed and adapted.

The core library source files (`srcs/`) were written by hand without AI assistance.
