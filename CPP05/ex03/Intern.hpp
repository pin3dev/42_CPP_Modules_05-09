/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:43:12 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 12:10:14 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream> //to std::cout and std::endl
#include "ShrubberyCreationForm.hpp" //to create new Shrubbery Form
#include "RobotomyRequestForm.hpp" //to create new Robotomy Form
#include "PresidentialPardonForm.hpp" //to create new Presidential Form
#include "mColors.hpp" //to define the colors MACROS and ENUM


/**
 * @class Intern
 * @brief This class serves to the only propose of creat Forms through the public method
 * 
 * More details in class
*/
class Intern
{
	private:
		/**
         * @typedef PtrToMethods
         * @brief Defines an alias for an pointer to any methods/function 
		 * 		  with the signature:
		 * 		 AForm *AnyNameFunction(const std::string &var) 
         * 
         * Simplifies subsequent references to this data type.
         */
		typedef AForm* (Intern::*PtrToMethods)(const std::string&);

		/**
		 * @brief static array of PtrToMethods pointers with size 3
		 * @warning static data has to be initializated in .cpp by default
		 * @note static data is always inerent to class, so this couldnt be 
		 * 		 considerate as an object atribute
		*/
		static PtrToMethods _forms[3];
		/**
		 * @brief static array of const string with size 3
		 * @warning static data has to be initializated in .cpp by default
		 * @note static data is always inerent to class, so this couldnt be 
		 * 		 considerate as an object atribute
		*/
		static const std::string	_types[3];

        /**
         * Utils Members (optional)
         * @brief Functions help to implement the logic of the class
        */
		AForm* makeS(const std::string& target);
		AForm* makeR(const std::string& target);
		AForm* makeP(const std::string& target);
	public:
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		AForm	*makeForm(std::string type, std::string target);
};

#endif