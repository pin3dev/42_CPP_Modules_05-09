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
- Reverse Polish Notation & Polish Notation
- Merge-Insertion Sort Algorithm (The Ford-Johnson Sorting Algorithm)
  
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

### [Module 05](https://github.com/pin3dev/42_CPP_Modules_05-09/tree/main/CPP05): Exception Handling, Custom Exceptions, Error Propagation
### [Module 06](https://github.com/pin3dev/42_CPP_Modules_05-09/tree/main/CPP06): Casting Operators, Type Conversion, Literals Values
### [Module 07](https://github.com/pin3dev/42_CPP_Modules_05-09/tree/main/CPP07): Template Functions, Templates Classes, Iterators
### [Module 08](https://github.com/pin3dev/42_CPP_Modules_05-09/tree/main/CPP08): STL, Containers, Algorithmic Efficiency
### [Module 09](https://github.com/pin3dev/42_CPP_Modules_05-09/tree/main/CPP09): RPN, Merge-Insertion Sort Algorithm, Advanced STL, Performance Optimization

## Execution
Each exercise's compilation is done separately by running the Makefile within the exercise's folder.  
```bash
#in the ex00, ex01, ex02 or ex03 directory
make

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
|🤩|`CPP08` `CPP09` | 🇺🇸 | 📹 |[C++ Standard Template Library  STL](https://www.youtube.com/watch?v=BKBXM7ypQG0&list=PL1w8k37X_6L9NXrP1D31hDTKcdAPIL0cG&index=1)  
|⭐|`CPP09`         | 🇺🇸 | 📄 |[Polish Notation](https://en.wikipedia.org/wiki/Polish_notation)|  
|⭐|`CPP09`         | 🇺🇸 | 📄 |[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)|  
|🤩|`CPP09`         | 🇺🇸 | 📹 |[Reverse Polish Notation](https://www.youtube.com/watch?v=qN8LPIcY6K4)|  
|✅|`CPP09`         | 🇺🇸 | 📹 |[Reverse Polish Notation Using Stacks](https://www.youtube.com/watch?v=QxHRM0EQHiQ)|  
|🤩|`CPP09`         | 🇺🇸 | 📹 |[Introduction to Reverse Polish Notation (RPN)](https://www.youtube.com/watch?v=HDwRlIc75w4)|  
|🤩|`CPP09`         | 🇺🇸 | 📹 |[Binary Search animated](https://www.youtube.com/watch?v=DRsJ8sA9xzc)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📚 |[On the Average Case of MergeInsertion](https://arxiv.org/pdf/1905.09656.pdf)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📄 |[Python: Sort unsorted numbers using Merge-insertion sort](https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📄 |[Ford-Johnson merge-insertion sort](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)|  
|⭐⭐|`CPP09`       | 🇺🇸 | 📄 |[Merge Sort vs. Insertion Sort](https://www.geeksforgeeks.org/merge-sort-vs-insertion-sort/)|  



> ✅ OK | ⭐ Good | ⭐⭐ VeryGood | 🤩 Amazing | 🔖 Bookmarked2Read  
> 📄 Blog | 💭 Chat | 📹 Video | 📚 Book_&_ScientificPapers

