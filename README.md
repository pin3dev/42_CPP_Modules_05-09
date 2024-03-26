# CPP-Modules_05-09 `100/100`

## Table of Contents
- [Project Overview](#overview)
- [Modules Guidelines](#guidelines)
- [Mandatory Features](#features)
- [Execution](#execution)
- [To Study](#Links2Study)

## Overview
The `cpp_modules_05-09` projects revolves around mastering advanced C++ concepts such as:
- Exceptions (throw, try/catch)
- Literals values
- Regular Expressions Concept (Regex)
- Casting Operators (static_cast, dynamic_cast, const_cast, reinterpret_cast)
- Templates Functions 
- Templates Classes 
- Templates Values
- Standard Template Library (STL)
- Containers (stack, list, vector, map, deque...)
- Iterators  
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
- Until you reach the Module 08: `STL`, meaning no Containers (`vector` `list` `map` and so forth) and no Algorithms (anything that requires to include the `<algorithm>` header).
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
| Grade |Modules|Lang | Type| Links and Subjects |
|:---------:|-------|:---:|:---:|--------------------|
|⭐⭐|`CPP05` `CPP09` | 🇧🇷 | 📄 |[SOLID Conceitos](https://www.macoratti.net/11/05/pa_solid.htm)|  
|⭐⭐|`CPP05` `CPP09`| 🇧🇷 | 📄 |[SOLID](https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design-pt)|  
|⭐⭐|`CPP05` `CPP09` | 🇧🇷 | 📄 |[O que é SOLID](https://medium.com/desenvolvendo-com-paixao/o-que-%C3%A9-solid-o-guia-completo-para-voc%C3%AA-entender-os-5-princ%C3%ADpios-da-poo-2b937b3fc530)|  
|⭐⭐|`CPP05` `CPP09` | 🇧🇷 | 📄 |[OOP - Herança x Composição](https://www.macoratti.net/11/05/oop_cph1.htm)|  
|✅|`CPP05` `CPP09` | 🇺🇸 | 📄 |[Composition vs Inheritance](https://www.digitalocean.com/community/tutorials/composition-vs-inheritance)|  
|🤩|`CPP05` `CPP09` | 🇺🇸 | 📄 |[Composition in OOPS](https://www.educba.com/composition-in-oops/)|  
|🤩|`CPP06`         | 🇺🇸 | 📄 |[Casting Operators in C++](https://www.geeksforgeeks.org/casting-operators-in-cpp/)|  
|⭐⭐|`CPP06`       | 🇧🇷 | 📄 |[TIPOS DE LITERAIS EM C / C++](https://acervolima.com/tipos-de-literais-em-c-c-com-exemplos/)|  
|🤩|`CPP06`         | 🇺🇸 | 📄 |[Literals In C++](https://www.geeksforgeeks.org/cpp-literals/)|  
|🤩|`CPP06` `CPP09` | 🇺🇸 | 📄 |[Regex](https://www3.ntu.edu.sg/home/ehchua/programming/howto/Regexe.html)|  
|⭐|`CPP09`         | 🇺🇸 | 📄 |[Polish Notation](https://en.wikipedia.org/wiki/Polish_notation)|  
|⭐|`CPP09`         | 🇺🇸 | 📄 |[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)|  
|🤩|`CPP09`         | 🇺🇸 | 📹 |[Reverse Polish Notation](https://www.youtube.com/watch?v=qN8LPIcY6K4)|  
|✅|`CPP09`         | 🇺🇸 | 📹 |[Reverse Polish Notation Using Stacks](https://www.youtube.com/watch?v=QxHRM0EQHiQ)|  
|🤩|`CPP09`         | 🇺🇸 | 📹 |[Introduction to Reverse Polish Notation (RPN)](https://www.youtube.com/watch?v=HDwRlIc75w4)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📚 |[On the Average Case of MergeInsertion](https://arxiv.org/pdf/1905.09656.pdf)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📄 |[Python: Sort unsorted numbers using Merge-insertion sort](https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php)|  

> ✅ OK | ⭐ Good | ⭐⭐ VeryGood | 🤩 Amazing | 🔖 Bookmarked2Read  
> 📄 Blog | 💭 Chat | 📹 Video | 📚 Book_&_ScientificPapers

