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
* Mastering the use of `try/catch` blocks for handling errors effectively.  
* Creating custom exceptions like `GradeTooHighException` and `GradeTooLowException` to manage invalid inputs.  
* Ensuring smooth recovery from unexpected situations.  

### Exercise 01: Form Management  
* Designing a `Form` class for bureaucrats to handle and sign forms.  
* Ensuring proper handling of form signing and execution requirements.  
* Testing form functionality to ensure it works as expected.  

### Exercise 02: Form Processing  
* Creating specialized forms such as `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`.  
* Implementing methods to execute forms based on bureaucrat authority and form status.  
* Testing form execution scenarios for accuracy and reliability.  

### Exercise 03: Intern Tasks  
* Developing an `Intern` class to assist bureaucrats in form tasks.  
* Implementing a `makeForm()` function to create forms based on given parameters.  
* Testing intern functionality to ensure efficient form creation and error handling.   

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
