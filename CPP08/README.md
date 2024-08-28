# CPP08-Module `100/100`

## Table of Contents
- [Project Overview](#overview)
- [Mandatory and Bonus Features](#features)
- [Project Compilation and Execution](#compilation-and-execution)
- [Tests](#Tests)

## Overview

The `cpp_module_08` project leverages C++ templated containers, iterators, and algorithms to deepen understanding of the Standard Template Library (STL). 
These exercises demonstrate practical applications of STL containers, enhance the ability to manipulate data efficiently, and extend the functionality of existing data structures, emphasizing the power and flexibility of templates in C++.
## Features

### Exercise 00: Easy find
* Implementation of a `function template` that searches for an integer in a templated container.
* Exploration of container traversal and search operations using STL algorithms.
* Handling cases where the search element is not found, demonstrating exception handling in template functions.

### Exercise 01: Span
* Development of a `Span` class to store a range of integers and calculate the shortest and longest span between elements.
* Implementation of methods to efficiently manage and query the data, emphasizing the use of STL algorithms for performance.
* Extension of functionality to handle large datasets and input ranges using iterator-based input.

### Exercise 02: Mutated abomination
* Creation of a `MutantStack` class that extends `std::stack` by adding iterator support, making the stack iterable.
* Demonstration of how to adapt and extend existing STL containers to meet specific needs.
* Testing the `MutantStack` to ensure compatibility with other STL containers and verifying iterator functionality.

## Compilation and Execution
Each exercise should be compiled separately by running the Makefile within the corresponding exercise folder.
```bash
# Within the ex00, ex01, or ex02 directories
make

# Execution of ex00:
./easyfind

# Execution of ex01:
./span

# Execution of ex02:
./mutant
```

## Tests
To be implemented...  
