# CPP-Module-05 `100/100`
This module is designed to help you understand Try/Catch and Exceptions in CPP.

<!--
<p align="center">
  <img src="https://github.com/pin3dev/42_Push_Swap/blob/d3573e4aa7ad62d9e6d1ee2acf2e6da3dbe860b1/%3CTutorial%3EPushSwap/pushswap_vs.gif" width="600" height="375" />
</p>

<p align="center">
  <a href="https://github.com/pin3dev/42_Push_Swap/wiki">🎰---TUTORIAL---🎰</a>
</p> --->


## Table of Contents
- [Project Overview](#overview)
- [Mandatory Features](#features)
- [Project Compilation and Execution](#compilation-and-execution)
- [Tests -  Usage Examples](#usage-examples)

## Overview
The `cpp_module_05` project revolves around the concepts of try/catch in C++.

## Features

### Exercise 00: Exception Handling  
* Utilizing `try/catch` blocks for effective error management.  
* Creating custom exception classes like `GradeTooHighException` and `GradeTooLowException` to handle invalid inputs.  
* Ensuring robust error recovery with `try/catch` blocks.

### Exercise 01: Form Management  
* Demonstrating composition by introducing the `Form` class with methods like `beSigned` and `signForm`. 
* Handling thrown and caught exceptions to ensure seamless composition.

### Exercise 02: Form Processing  
* Implementing abstraction through a pure abstract method `execute`.
* Creating concrete classes such as `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`.
* Maintaining encapsulation and adherence to abstract base class by keeping attributes private and constant.

### Exercise 03: Intern Tasks  
* Employing composition with an `Intern` class to aid in form tasks.
* Demonstrating polymorphism by utilizing an array of pointers to internal methods and the `makeForm()` function for execution.  

## Compilation and Execution
Each exercise's compilation is done separately by running the Makefile within the exercise's folder.  
```bash
#in the ex00, ex01, ex02 or ex03 directory
$>make

#Execution ex00:
./Bureaucrat

#Execution ex01:
./Form

#Execution ex02:
./Exec

#Execution ex03:
./Intern
```

## Usage Examples
to be implemented...  
<!--
```c
//Changes to be applied to the main function of the exercises 

//Execution ex00:
    //to test Default Constructors
int main()
{
  Animal;
  Dog;
  Cat;
  WrongAnimal;
  WrongCat;

  (void)Animal;
  (void)Dog;
  (void)Cat;
  (void)WrongAnimal;
  (void)WrongCat;

}
    //to test Polymorphism
int main()
{
  Animal *anyAnimal;
  anyAnimal = new Dog();
  std::cout << anyAnimal ->getType() << " ";
  anyAnimal ->makeSound();

  Animal *anotherAnimal;
  anyAnimal = new Cat();
  std::cout << anotherAnimal ->getType() << " ";
  anotherAnimal ->makeSound();

  delete anyAnimal;
  delete anotherAnimal;
}

    //to test wrong classes
int main()
{
  Animal *anyAnimal;
  anyAnimal = new Dog;
  std::cout << anyAnimal ->getType() << " ";
  anyAnimal ->makeSound();

  Animal *anotherAnimal;
  anyAnimal = new Cat;
  std::cout << anotherAnimal ->getType() << " ";
  anotherAnimal ->makeSound();

  delete anyAnimal;
  delete anotherAnimal;
}

//Execution ex01:


//Execution ex02:

//Execution ex03:

```
--->
