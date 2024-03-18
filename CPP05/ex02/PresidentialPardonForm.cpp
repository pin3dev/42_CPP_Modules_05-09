/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:52 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 11:32:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private attributes with default values, 
 * 		  by calling the Constructor with paramters of base abstract class AForm
 * 	      The default value for the _name in AForm base class is "Def_Form_P".
 * 		  The default value for the _toSign in AForm base class is the value of MACRO TO_SIGN_P
 * 		  The default value for the _toExec in AForm base class is the value of MACRO TO_EXEC_P
 * 		  The default value for the _signed in AForm base class is false.
 * 		  The default value for the _target in this object is "Def_Presidential"
 * 		  Displays a message to the standard output.
*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("Def_Form_P", TO_SIGN_P, TO_EXEC_P), _target("Def_Presidential")
{
	std::cout << BKGRAY "[Presidential] Default Constructor called" RESET << std::endl;
}
/**
 * Copy Constructor
 * @brief Initializes the private attributes with the values of the instance passed by reference.
 * 		  Displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied.
 * 
 * @note this constructor is simplify by the calling of AForm base class constructor
 * 			and the assignment of _target through the initialization list
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << BKGRAY "[Presidential] Copy constructor called to " << this->getTarget() + RESET << std::endl;
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
 * @note Because the atributes of AForm are const, the only atribute that can be modified by
 * this method is the _target
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) 
{
	if (this != &src)
		this->_target = src.getTarget();
	std::cout << BKGRAY "[Presidential] Copy assignment operator called to " << this->getTarget() + RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the PresidentialPardon object, either by an explicit call (delete PresidentialPardon) 
 * 		  in case of heap memory allocation or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * This destructor will automatically call the destructor of the base class AForm
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BKGRAY "[Presidential] Destructor called to " << this->getTarget() + RESET << std::endl;
}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * Constructor with parameters (Mandatory)
 * @brief Initializes the private attributes with default values, 
 * 		  by calling the Constructor with paramters of base abstract class AForm.
 * 		  Displays a message to the standard output.
 * @param[in] target a string with the name of the target to be pardoned.
 * 
 * @note this constructor is simplify by the calling of AForm base class constructor
 * 		 and the assignment of _target through the initialization list
 */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Def_Form_P", TO_SIGN_P, TO_EXEC_P), _target(target)
{
	std::cout << BKGRAY "[Presidential] Constructor called to " << this->getTarget() + RESET << std::endl;
}

/**
 * @brief Execute the action of the form, in this case, pardons the target.
 * @param[out] executor a reference to the Bureaucrat that will try to execute the form.
 * @warning use the method ckBureaucraAndForm to check if the Bureaucrat can execute the form.
 * 
 * @note this method is a pure virtual method from the base class AForm and must be implemented
*/
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
	ckBureaucraAndForm(executor);
	std::cout << GREEN "[Presidential] "
	<< this->getTarget() << " has been pardoned by Zaphod Beeblebrox " 
	<< RESET << std::endl;
}

/**
 * @brief Overload the << operator to print the form to the standard output.
 * @param[out] out a reference to the standard output.
 * @param[in] obj a reference to the form to be printed.
 * @return a reference to the standard output.
 * 
 * @note this method is a overrided method from the base class AForm
 * 		 and use the << operator from the base class to print the common attributes
 * 		 adding the target attribute from this class.
*/
std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& obj)
{
	out << static_cast<const AForm&>(obj);
	out << CYAN "> target: " RESET << obj.getTarget() << std::endl;

    return out;
}

/** !SECTION
 * ****************************
 * SECTION - GETTERS & SETTERS
 * ****************************
*/

/**
 * @return a string with the name of the target to be pardoned.
*/
std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
/**!SECTION
*/
