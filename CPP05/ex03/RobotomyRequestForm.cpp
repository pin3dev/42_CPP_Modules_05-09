/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:40 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 11:32:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private attributes with default values, 
 * 		  by calling the Constructor with paramters of base abstract class AForm
 * 	      The default value for the _name in AForm base class is "Def_Form_R".
 * 		  The default value for the _toSign in AForm base class is the value of MACRO TO_SIGN_R
 * 		  The default value for the _toExec in AForm base class is the value of MACRO TO_EXEC_R
 * 		  The default value for the _signed in AForm base class is false.
 * 		  The default value for the _target in this object is "Def_Robotomy"
 * 		  Displays a message to the standard output.
*/
RobotomyRequestForm::RobotomyRequestForm() : AForm("Def_Form_R", TO_SIGN_R, TO_EXEC_R), _target("Def_Robotomy")
{
	std::cout << BKGRAY "[Robotomy] Default Constructor called" RESET << std::endl;
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
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << BKGRAY "[Robotomy] Copy constructor called to " << this->getTarget() + RESET << std::endl;
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
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	std::cout << BKGRAY "[Robotomy] Copy assignment operator called to " << this->getTarget() + RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the RobotomyRequest object, either by an explicit call (delete RobotomyRequest) 
 * 		  in case of heap memory allocation or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * This destructor will automatically call the destructor of the base class AForm
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BKGRAY "[Robotomy] Destructor called to " << this->getTarget() + RESET << std::endl;
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
 * @param[in] target a string with the name of the target to be robotomized.
 * 
 * @note this constructor is simplify by the calling of AForm base class constructor
 * 		 and the assignment of _target through the initialization list
 */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Def_Form_R", TO_SIGN_R, TO_EXEC_R), _target(target)	
{
	std::cout << BKGRAY "[Robotomy] Constructor called to " << this->getTarget() + RESET << std::endl;
}

/**
 * @brief Execute the action of the form, in this case, robotomizes the target if the random number is even.
 * 		   displays a message to the standard output.
 * @param[out] executor a reference to the Bureaucrat that will try to execute the form.
 * @warning use the method ckBureaucraAndForm to check if the Bureaucrat can execute the form.
 * 
 * @note this method is a pure virtual method from the base class AForm and must be implemented
*/
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	ckBureaucraAndForm(executor);
	srand(time(0));
	if ((rand()) % 2 == 0)
		std::cout << GREEN "[Robotomy] " 
		<< this->getTarget() << " has been robotomized " RESET << std::endl;
	else
		std::cerr << RED "[Robotomy] " 
		<< this->getTarget() << " robotomy failed " RESET << std::endl;
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
std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& obj)
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
 * @return a string with the name of the target to be robotomized.
*/
std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}
/**!SECTION
*/