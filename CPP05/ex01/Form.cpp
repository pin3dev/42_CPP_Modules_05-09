/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:08 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 10:21:10 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/
/**
 * Default Constructor
 * @brief Initializes the private attributes with default values.
 * 	      The default value for the _name is "Def_Form".
 * 		  The default value for the _toSign is the highest possible (1).
 * 		  The default value for the _toExec is the highest possible (1).
 * 		  The default value for the _signed is false.
 * 		  Displays a message to the standard output.
 * This behavior is optional and reflects a design choice; it is subject to modification.
 */
Form::Form() : _name("Def_Form"), _toSign(HIGHER_GRADE), _toExec(HIGHER_GRADE), _signed(false)
{
	std::cout << BKGRAY "[Form] Default Constructor called" RESET << std::endl;
}


/**
 * Copy Constructor
 * @brief Initializes the private attributes with the values of the instance passed by reference.
 * 		  Displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied.
 * 
 * This behavior is mandatory.
 */
Form::Form(const Form &src) :_name(src._name), _toSign(src._toSign), _toExec(src._toExec),_signed(src._signed)
{
	std::cout << BKGRAY "[Form] Copy constructor called to " << this->getName() + RESET << std::endl;
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
 * This behavior is mandatory.
 */
Form &Form::operator=(const Form &src)
{
    if (this != &src)
	    this->_signed = src.getStatus();
	std::cout << BKGRAY "[Form] Copy assignment operator called to " << this->getName() + RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the Form object, either by an explicit call (delete Form) 
 * 		  in case of heap memory allocation
 *        or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * This behavior is standard and mandatory.
 */
Form::~Form() 
{
	std::cout << BKGRAY "[Form] Destructor called to " << this->getName() + RESET << std::endl;
}

/**!SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/
/**
 * Constructor with parameters (Mandatory)
 * @brief Initializes the private attributes with the values of the parameters passed by reference.
 * @param name a const reference to a string that represents the name of the Form.
 * @param toSign an int that represents the grade of the Bureaucrat required to sign the Form.
 * @param toExec an int that represents the grade of the Bureaucrat required to execute the Form.
 * 				 Displays a message to the standard output.
 * 
 * @exception Bureaucrat::GradeTooLowException if the grade (toSign or toExec) too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade (toSign or toExec) too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 		  	The grade is limited to a range between 1 and 150.
 * 
 * This behavior is mandatory.
 */
Form::Form(std::string name, int const toSign, int const toExec) : _name(name), _toSign(toSign), _toExec(toExec), _signed(false)
{
    ckOutLimitGrade(toSign);
	ckOutLimitGrade(toExec);
	std::cout << BKGRAY "[Form] Constructor called to " << this->getName() + RESET << std::endl;
}

/**
 * @brief Method that signs the form, changing the status to true.
 * @param unkwonBur a const reference to a Bureaucrat that will try to sign the form.
 * @exception Form::alreadySigned if the form status is already signed.
 * @exception Form::GradeTooLowException if the grade of the Bureaucrat is lower than the grade required to sign the form.
*/
void	Form::beSigned(Bureaucrat const &unkwonBur)
{
	if (this->getStatus())
		throw (Form::alreadySigned());
	else if (unkwonBur.getGrade() > this->getToSign())
		throw (Form::GradeTooLowException()); //queria colocar o LowExcepiton do Bureaucrat, fazia mais sentido, mas o subject pediu assim
	else 
		signIt();
}

/** !SECTION
 * ****************************
 * SECTION - EXCEPTIONS
 * ****************************
*/
/**
 * @brief Overload of the what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message.
 * 		   should be used to when the form is already signed, in other words, the status is true.
 * @warning used by the method beSigned.
 * 
 * This behavior is mandatory.
 */
const char *Form::alreadySigned::what() const throw()
{
	return (YELLOW "[Form_Exception] Already Signed" RESET);
}

/**
 * @brief Overload of the what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message.
 * 		   should be used to when the grade passed as parameter is too high to be assigned to the form.
 * @warning used by the constructor of the Form class.
 * 
 * This behavior is mandatory.
*/
const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "[Form_Exception] Grade too High" RESET);
}

/**
 * @brief Overload of the what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message.
 * 		   should be used to when the grade passed as parameter is too low to be assigned to the form.
 * 		   or if the grade of the Bureaucrat is lower than the grade required to sign the form.
 * @warning used by the constructor of the Form class and by the method beSigned.
 * 
 * This behavior is mandatory.
*/
const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "[Form_Exception] Grade too Low" RESET);
}

/** !SECTION
 * ****************************
 * SECTION - GETTERS & SETTERS
 * ****************************
*/

/**
 * @return a copy from a string that 
 * represents the name of the Form.
 */
std::string	Form::getName() const
{
	return (this->_name);
}

/**
 * @return a copy from a int that 
 * represents the grade of the Bureaucrat required to sign the Form.
 */
int	Form::getToSign() const
{
	return (this->_toSign);
}

/**
 * @return a copy from a int that 
 * represents the grade of the Bureaucrat required to execute the Form.
 */
int	Form::getToExec( void ) const
{
	return (this->_toExec);
}

/**
 * @return a copy from a bool that 
 * represents the status of the Form.
 */
bool	Form::getStatus( void ) const
{
	return (this->_signed);
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
 * This function is mandatory and helps facilitate cleaner debugging tests
 */
std::ostream &operator<<(std::ostream& out, const Form& obj)
{
	std::string st = RED "NotSigned" RESET;
	if(obj.getStatus())
		st = GREEN "Signed" RESET;
	out << CYAN "--------FORM--------" << std::endl
		<< "> name: " RESET << obj.getName() << std::endl
		<< CYAN "> status: " RESET << st << std::endl
		<< CYAN "> gradeToSign: " RESET << obj.getToSign() << std::endl
		<< CYAN "> gradeToExecute: " RESET << obj.getToExec() << std::endl;
	return (out);
}

/**
 * @brief Verifies if the grade is within the limits and throws an exception if it is not.
 * @param grade an int that represents the grade to be checked.

 * @exception Bureaucrat::GradeTooLowException if the grade too high (higher than 150).
 * 			  Bureaucrat::GradeTooHighException if the grade too low (lower than 1).
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 		  	The grade is limited to a range between 1 and 150.
 * 
 * @note When an exception is thrown, the class std::exception is instantiated 
 * and the method what() is called.
 * @note to student - Was used an fall-through switch case to avoid code repetition.
 * 
 * This behavior is mandatory, and it is a utility function.
 */
void Form::ckOutLimitGrade(int grade)
{
	if(grade < HIGHER_GRADE) //checks if the grade is < 1
		throw(Form::GradeTooHighException());
	if(grade > LOWER_GRADE) //checks if the grade is > 150
		throw(Form::GradeTooLowException());
}
/**
 * @brief Private method that signs the form, changing the status to true.
 * @warning used by the method beSigned.
 * 
 * This method is a utility function, not mandatory.
*/
void	Form::signIt()
{
	this->_signed = true;
}
/*!SECTION
*/
