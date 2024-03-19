/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:45 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 11:32:56 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * @brief ASCII art for the ShrubberyCreationForm file
*/
const char *ShrubberyCreationForm::_pin3 =
"       %%%,%%%%%%%\n"
"       ,'%% \\-*%%%%%%%\n"
" ;%%%%%*%   _%%%%\"\n"
"  ,%%%       \\(_.*%%%%.\n"
"  % *%%, ,%%%%*(    '\n"
" %^     ,*%%% )\\|,%%*%,_\n"
"      *%    \\/ #).-\"*%%*\n"
"          _.) ,/ *%,\n"
"  _________/)#(_____________\n";

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private attributes with default values, 
 * 		  by calling the Constructor with paramters of base abstract class AForm
 * 	      The default value for the _name in AForm base class is "Def_Form_S".
 * 		  The default value for the _toSign in AForm base class is the value of MACRO TO_SIGN_S
 * 		  The default value for the _toExec in AForm base class is the value of MACRO TO_EXEC_S
 * 		  The default value for the _signed in AForm base class is false.
 * 		  The default value for the _target in this object is "Def_Shurbbery"
 * 		  Displays a message to the standard output.
*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Def_Form_S", TO_SIGN_S, TO_EXEC_S), _target("Def_Shurbbery")
{
	std::cout << BKGRAY "[Shrubbery] Default Constructor called" RESET << std::endl;
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
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << BKGRAY "[Shrubbery] Copy constructor called to " << this->getTarget() + RESET << std::endl;
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
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) 
{
	if (this != &src)
		this->_target = src.getTarget();
	std::cout << BKGRAY "[Shrubbery] Copy assignment operator called to " << this->getTarget() + RESET << std::endl;
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
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << BKGRAY "[Shrubbery] Destructor called to " << this->getTarget() + RESET << std::endl;
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
 * @param[in] target a string with the name of the target to create the shrubbery.
 * 
 * @note this constructor is simplify by the calling of AForm base class constructor
 * 		 and the assignment of _target through the initialization list
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Def_Form_S", TO_SIGN_S, TO_EXEC_S), _target(target)
{
	std::cout << BKGRAY "[Shrubbery] Constructor called to " << this->getTarget() + RESET << std::endl;
}

/**
 * @brief Execute the action of the form, in this case, create a file with the name of the target
 * 		  and the suffix "_shrubbery" and inserts the ASCII art of a tree inside the file.
 * 		   displays a message to the standard output.
 * @param[out] executor a reference to the Bureaucrat that will try to execute the form.
 * @warning use the method ckBureaucraAndForm to check if the Bureaucrat can execute the form.
 * 
 * @note this method is a pure virtual method from the base class AForm and must be implemented
*/
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	ckBureaucraAndForm(executor);
	std::string newfile = this->getTarget() + "_shrubbery";
	std::ofstream	file(newfile.c_str());
	if (!file.is_open())
	{
		std::cerr << RED "[Shrubbery] Error opening file " RESET << std::endl;
		return ;
	}
	file << _pin3 << std::endl;
	file.close();
	std::cout << GREEN "[Shrubbery] " 
	<< this->getName() << " form was executed, check " 
	<< this->getTarget() << "_shrubbery file" RESET << std::endl;
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
std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
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
 * @return a string with the name of the target to create the shrubbery.
*/
std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
/**!SECTION
*/