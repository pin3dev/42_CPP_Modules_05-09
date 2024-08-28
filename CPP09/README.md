# CPP09-Module `100/100`

## Table of Contents
- [Project Overview](#overview)
- [Mandatory Features](#features)
- [Project Compilation and Execution](#compilation-and-execution)
- [Tests](#Tests)

## Overview

The `cpp_module_09` project focuses on advanced use of the Standard Template Library (STL) to solve complex problems involving data processing and algorithmic manipulation. 
This module emphasizes the efficient use of STL containers, understanding different algorithmic approaches, and optimizing performance across various computational tasks. 
Through the exercises, the module highlights the practical applications of STL in managing real-world data scenarios, with a strong focus on performance and correctness.

## Features

### Exercise 00: Bitcoin Exchange
* Implementation of a program to evaluate Bitcoin values on specific dates using historical data.
* Utilization of STL containers to efficiently manage and query large datasets.
* Handling of `edge cases` such as missing dates and invalid input formats, demonstrating robust error handling within container-based operations.

### Exercise 01: Reverse Polish Notation
* Development of a calculator that processes mathematical expressions in `Reverse Polish Notation` (RPN).
* Application of STL containers to manage the operand stack and perform calculations in a non-standard notation format.
* Focus on error handling and ensuring accurate computation for a variety of expression inputs.

### Exercise 02: PmergeMe
* Creation of a program that sorts a sequence of integers using the `merge-insert` sort algorithm.
* Implementation of the `Ford-Johnson algorithm` across multiple STL containers to compare performance.
* Emphasis on optimizing the sorting process and analyzing the efficiency of different container implementations.
* Dedicated class for `log outputs` to effectively monitor and track the algorithm's execution.


## Compilation and Execution
Each exercise should be compiled separately by running the Makefile within the corresponding exercise folder.
```bash
# Within the ex00, ex01, or ex02 directories
make

# Execution of ex00:
./btc

# Execution of ex01:
./RPN

# Execution of ex02:
./PmergeMe
```

## Tests
To be implemented...  
