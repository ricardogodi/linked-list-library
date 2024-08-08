# Linked List Library in C

## Overview
This project implements a linked list library in C, focusing on efficient memory management and runtime optimization. It ensures safe memory operations to prevent leaks and provides a robust handling of dynamic data structures with recursive and iterative methods for manipulating linked lists.

## Files Included
- `list.h`: Header file with declarations for list functions and structures.
- `llist.c`: Implementation of linked list functions including list creation, deletion, and manipulation.
- `tests_pt1.c`: Test suite for basic list functionality; compile to `test1` executable.
- `tests_pt2.c`: Additional test suite focusing on advanced list operations; compile to `test2` executable.
- `ll_tst.c`: Test suite for performance and stress testing; compile to `test3` executable.

## Functions Implemented
- `lst_create()`: Creates a new, empty list.
- `lst_free()`: Frees all nodes in the list and the list itself.
- `lst_print()`: Prints all elements in the list.
- `lst_are_equal()`: Checks if two lists contain the same elements in the same order.
- `lst_print_rev()`: Prints all elements in reverse order using recursion.
- `lst_push_front()`: Inserts an element at the beginning of the list.
- `lst_push_back()`: Inserts an element at the end of the list.
- `lst_pop_front()`: Removes and returns the first element of the list.
- `lst_pop_back()`: Removes and returns the last element of the list.
- `lst_length()`: Returns the number of elements in the list.
- `lst_is_empty()`: Checks if the list is empty.
- `lst_count()`: Counts occurrences of a specific value in the list.
- `lst_remove_first()`: Removes the first occurrence of a specific value.
- `lst_remove_all_slow()`: Removes all occurrences of a specific value slowly.
- `lst_remove_all_fast()`: Removes all occurrences of a specific value efficiently.
- `lst_insert_sorted()`: Inserts a value in a sorted list while maintaining order.
- `lst_merge_sorted()`: Merges two sorted lists into one.
- `lst_clone()`: Creates a deep copy of a list.
- `lst_from_array()`: Creates a list from an array.
- `lst_to_array()`: Converts a list to an array.
- `lst_prefix()`: Removes and returns the first k elements of a list.
- `lst_filter_leq()`: Removes and returns all elements less than or equal to a cutoff value.
- `lst_concat()`: Concatenates two lists into one.

## Contributions
I developed all the functions within `llist.c`.

## Compilation and Running
Ensure GCC is installed and use the provided Makefile to compile the test suites:
```bash
make all   # Compiles all test suites
```

Each test suite can be run to validate different aspects of the linked list library:
```bash
./test1  # Runs basic functionality tests
./test2  # Runs advanced functionality tests
./test3  # Runs performance tests
```
