*This project has been created as part of the 42 curriculum by <mrayamma@student.42abudhabi.ae>*

## Description

**`libft`**: The goal of this project is to rebuild a subset of the C standard library functions from scratch, along with a set of custom utility functions and linked list data structures. 

This library serves as a foundational toolkit for future 42 projects in compliance with the **42 Norm** coding standard.

---

## Instructions

### Compilation
The project includes a fully automated **Makefile** to compile the library archive (`libft.a`).

* **Compile functions:**
 ```bash
make 		#	or make all (compiles mandatory)
make clean 	#	removes object files
make fclean 	#	removes object files and libft.a
make re 	#	re-compiles everything
 ```
---

## Resources

### cppreference.com
 Standard Library Documentation – For precise specifications, edge cases, and return values of standard library functions

### Google Gemini
For Debugging, Edge-Case Analysis and Conceptual Explanations.

---

## Library Details

The library is organized into three main categories of functions:

### 1. Libc Functions
A set of standard C library functions (with the `ft_` prefix):
* **Character checks & conversions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
* **String inspection:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`
* **Memory operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`, `ft_strdup`
* **Conversion:** `ft_atoi`


### 2. Additional Functions
A set of functions for string manipulation & file access and modification:
* **String manipulation:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`, `ft_itoa`
* **File descriptor output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`


### 3. Linked List Functions
A set of functions for managing linked lists (`t_list`):
* **Creation & Initialization:** `ft_lstnew`
* **Insertion:** `ft_lstadd_front`, `ft_lstadd_back`
* **Inspection & Sizing:** `ft_lstsize`, `ft_lstlast`
* **Iteration & Mapping:** `ft_lstiter`, `ft_lstmap`
* **Memory Deallocation:** `ft_lstdelone`, `ft_lstclear`

---
