*This project has been created as part of the 42 curriculum by <your_login>.*

# push_swap

## Description

**push_swap** is an algorithmic sorting project developed in C as part of the 42 curriculum.

The goal of this project is to sort a list of arbitrary 32-bit signed integers using two stacks (`A` and `B`) and a limited set of predefined operations. The challenge is to produce an ordered stack using the smallest possible number of operations while respecting the project's constraints.

Unlike traditional sorting algorithms, `push_swap` does not directly rearrange array elements. Instead, it generates a sequence of stack instructions that, when executed, sorts the input in ascending order.

The project implements an **adaptive sorting controller** that analyzes the initial disorder of the input and selects an appropriate sorting algorithm depending on its characteristics.

### Main Features

- Coordinate compression to normalize integer values into zero-based ranks.
- An inversion-based disorder metric to evaluate input organization.
- Three sorting strategies with different complexity characteristics.
- An adaptive controller that automatically selects a strategy.
- Support for explicit strategy selection through command-line flags.
- Input validation, duplicate detection, and overflow-safe integer parsing.
- Memory management and compatibility with the 42 Norm.

### Available Operations

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of Stack A. |
| `sb` | Swap the first two elements of Stack B. |
| `ss` | Perform `sa` and `sb` simultaneously. |
| `pa` | Push the top element of B onto A. |
| `pb` | Push the top element of A onto B. |
| `ra` | Rotate Stack A upwards. |
| `rb` | Rotate Stack B upwards. |
| `rr` | Perform `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate Stack A. |
| `rrb` | Reverse rotate Stack B. |
| `rrr` | Perform `rra` and `rrb` simultaneously. |

---

## Instructions

### Compilation

The project uses a Makefile to compile the executable.

Clone the repository and enter its directory:

```bash
git clone <repository-url>
cd push_swap
````

Compile the project:

bash

```bash
make
```

The Makefile supports the standard 42 rules:

bash

