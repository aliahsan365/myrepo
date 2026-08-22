# Programming Exercise Archive

This repository contains exercises, coursework, and experiments written between 2013 and 2026. Each source file is generally independent, and the repository is organized chronologically by year and month. It includes C, C++, x86 assembly, Haskell, Prolog, Python, and PowerShell.

The main exception to the standalone exercise format is [`2014/May/Organismos`](2014/May/Organismos), a C++ project split into several modules.

## Code Catalog

### 2013

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2013/March/computing_e_aproximation.cc`](2013/March/computing_e_aproximation.cc) | 2013-03 | C++ | Approximates Euler's number using `n` terms. | Reads values until EOF and sums `1 + 1/1! + ... + 1/(n-1)!`, updating the factorial iteratively and displaying ten decimal places. |

### 2014: Organismos

The program simulates a population of organisms. Each organism is a binary tree of cells with an identifier and an active state; it can grow, be trimmed, and reproduce. The executable processes numeric commands from standard input and maintains both the population and a reproduction ranking.

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2014/May/Organismos/pro2.cpp`](2014/May/Organismos/pro2.cpp) | 2014-05 | C++ | Serves as the experiment's entry point. | Reads the population and capacity; interprets `-1` (grow), `-2` (trim), `-3` (reproduce), `-4` (ranking), `-5` (display), and `-6` (finish). |
| [`2014/May/Organismos/Organismo.hpp`](2014/May/Organismos/Organismo.hpp) | 2014-05 | C++ | Declares the organism model. | Encapsulates an `Arbre<Celula>`, size, maximum identifier, and trimming state; exposes input, output, growth, trimming, and reproduction operations. |
| [`2014/May/Organismos/Organismo.cpp`](2014/May/Organismos/Organismo.cpp) | 2014-05 | C++ | Implements each organism's morphology and operations. | Traverses the tree recursively: growth adds two cells to each leaf, trimming processes the leaves, and reproduction combines compatible nodes from two parents. |
| [`2014/May/Organismos/Cjt_Organismo.hpp`](2014/May/Organismos/Cjt_Organismo.hpp) | 2014-05 | C++ | Declares the population container. | Maintains a vector of organisms, living and total counters, and a Boolean matrix containing the processed pairs. |
| [`2014/May/Organismos/Cjt_Organismo.cpp`](2014/May/Organismos/Cjt_Organismo.cpp) | 2014-05 | C++ | Manages operations on the population. | Pairs living organisms, adds offspring, records pairs, and delegates growth, trimming, and serialization to `Organismo`. |
| [`2014/May/Organismos/Ranking.hpp`](2014/May/Organismos/Ranking.hpp) | 2014-05 | C++ | Declares the reproduction ranking. | Models each parent with a list of partners and offspring. |
| [`2014/May/Organismos/Ranking.cpp`](2014/May/Organismos/Ranking.cpp) | 2014-05 | C++ | Updates and displays the ranking. | Records each offspring for both parents and sorts entries by number of reproductions and identifier. |
| [`2014/May/Organismos/Arbre.hpp`](2014/May/Organismos/Arbre.hpp) | 2014-05 | C++ | Provides a generic binary tree. | Implements a template with linked nodes, deep copying, recursive destruction, and root and child operations. |
| [`2014/May/Organismos/ArbIOint.hpp`](2014/May/Organismos/ArbIOint.hpp) | 2014-05 | C++ | Adds input and output operations for `Arbre<int>`. | Reads trees in preorder using a marker and writes them using an inorder traversal. |
| [`2014/May/Organismos/utils.PRO2`](2014/May/Organismos/utils.PRO2) | 2014-05 | C++ | Contains shared utilities. | Defines `PRO2Excepcio` and `read*` functions for reading basic types from `cin`. |
| [`2014/May/Organismos/Makefile`](2014/May/Organismos/Makefile) | 2014-05 | Make | Builds the Organismos project. | Compiles the modules with `g++ -D_GLIBCXX_DEBUG`, links them as `pro2.exe`, and provides the `clean` rule. |

