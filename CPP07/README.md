# CPP07-Module `100/100`

## Table of Contents
- [Project Overview](#overview)
- [Mandatory Features](#features)
- [Project Compilation and Execution](#compilation-and-execution)
- [Tests](#Tests)

## Overview

Aqui está o parágrafo do Overview revisado:

## Overview

The `cpp_module_07` project uses C++ templates to deepen understanding of creating generic, type-safe code. 
It explores the practical application of template functions and classes, demonstrating how templates can be utilized to build flexible and reusable solutions in C++.
## Features

### Exercise 00: Start with a few functions
* Implementation of basic `function templates` for operations such as `swap`, `min`, and `max`.
* These templates are designed to work with any data type, demonstrating the versatility of templates in C++.
* Exploration of template-based comparisons and operations, ensuring that the functions can handle various types while maintaining type safety.

### Exercise 01: Iter
* Development of a function template `iter` that applies a given function to each element of an array.
* The `iter` function template is designed to be generic, working with any array type and any function that can be applied to the elements of the array.
* Emphasis on the flexibility and reusability of template functions when dealing with different data types and operations.

### Exercise 02: Array
* Creation of a `template class Array` that mimics the behavior of a basic array, but with additional safety and functionality.
* Implementation of dynamic memory management using `operator new[]` to allocate memory for the array elements.
* Development of features such as bounds checking, deep copying, and size management, ensuring that the template class is robust and behaves correctly under various conditions.

## Compilation and Execution
Each exercise should be compiled separately by running the Makefile within the corresponding exercise folder.
```bash
# Within the ex00, ex01, or ex02 directories
make

# Execution of ex00:
./whatever

# Execution of ex01:
./iter

# Execution of ex02:
./array
```

## Tests
To be implemented...  
