/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:43:09 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 12:01:31 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**
 * @brief Static array of strings with possibles types of forms
*/
const std::string Intern::_types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
/**
 * @brief typedef for a pointer to a method that receives a string and returns a pointer to a AForm
 * @note this is a pointer to any method of Intern class that has the same signature
 *       but was filled with the methods makeS, makeR and makeP
*/
Intern::PtrToMethods Intern::_forms[3] = {&Intern::makeS,&Intern::makeR,&Intern::makeP};

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the Intern instance
 * 		  Displays a message to the standard output.
*/
Intern::Intern()
{
	std::cout << BKGRAY "[Intern] Default Constructor called" RESET << std::endl;
}

/**
 * Copy Constructor
 * @deprecated Initializes the Intern instance, exatcly as the default constructor
 * 		  Displays a message to the standard output.
 * @param[out] src an const reference to the instance to be copied, that will be ignored.

 * @note The Intern has no attributes, so the copy constructor just serve to complete the canonical form
 */
Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << BKGRAY "[Intern] Copy constructor called" RESET << std::endl;
}

/**
 * Copy Assignment operator / OVERLOAD OPERATOR
 * @deprecated do nothing, just return the current instance
 * @param[out] src an const reference to the instance to be copied, that will be ignored.
 * @return a reference to the instance on the left side of the operator.
 * 
 * @note The Intern has no attributes, so the copy assignment operator just serve to complete the canonical form
 */
Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << BKGRAY "[Intern] Copy assignment operator called to Intern" RESET << std::endl;
	return (*this);
}

/**
 * Destructor
 * @brief Deletes the Intern object, either by an explicit call (delete Intern) 
 * 		  in case of heap memory allocation
 *        or automatically in case of stack memory allocation
 * 		  display a message to the standard output.
 * 
 * @note This behavior is standard and mandatory.
 */
Intern::~Intern()
{
	std::cout << BKGRAY "[Intern] Destructor called" RESET << std::endl;
}

/** !SECTION 
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * @brief creates a form by type and target provided by parameters 
 * @param[out] type a string that represents the type of the form to be created
 * @param[out] target a string that represents the target of the form to be created
 * @return a pointer to the new form created
 * 
 * @warning this function uses a const array of strings with types of forms 
 * 			and compares with the type provided by parameter
 * @note this function dont create a form, but call a method to do it
 * 			according to the type provided by parameter, after the comparison
*/
AForm	*Intern::makeForm(std::string type, std::string target)
{
	std::cout << YELLOW "> [Intern] is trying to create a form [" << type <<  "]..." RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
        if (this->_types[i] == type)
		{
			std::cout << GREEN "> [Intern] create a form [" << type <<  "]" RESET << std::endl;
            return ((this->*_forms[i])(target));
		}
    }
	std::cout << RED "[Intern] Couldnt create any form, type [" << type << "] doesnt exist" RESET << std::endl;
	return NULL;
}

/** !SECTION 
 * ****************
 * SECTION - UTILS 
 * ****************
*/

/**
 * @brief creates a ShrubberyCreationForm by target provided by parameter 
 * @param[out] target a string that represents the target of the form to be created
 * @return a pointer to the new ShrubberyCreationForm object created
 * 
 * @note this function is called by makeForm to create a ShrubberyCreationForm
*/
AForm* Intern::makeS(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

/**
 * @brief creates a RobotomyRequestForm by target provided by parameter 
 * @param[out] target a string that represents the target of the form to be created
 * @return a pointer to the new RobotomyRequestForm object created
 * 
 * @note this function is called by makeForm to create a RobotomyRequestForm
*/
AForm* Intern::makeR(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

/**
 * @brief creates a PresidentialPardonForm by target provided by parameter 
 * @param[out] target a string that represents the target of the form to be created
 * @return a pointer to the new PresidentialPardonForm object created
 * 
 * @note this function is called by makeForm to create a PresidentialPardonForm
*/
AForm* Intern::makeP(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

/**!SECTION
*/

//DEPRECATED & INCOMPLETE
/* AForm	*Intern::makeForm(std::string type, std::string target)
{
	AForm *form = NULL;
	int i = getType(type, this->_types);
	std::cout << YELLOW "> [Intern] is trying to create a form [" << type <<  "]..." RESET << std::endl;
	switch (i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << RED "[Intern] Couldnt create any form, type [" << type << "] doesnt exist" RESET << std::endl;
			return NULL;
	}
	std::cout << GREEN "> [Intern] create a form [" << type <<  "] w/ name: " << form->getName() + RESET << std::endl;
	return form;
} */