### 2015

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2015/March/binary_search.cc`](2015/March/binary_search.cc) | 2015-03 | C++ | Searches for a `double` in a sorted vector. | Recursively divides the search interval and continues through the half that may contain the value. |
| [`2015/May/applying_BFS_algorithm.cc`](2015/May/applying_BFS_algorithm.cc) | 2015-05 | C++ | Calculates the maximum distance to a reachable treasure in a grid. | Runs BFS in four directions using a queue, a visited matrix, and a distance matrix; `X` represents obstacles and `t` represents treasures. |
| [`2015/May/bot_gameplayer_using_BFS.cc`](2015/May/bot_gameplayer_using_BFS.cc) | 2015-05 | C++ | Implements the `AliOli_v3` player for a game engine. | Selects a target based on Goku's state and strength, uses BFS to locate it, and reconstructs the first move from the distance map. |

### 2016

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2016/April/MiSimulador.c`](2016/April/MiSimulador.c) | 2016-04 | C | Simulates a direct-mapped cache with 128 lines and 32-byte blocks. | Splits each address into offset, line, and tag; counts hits and misses and models reads, writes, and replacements. |
| [`2016/April/MiSimulador2.c`](2016/April/MiSimulador2.c) | 2016-04 | C | Simulates a cache with `write-back` and `write-allocate`. | Adds a dirty bit to each line and uses it to determine transfers during misses and replacements. |
| [`2016/March/Asigna.s`](2016/March/Asigna.s) | 2016-03 | x86 Assembly | Assigns a 12-byte structure to a vector position. | Uses the 32-bit calling convention and copies the `char`, `k`, and `m` fields into `v[pos]` through offsets. |
| [`2016/March/Inserta.s`](2016/March/Inserta.s) | 2016-03 | x86 Assembly | Inserts a structure ordered by its `k` field. | Traverses the vector, shifts 12-byte records, and calls `Asignar` to place the new element. |
| [`2016/March/Practica3CompletarA.s`](2016/March/Practica3CompletarA.s) | 2016-03 | x86 Assembly | Finds equal consecutive values. | Traverses a vector using indexed addressing and retains the last position satisfying `vector[i] == vector[i-1]`. |
| [`2016/March/Practica3CompletarB.s`](2016/March/Practica3CompletarB.s) | 2016-03 | x86 Assembly | Sums a triangular selection from a `3x3` matrix. | Uses nested loops, advances rows according to `salto`, and sums positions whose column satisfies `j <= i`. |
| [`2016/May/Transformar.c`](2016/May/Transformar.c) | 2016-05 | C | Runs and measures a PGM image transformation. | Reads `in.pgm`, repeatedly invokes `procesar`, writes `out.pgm`, and measures the time using matrices aligned to 16 bytes. |
| [`2016/May/Procesar_asm.s`](2016/May/Procesar_asm.s) | 2016-05 | x86 Assembly | Implements the image transformation with scalar operations. | Preserves the least significant bit of each pixel and converts it to `0` or `255`. |
| [`2016/May/Procesar_align.s`](2016/May/Procesar_align.s) | 2016-05 | x86/SSE Assembly | Processes aligned data using SIMD. | Transforms 16 pixels per iteration using `movdqa`, `pand`, and `pcmpgtb`. |
| [`2016/May/Procesar_unal.s`](2016/May/Procesar_unal.s) | 2016-05 | x86/SSE Assembly | Processes unaligned data using SIMD. | Transforms blocks of 16 pixels with `movdqu` loads and stores. |
| [`2016/May/Procesar_dual.s`](2016/May/Procesar_dual.s) | 2016-05 | x86/SSE Assembly | Combines aligned and unaligned SIMD access. | Checks the block address and selects `movdqa` or `movdqu` before applying the mask. |

### 2018

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2018/October/queue_implementation.hs`](2018/October/queue_implementation.hs) | 2018-10 | Haskell | Implements a polymorphic functional queue. | Maintains one list for removal and another reversed list for insertion; reverses the second list when the first is exhausted. |
| [`2018/December/nqueens.pl`](2018/December/nqueens.pl) | 2018-12 | Prolog | Enumerates and draws solutions to the eight queens problem. | Uses `clpfd`, `all_different`, and diagonal constraints; labels the variables and draws each board. |
| [`2018/December/travel_selesman_problem.pl`](2018/December/travel_selesman_problem.pl) | 2018-12 | Prolog | Models a directed Hamiltonian cycle with a maximum cost. | Generates SAT clauses for position, uniqueness, adjacency, and cardinality, numbers symbolic variables, and translates the model into a route. |

### 2019

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2019/May/body_mass_index.hs`](2019/May/body_mass_index.hs) | 2019-05 | Haskell | Classifies body mass index. | Extracts a name, weight, and height, calculates `weight/height^2`, applies range guards, and processes input until `*`. |
| [`2019/May/haskell_stuff.hs`](2019/May/haskell_stuff.hs) | 2019-05 | Haskell | Groups exercises involving Roman numerals, roots, and trees. | Converts Roman numerals, approximates roots with Newton's method, and defines `LTree` construction and combination. |
| [`2019/May/high_order_functions.hs`](2019/May/high_order_functions.hs) | 2019-05 | Haskell | Exercises higher-order functions. | Combines `map`, `filter`, `foldl`, lambdas, and function application to count, transform, reduce, and sort. |
| [`2019/May/pension_computation.hs`](2019/May/pension_computation.hs) | 2019-05 | Haskell | Calculates statistics for a collection of pensioners. | Defines the `Avi` record and obtains expense averages, extreme ages, aggregates, and threshold searches. |
| [`2019/May/sorting_algorithms.hs`](2019/May/sorting_algorithms.hs) | 2019-05 | Haskell | Implements several sorting algorithms. | Includes insertion sort, recursive selection sort, merge sort, and specialized and generic quicksort. |
| [`2019/October/binary_tree.hs`](2019/October/binary_tree.hs) | 2019-10 | Haskell | Defines and traverses binary trees. | Implements size, height, equality, isomorphism, and preorder, inorder, postorder, and breadth-first traversals. |
| [`2019/December/generators.py`](2019/December/generators.py) | 2019-12 | Python | Generates Fibonacci sequences, root approximations, and prime numbers. | Uses `yield` to retain state, Newton's method for roots, and trial division for primes. |
| [`2019/December/high_order_functions.py`](2019/December/high_order_functions.py) | 2019-12 | Python | Calculates the product of the even numbers in a list. | Combines `filter` with `functools.reduce` and uses `1` as the initial accumulator. |
| [`2019/December/tree_class.py`](2019/December/tree_class.py) | 2019-12 | Python | Models a general tree and its preorder traversal. | `Tree` stores a root and children; `Pre` inherits from it and recursively concatenates the traversal of each child. |

