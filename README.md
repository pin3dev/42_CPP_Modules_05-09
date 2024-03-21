# CPP-Modules_05-09 `100/100`



## Table of Contents
- [Project Overview](#overview)
- [Modules Guidelines](#guidelines)
- [Mandatory Features](#features)
- [Execution](#execution)
- [To Study](#Links2Study)

## Overview
The `cpp_modules_05-09` projects revolves around mastering advanced C++ concepts such as:
- Exceptions
- Templates Functions 
- Templates Classes 
- Templates Values
- Composition vs Inheritance  
  
## Guidelines

### Compilation:

- Compile your code using `c++` with flags `-Wall` `-Wextra` `-Werror` `-std=c++98`
- Exercise directories: `ex00`, `ex01`, ..., `exn`
- Separate `Makefile` within each exercise directory.
- Use `UpperCamelCase` for class names.

### Forbidden:

- Functions: `*printf()`, `*alloc()`, `free()`
- External libraries like `C++11`, `Boost`
- Using `namespace <ns_name>` and `friend` keywords.
- `STL`, meaning no Containers (`vector/list/map/and` so forth) and no Algorithms (anything that requires to include the `<algorithm>` header) until Module 08-09.
- `Memory leaks` when using `new`.
- Function `implementations in header` files (except for function templates).

### Allowed:

- Use `standard library` extensively.
- `Additional files` allowed if necessary.

### Rule:
Follow the `Orthodox Canonical Form` for classes `Modules 02-09`, which must implement four essential member functions:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
- Split class code into two files: Header file `.hpp/.h` for class definition, and Source file `.cpp` for implementation

## Features

### Module 05: Exception Handling and Object-Oriented Design

- Implementing `try/catch` blocks for error handling in C++.
- Custom exception classes creation for handling specific errors.
- Ensuring robust error recovery with `try/catch` blocks.
- Designing classes and methods following principles of composition.
- Utilizing encapsulation and visibility concepts (public, private).
- Employing abstraction through pure abstract methods.
- Creating concrete classes with specific functionalities.
- Maintaining encapsulation and adherence to abstract base class.
- Demonstrating polymorphism through the use of pointers to internal methods.
- Applying object-oriented design principles in C++ programming.

## Execution
Each exercise's compilation is done separately by running the Makefile within the exercise's folder.  
```bash
#in the ex00, ex01, ex02 or ex03 directory
$>make

```
## Links2Study
`CPP05` `CPP09` 🇧🇷📄 [SOLID Conceitos](https://www.macoratti.net/11/05/pa_solid.htm)  
`CPP05` `CPP09` 🇧🇷📄 [OOP - Herança x Composição](https://www.macoratti.net/11/05/oop_cph1.htm)  
`CPP05` `CPP09` 🇺🇸📄 [Composition vs Inheritance](https://www.digitalocean.com/community/tutorials/composition-vs-inheritance)  
`CPP05` `CPP09` 🇺🇸📄 [Composition in OOPS](https://www.educba.com/composition-in-oops/)  
