/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:08 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:16:52 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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
 * 
 * This constructor will be automatically called when some instance 
 * of the derived class is created by default way.
 * 
 * This behavior is optional and reflects a design choice; it is subject to modification.
 */
AForm::AForm() : _name("Def_Form"), _toSign(HIGHER_GRADE), _toExec(HIGHER_GRADE), _signed(false)
{
	std::cout << BKGRAY "[AForm] Default Constructor called" RESET << std::endl;
}

/**
 * Copy Constructor
 * @brief Initializes the private attributes with the values of the instance passed by reference.
 * 		  Displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied.
 * 
 * This constructor could be called by the constructor of a derived class.
 * 
 * This behavior is mandatory.
 */
AForm::AForm(const AForm &src) :_name(src._name), _toSign(src._toSign), _toExec(src._toExec),_signed(src._signed)
{
	std::cout << BKGRAY "[AForm] Copy constructor called to " << this->getName() + RESET << std::endl;
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
 * This copy could be called by the copy assingnment of a derived class.
 * 
 * This behavior is mandatory.
 */
AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
	    this->_signed = src.getStatus();
	std::cout << BKGRAY "[AForm] Copy assignment operator called to " << this->getName() + RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the AForm object, either by an explicit call (delete AForm) 
 * 		  in case of heap memory allocation
 *        or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * This destructor will be automatically called when some instance 
 * of the derived class is deleted
 * 
 * This behavior is standard and mandatory.
 */
AForm::~AForm() 
{
	std::cout << BKGRAY "[AForm] Destructor called to " << this->getName() + RESET << std::endl;
}

/** !SECTION 
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
AForm::AForm(std::string name, int const toSign, int const toExec) : _name(name), _toSign(toSign), _toExec(toExec), _signed(false)
{
    ckOutLimitGrade(toSign);
	ckOutLimitGrade(toExec);
	std::cout << BKGRAY "[AForm] Constructor called to " << this->getName() + RESET << std::endl;
}

/**
 * @brief Method that signs the form, changing the status to true.
 * @param unkwonBur a const reference to a Bureaucrat that will try to sign the form.
 * @exception Form::alreadySigned if the form status is already signed.
 * @exception Form::GradeTooLowException if the grade of the Bureaucrat is lower 
 * than the grade required to sign the form.
*/
void	AForm::beSigned(Bureaucrat const &unkwonBur)
{
	if (this->getStatus())
		throw (AForm::alreadySigned());
	else if (unkwonBur.getGrade() > this->getToSign())
		throw (AForm::GradeTooLowException()); //queria colocar o LowExcepiton do Bureaucrat, fazia mais sentido, mas o subject pediu assim
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
const char *AForm::alreadySigned::what() const throw()
{
	return (YELLOW "[AForm_Exception] already signed" RESET);
}
/**
 * @brief Overload of the what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message.
 * 		   should be used to when the form try to execute an unsigned form
 * @warning used by the method execute on the concrete devired class.
 * 
 * This behavior is mandatory.
 */
const char *AForm::notSigned::what() const throw()
{
	return (RED "[AForm_Exception] is not signed, and couldnt be executed" RESET);
}

/**
 * @brief Overload of the what() method from std::exception.
 * @return a const char pointer to a string that represents the exception message.
 * 		   should be used to when the grade passed as parameter is too high to be assigned to the form.
 * @warning used by the constructor of the Form class.
 * 
 * This behavior is mandatory.
*/
const char *AForm::GradeTooHighException::what() const throw()
{
	return (RED "[AForm_Exception] Grade too High" RESET);
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
const char *AForm::GradeTooLowException::what() const throw()
{
	return (RED "[AForm_Exception] Grade too Low" RESET);
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
std::string	AForm::getName() const
{
	return (this->_name);
}

/**
 * @return a copy from a int that 
 * represents the grade of the Bureaucrat required to sign the Form.
 */
int	AForm::getToSign() const
{
	return (this->_toSign);
}

/**
 * @return a copy from a int that 
 * represents the grade of the Bureaucrat required to execute the Form.
 */
int	AForm::getToExec() const
{
	return (this->_toExec);
}

/**
 * @return a copy from a bool that 
 * represents the status of the Form.
 */
bool	AForm::getStatus() const
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
std::ostream &operator<<(std::ostream& out, const AForm& obj)
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
 * NOTE - When an exception is thrown, the class std::exception is instantiated 
 * and the method what() is called.
 * NOTE to student - Was used an fall-through switch case to avoid code repetition.
 * 
 * This behavior is mandatory, and it is a utility function.
 */
void AForm::ckOutLimitGrade(int grade)
{
	//verifica apenas o caso de ultrapassar o menor grau (< 1)
	if(grade < HIGHER_GRADE)
		throw(AForm::GradeTooHighException());
		//verifica apenas o caso de ultrapassar o menor grau (> 150)
	if(grade > LOWER_GRADE)
		throw(AForm::GradeTooLowException());
}

/**
 * @brief Private method that signs the form, changing the status to true.
 * @warning used by the method beSigned.
 * 
 * This method is a utility function, not mandatory.
*/
void	AForm::signIt()
{
	this->_signed = true;
}

/**
 * @brief Verifies conditions to execute te Form, such as if the grade of the Bureaucrat 
 * is high enough to excute the Form and if the Form is signed
 * @param executor a const reference to a Bureaucrat that will try to execute the form.
 * @exception AForm::notSigned if the form status is false.
 * @exception AForm::GradeTooLowException if the grade of the Bureaucrat is lower 
 * than the grade required to execute the form.
 * 
 * @warning the grade logic is inverted, the higher the grade, the lower the value.
 * 		  	The grade is limited to a range between 1 and 150.
 * 
 * NOTE - When an exception is thrown, the class std::exception is instantiated 
 * and the method what() is called.
 * NOTE to student - Was used an fall-through switch case to avoid code repetition.
 * 
 * This behavior is mandatory, and it is a utility function.
 */
void AForm::ckBureaucraAndForm(Bureaucrat const &executor) const
{
	if (this->getStatus() == false)
		throw(AForm::notSigned());
	if (executor.getGrade() > this->getToExec())
		throw(AForm::GradeTooLowException());
}
/**!SECTION
*/
