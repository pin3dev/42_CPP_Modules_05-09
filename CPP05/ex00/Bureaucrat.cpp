/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:22 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 10:19:43 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private attributes with default values.
 *        The default value for the _grade is the lowest possible (150).
 * 		  The default value for the _name is "Def_Bureaucrat".
 * 		  Displays a message to the standard output.
 * 
 * @note This behavior is optional and reflects a design choice; it is subject to modification.
 */
Bureaucrat::Bureaucrat() : _name("Def_Bureaucrat"), _grade(LOWER_GRADE)
{
	std::cout << BKGRAY "[Bureaucrat] Default Constructor called" RESET << std::endl;
}
/**
 * Copy Constructor
 * @brief Initializes the private attributes with the values of the instance passed by reference.
 * 		  Displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied.
 * 
 * @note This behavior is mandatory.
 */
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << BKGRAY "[Bureaucrat] Copy constructor called to " << this->getName() + RESET << std::endl;
	//*this = src;
}
/**
 * Copy Assignment operator / OVERLOAD OPERATOR
 * @brief assigns the values of the private attributes of the instance passed by
 * 		  reference to the instance on the left side of the operator.
 * 		  displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied.
 * @return a reference to the instance on the left side of the operator.
 * 
 * @note This behavior is mandatory.
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	std::cout << BKGRAY "[Bureaucrat] Copy assignment operator called to " << this->getName() + RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the Bureaucrat object, either by an explicit call (delete Bureaucrat) in case of heap memory allocation
 *        or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * @note This behavior is standard and mandatory.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << BKGRAY "[Bureaucrat] Destructor called to " << this->getName() + RESET << std::endl;
}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * Constructor with parameters (Mandatory)
 * @brief Initializes the private attributes with the values of the parameters passed by reference.
 * @param name a const reference to a string that represents the name of the Bureaucrat.
 * @param grade an int that represents the grade of the Bureaucrat.
 * @exception Bureaucrat::GradeTooLowException if the grade too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 		  	The grade is limited to a range between 1 and 150.
 * 
 * @note This behavior is mandatory.
 */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	ckOutLimitGrade(checkAll, grade);
	std::cout << BKGRAY "[Bureaucrat] Constructor called to " << this->getName() + RESET << std::endl;
	this->_grade = grade;
}

/**
 * @brief Increments the grade of the Bureaucrat by 1.
 * @exception Bureaucrat::GradeTooLowException if the grade too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value,
 * 			so the increment operation is a decrement in the value.
 * 
 * @note This behavior is mandatory.
 */
void	Bureaucrat::increment()
{
	std::cout << YELLOW "[Bureaucrat] trying increment " 
	<< this->getName() << "..." RESET << std::endl;

	//Implementar depois com calma; try-catch aqui para mensagem personalizada
	ckOutLimitGrade(checkHigher, (this->getGrade() - 1));
	this->_grade--;

	std::cout << GREEN "[Bureaucrat] " 
	<< this->getName() << " incremented" RESET << std::endl;
}

/**
 * @brief Decrements the grade of the Bureaucrat by 1.
 * @exception Bureaucrat::GradeTooLowException if the grade too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value,
 * 			so the decrement operation is an increment in the value.
 * 
 * @note This behavior is mandatory.
 */
void	Bureaucrat::decrement()
{
	std::cout << YELLOW "[Bureaucrat] trying decrement " 
	<< this->getName() << "..." RESET << std::endl;
	
	//Implementar depois com calma; try-catch aqui para mensagem personalizada
	ckOutLimitGrade(checkLower, (this->getGrade() + 1));
	this->_grade++;
	
	std::cout << GREEN "[Bureaucrat] " 
	<< this->getName() << " decremented" RESET << std::endl;
}

/** !SECTION
 * ****************************
 * SECTION - EXCEPTIONS
 * ****************************
*/

/* Lança mensagem personalizada que quando capturada desvia a execução do programa */
/* shows a custom mensage when catch an throw exception */

//Exceção para this->_grade maior do que o limite permitido (< 1)

/**
 * @brief overrided what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message
 * 		   should be used when the grade is too low ('lower' than 150).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "[Bureaucrat_Exception] Grade Is Too Low" RESET);
}
/**
 * @brief overrided what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message
 * 		   should be used when the grade is too high ('higher' than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 
 * @note The throw() is a specification that indicates that the function does not throw exceptions.
 */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "[Bureaucrat_Exception] Grade Is Too High" RESET);
}


/** !SECTION
 * ****************************
 * SECTION - GETTERS & SETTERS
 * ****************************
*/

/**
 * @return a copy from a const string that 
 * represents the name of the Bureaucrat.
 */
const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

/**
 * @return a copy from a integer that  
 * represents the grade of the Bureaucrat.
 */
int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/** !SECTION
 * ****************
 * SECTION - UTILS 
 * ****************
*/


/**
 * operator<< OVERLOAD OPERATOR GENERAL
 * @brief displays the content of the Bureaucrat object in the standard output.
 * @param[out] out the reference to the output stream.
 * @param[out] obj an const reference to the Bureaucrat object to be printed.
 * @return a reference to the output stream.
 * 
 * @note This function is mandatory and helps facilitate cleaner debugging tests
 */
std::ostream &operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << CYAN "-----BUREAUCRAT-----" << std::endl
		<< "> name: " RESET << obj.getName() << std::endl
		<< CYAN "> grade: " RESET << obj.getGrade() << std::endl;
	return (out);
}

/**
 * @brief Verifies if the grade is within the limits and throws an exception if it is not.
 * @param type an enum that represents the type of check to be performed.
 * @param grade an int that represents the grade to be checked.

 * @exception Bureaucrat::GradeTooLowException if the grade too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 		  	The grade is limited to a range between 1 and 150.
 * 
 * @note When an exception is thrown, the class std::exception is instantiated 
 * and the method what() is called.
 * @note  Was used an fall-through switch case to avoid code repetition.
 * 
 * @note This behavior is mandatory, and it is a utility function.
 */
void Bureaucrat::ckOutLimitGrade(checkGrade type, int grade)
{
	switch (type)
	{
		case checkHigher:
			if(grade < HIGHER_GRADE)
				throw(Bureaucrat::GradeTooHighException());
			break;
		case checkAll:
			if(grade < HIGHER_GRADE)
				throw(Bureaucrat::GradeTooHighException());
		case checkLower:
			if(grade > LOWER_GRADE)
				throw(Bureaucrat::GradeTooLowException());
			break;
		default:
			break;
	}
}

/**!SECTION
 * 
*/
