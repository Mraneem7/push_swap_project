# Bubble Sort only — Push_swap learning prototype

This is a **runnable learning example** of the `--simple` sorting strategy.
It is **not a complete submission** for Push_swap v1.2: the medium, complex,
adaptive, disorder metric, benchmark, and remaining stack operations are absent.

## Build and run

```sh
make
./push_swap --simple 5 2 4 1
./push_swap 3 2 1
./push_swap 1 2 3
make fclean
```

`operations.c` provides `sa` and `ra`. `bubble_sort.c` performs comparisons
and calls these two allowed Push_swap operations to change the stack. The
array representation treats `values[0]` as the top.

Input: one signed integer per argument. Quoted multi-number arguments are
not supported in this simplified example.

Run `norminette` in your 42 environment before using this as learning material.