### 2021

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2021/June/double_linked_list_c.c`](2021/June/double_linked_list_c.c) | 2021-06 | C | Implements ordered insertion into a doubly linked list. | Allocates nodes, traverses `next` links, adjusts `prev` and `next` according to position, and displays the list. |
| [`2021/June/matrix_multiply.c`](2021/June/matrix_multiply.c) | 2021-06 | C | Allocates, fills, and displays a dynamic `N x M` matrix. | Creates a vector of pointers, allocates each row, and assigns `mat[i][j] = i+j` before printing it. |
| [`2021/July/image_histrogram.cpp`](2021/July/image_histrogram.cpp) | 2021-07 | C++ | Calculates the intensity frequencies of an 8-bit image. | Reads the image into a matrix and uses each pixel value as the index of a vector containing 256 counters. |

### 2025

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2025/April/async_channels.cpp`](2025/April/async_channels.cpp) | 2025-04 | C++ | Demonstrates asynchronous value passing and calculates a factorial. | A `promise<int>` feeds a `future`; `std::async` waits for the value and returns the result through another `future`. |
| [`2025/May/modernIterations.cpp`](2025/May/modernIterations.cpp) | 2025-05 | C++ | Compares object iteration by value and by reference. | Adds prices by copying each car and modifies them by iterating with `auto&` over the original objects. |
| [`2025/May/selectionsort.cpp`](2025/May/selectionsort.cpp) | 2025-05 | C++ | Sorts a vector using selection sort. | Finds the minimum value in each suffix, swaps the elements, and displays the result. |
| [`2025/June/placing_towers.cpp`](2025/June/placing_towers.cpp) | 2025-06 | C++ | Enumerates tower configurations that do not share rows or columns. | Represents columns with indices and rows with values, then filters assignments that repeat a row. |
| [`2025/June/placing_towers_v2.cpp`](2025/June/placing_towers_v2.cpp) | 2025-06 | C++ | Applies pruning to the tower placement problem. | Checks previously used rows before descending and builds configurations through backtracking. |
| [`2025/November/hospital_granollers_multithreading.cpp`](2025/November/hospital_granollers_multithreading.cpp) | 2025-11 | C++ | Simulates hospital rooms attending to patients in parallel. | Creates one thread and one `Room` per room, using random waits, an atomic counter, and a mutex to coordinate output. |

### 2026

| File | Date | Language | What it does | How it works |
| --- | --- | --- | --- | --- |
| [`2026/April/inheritance_leaks.cpp`](2026/April/inheritance_leaks.cpp) | 2026-04 | C++ | Demonstrates polymorphism and destruction through a base class. | Defines an abstract interface, creates a `Son` through `Parent*`, dispatches `printName` virtually, and deletes the object through the base pointer. |
| [`2026/May/cond_variable.cpp`](2026/May/cond_variable.cpp) | 2026-05 | C++ | Coordinates a producer and a consumer. | Protects a queue with a `mutex`; the producer inserts a countdown and notifies the consumer through a `condition_variable`. |

## Running the Examples

Each example can be compiled or loaded from its directory according to the language shown above.

```powershell
# C++
g++ .\2025\May\selectionsort.cpp -std=c++11 -o selectionsort.exe
.\selectionsort.exe

# C
gcc .\2021\June\matrix_multiply.c -o matrix_multiply.exe
.\matrix_multiply.exe

# Haskell
ghci .\2019\May\sorting_algorithms.hs

# Prolog
swipl -s .\2018\December\nqueens.pl

# Python
python .\2019\December\generators.py

# Organismos project (2014)
make
```