```bash
make        # Compile the project
make all    # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

After successful compilation, the `push_swap` executable will be available at the root of the project.

### Execution

The program accepts integers as command-line arguments.

Default Mode — Adaptive Strategy:

bash

```bash
./push_swap 42 -5 100 0 17
```

Quoted String Arguments:

bash

```bash
./push_swap "42 -5 100 0 17"
```

Explicit Strategy Selection:

bash

```bash
./push_swap --simple 42 -5 100 0 17
./push_swap --medium 42 -5 100 0 17
./push_swap --complex 42 -5 100 0 17
./push_swap --adaptive 42 -5 100 0 17
```

If no strategy flag is provided, the program automatically selects a sorting algorithm based on the measured disorder of Stack A.

### Testing and Verification

The generated instructions can be verified using the official or compatible `checker_linux` program.

Generate a random input:

bash

```bash
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000, 1000), 100))))")
```

Check whether the generated instructions correctly sort the stack:

bash

```bash
./push_swap --adaptive $ARG | ./checker_linux $ARG
```

Expected output:

text

```text
OK
```

Count the number of generated operations:

bash

```bash
./push_swap --adaptive $ARG | wc -l
```

Check memory management with Valgrind:

bash

```bash
valgrind --leak-check=full ./push_swap --adaptive $ARG > /dev/null
```

Check compliance with the 42 Norm:

bash

```bash
norminette *.c *.h
```

## Technical Architecture

### Data Representation

The project uses a two-layer linked-list architecture.

`t_node`

Each node stores:

- `value`: The original integer provided by the user.
- `index`: The normalized rank of the integer.
- `next`: A pointer to the next node.

`t_stack`

Each stack maintains:

- `top`: A pointer to its first node.
- `size`: The current number of elements.

This representation allows efficient stack operations without shifting array elements.

### Coordinate Compression

Before sorting begins, the original integer values are converted into normalized ascending ranks using `ft_assign_index`.

For an input containing `n` unique integers, each integer receives a rank in the range:

text

```text
0 to n - 1
```

For example:

text

```text
Original values:  42  -5  100  0  17
Normalized ranks:  3   0    4  1   2
```

Coordinate compression provides several advantages:

- Eliminates gaps between integer values.
- Makes comparisons independent of the original integer magnitude.
- Avoids arithmetic operations on potentially extreme integer values during sorting.
- Enables deterministic binary radix sorting.
- Simplifies chunk partitioning.

## Algorithms and Strategy Selection

The main feature of this project is its disorder-driven adaptive controller.

Instead of always applying the same sorting algorithm, the program measures the initial disorder of Stack A and selects a strategy based on the result.

### 1. Disorder Metric

The disorder metric is calculated using the normalized inversion ratio.

An inversion occurs when an element appears before another element that has a smaller normalized rank.

The formula is:

$$ d = \\frac $$

Where:

- `d` represents the disorder ratio.
- `I` represents the total number of inversions.
- `n` represents the number of elements in Stack A.
- `n(n-1)/2` represents the maximum possible number of inversions.

The resulting value ranges from 0 to 1.

| Disorder | Interpretation |
| --- | --- |
| `d = 0.0` | Completely sorted input. |
| `d ≈ 0.5` | Typical random permutation. |
| `d = 1.0` | Completely reverse-sorted input. |

The calculation is performed by `ft_compute_disorder`.

If the input is already sorted, the program exits immediately without generating unnecessary instructions.

### 2. Simple Strategy — Min-Extraction Selection Sort

Function: `ft_sort_simple`

Complexity: `O(n²)`

The simple strategy repeatedly extracts the smallest remaining element from Stack A and moves it to Stack B.

The algorithm works as follows:

1. Find the minimum element in Stack A.
2. Determine its position.
3. Calculate whether `ra` or `rra` provides the shortest path to the top.
4. Rotate Stack A until the minimum reaches the top.
5. Push the minimum onto Stack B using `pb`.
6. Repeat until the remaining elements can be sorted directly.
7. Push the extracted elements back onto Stack A using `pa`.

An early-sorted check avoids unnecessary operations when the remaining stack is already ordered.

Why this algorithm?

For relatively ordered inputs, repeatedly extracting minimum elements can be practical because only a limited number of elements may need to be repositioned.

The strategy is particularly suitable for small inputs and low-disorder cases, where the overhead of more sophisticated algorithms may not be worthwhile.

Complexity:

- Time: `O(n²)`
- Auxiliary space: `O(n)` total stack nodes.

### 3. Medium Strategy — Sliding √n Chunk Sort

Function: `ft_sort_medium`

Complexity target: `O(n√n)`

The medium strategy divides the normalized rank range into chunks using a window approximately equal to the square root of the input size.

The chunk width is calculated as:

$$ w = \\lfloor \\sqrt \\rfloor $$

The algorithm has two main phases.

Phase 1 — Distribute Elements into Stack B

1. Define the current rank window.
2. Search Stack A for elements belonging to that window.
3. Rotate Stack A to bring matching elements to the top.
4. Push matching elements into Stack B using `pb`.
5. Optionally rotate Stack B using `rb` to improve the distribution of its elements.
6. Advance the window until all elements have been distributed.

Phase 2 — Reconstruct Stack A

1. Find the maximum remaining rank in Stack B.
2. Determine its position.
3. Use `rb` or `rrb` to bring it to the top through the shorter rotation path.
4. Push it back to Stack A using `pa`.
5. Repeat until Stack B is empty.

Why this algorithm?

Chunk sorting provides a balance between partitioning and element retrieval.

Instead of processing every element individually through minimum extraction, the algorithm groups elements into rank ranges. This reduces the search space during reconstruction and can perform well on partially ordered inputs.

The square-root window provides a balance between the number of chunks and the number of elements handled in each chunk.

Complexity:

- Time target: `O(n√n)`, subject to the actual rotation and partitioning implementation.
- Auxiliary space: `O(n)` total stack nodes.

### 4. Complex Strategy — LSD Binary Radix Sort

Function: `ft_sort_complex`

Complexity: `O(n log n)`

The complex strategy implements Least Significant Digit (LSD) binary radix sorting.

Since coordinate compression converts all values into ranks from `0` to `n - 1`, the algorithm can sort elements by examining their binary representations.

For example:

text

```text
Rank:   3    1    4    0    2
Binary: 011  001  100  000  010
```

The number of required bit passes is:

$$ b = \\lceil \\log\_2(n) \\rceil $$

For every bit position, starting with the least significant bit:

1. Inspect the top element of Stack A.
2. Check the current bit of its normalized rank.
3. If the bit is `0`, push the element to Stack B using `pb`.
4. If the bit is `1`, rotate Stack A using `ra`.
5. Continue until all original elements have been processed.
6. Push all elements from Stack B back to Stack A using `pa`.
7. Move to the next bit position.

After processing all bit positions, Stack A is sorted in ascending order.

Why this algorithm?

Binary radix sort avoids repeatedly searching for minimum or maximum elements.

Its operation count depends on the number of bits required to represent the normalized ranks rather than the original values or their distribution.

This makes it particularly suitable for large, highly disordered inputs.

Complexity:

- Time: `O(n log n)`.
- Auxiliary space: `O(n)` total stack nodes.

## Adaptive Controller

Function: `ft_sort_adaptive`

The adaptive controller combines the three algorithms using the measured disorder ratio.

The selection thresholds are:

| Disorder range | Selected algorithm | Complexity |
| --- | --- | --- |
| `d < 0.2` | Simple — Min Extraction | `O(n²)` |
| `0.2 ≤ d < 0.5` | Medium — Chunk Sort | Target `O(n√n)` |
| `d ≥ 0.5` | Complex — Binary Radix | `O(n log n)` |

### Justification of Thresholds

Low Disorder: `d < 0.2`

When fewer than 20% of all possible element pairs are inverted, the input has relatively few inversions.

Minimum extraction with shortest-path rotations can be effective for small or nearly sorted inputs. An early-sorted check also avoids unnecessary operations.

Medium Disorder: `0.2 ≤ d < 0.5`

This range represents partially ordered inputs, including inputs containing sorted runs or locally shuffled blocks.

Chunk partitioning groups nearby ranks together and reduces the need for repeated global searches.

The square-root partition size balances chunk processing and reconstruction.

High Disorder: `d ≥ 0.5`

At or above the expected inversion ratio of a uniformly random permutation, positional searching can become expensive.

Binary radix sort offers a predictable number of passes and avoids repeated minimum or maximum searches.

It therefore provides a suitable strategy for highly disordered and larger inputs.

Note: These thresholds are heuristic design choices, not mathematically proven optimal boundaries. Actual operation counts depend on input size, permutation structure, and the implementation of each strategy.

## Complexity Summary

| Strategy | Algorithm | Time complexity | Space complexity |
| --- | --- | --- | --- |
| Simple | Min-Extraction Selection Sort | `O(n²)` | `O(n)` |
| Medium | Sliding √n Chunk Sort | Target `O(n√n)` | `O(n)` |
| Complex | LSD Binary Radix Sort | `O(n log n)` | `O(n)` |

In this project, time complexity refers to the number of stack instructions generated rather than conventional CPU execution time.

Space complexity refers to the total heap-allocated stack nodes across Stack A and Stack B. The nodes are transferred between stacks rather than duplicated.

## Project Structure

text

```text
.
├── Makefile
├── push_swap.h
├── main.c
├── parse_args.c
├── parse_utils.c
├── stack_init.c
├── op_swap.c
├── op_push.c
├── op_rotate.c
├── op_rev_rotate.c
├── sort_controller.c
├── sort_simple.c
├── sort_medium.c
├── sort_complex.c
└── libft/
```

### File Responsibilities

| File | Responsibility |
| --- | --- |
| `Makefile` | Compilation and project management. |
| `push_swap.h` | Structures, enums, and function prototypes. |
| `main.c` | Program entry point, argument handling, and memory lifecycle. |
| `parse_args.c` | Argument splitting and array assembly. |
| `parse_utils.c` | Integer parsing, validation, overflow checks, and duplicate detection. |
| `stack_init.c` | Stack initialization, node allocation, rank assignment, and cleanup. |
| `op_swap.c` | Swap operations. |
| `op_push.c` | Push operations. |
| `op_rotate.c` | Rotation operations. |
| `op_rev_rotate.c` | Reverse rotation operations. |
| `sort_controller.c` | Sorted checks, disorder calculation, and adaptive strategy selection. |
| `sort_simple.c` | Min-extraction sorting strategy. |
| `sort_medium.c` | Sliding square-root chunk sorting strategy. |
| `sort_complex.c` | LSD binary radix sorting strategy. |
| `libft/` | Custom C utility library. |

## Resources

The following resources are useful for understanding the concepts and techniques used in this project.

### Documentation

- [42 School](<https://42.fr/?utm_source=chatgpt.com>) — Information about the 42 curriculum and its projects.
- [C Programming Language Reference](<https://en.cppreference.com/w/c?utm_source=chatgpt.com>) — C language reference and standard library documentation.
- [GNU Make Manual](<https://www.gnu.org/software/make/manual/?utm_source=chatgpt.com>) — Makefile syntax and compilation rules.
- [Valgrind Documentation](<https://valgrind.org/docs/manual/manual.html?utm_source=chatgpt.com>) — Memory debugging and leak detection.

### Algorithm References

- [Selection Sort](<https://en.wikipedia.org/wiki/Selection_sort?utm_source=chatgpt.com>) — Fundamentals of selection-based sorting.
- [Inversion Count](<https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)?utm_source=chatgpt.com>) — Mathematical definition of inversions and permutation disorder.
- [Coordinate Compression](<https://usaco.guide/silver/sorting-custom?utm_source=chatgpt.com>) — Rank normalization and sorting techniques.
- [Radix Sort](<https://en.wikipedia.org/wiki/Radix_sort?utm_source=chatgpt.com>) — LSD and MSD radix sorting concepts.
- [Square Root Decomposition](<https://cp-algorithms.com/data_structures/sqrt_decomposition.html?utm_source=chatgpt.com>) — Square-root partitioning concepts.

### AI Usage

Artificial Intelligence tools were used as supplementary learning and development resources throughout this project.

AI assistance was used for:

- Algorithm research: Understanding selection sort, chunk-based sorting, binary radix sort, and inversion counting.
- Algorithm analysis: Exploring time and space complexity and comparing the advantages and disadvantages of different sorting approaches.
- Adaptive strategy design: Evaluating possible disorder thresholds and understanding how input characteristics can influence algorithm selection.
- Documentation: Organizing the README, improving technical explanations, and presenting the project architecture and algorithm choices clearly.
- Testing guidance: Identifying useful test cases, checker commands, and memory verification techniques.

AI was used as an explanatory and documentation assistant. The project implementation, testing, debugging, and final validation should be reviewed and understood by the author. All generated suggestions must be checked against the actual source code and the 42 subject requirements.

## Author

Login:

Project: push\_swap

Language: C

School: 42
