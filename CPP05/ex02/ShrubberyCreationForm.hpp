/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:48 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 11:32:09 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp" //to inherit from AForm class
#include <fstream> //to use std::ofstream

/**
 * Classe Definition
 * @class ShrubberyCreationForm 
 * @brief This class is a derived class from AForm abstract class and represents a form to plant a shrubbery in the target's home
 * @param _target a const string that represents the name of the person that will receive the shrubbery
 * @param _pin3 a const char* that represents the ASCII art for the ShrubberyCreationForm file
 * 
 * @note These parameters are mandatory and must be passed to the constructor of the derived class
 * 
 * More details in class
*/
class ShrubberyCreationForm : public AForm 
{
	private :
		std::string		_target;
		static const char * _pin3;
	public :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target); //Adicional member functions: Constructor w/ parameter
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
				
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		void	execute(Bureaucrat const &executor) const;
		/**
         * Getters
         * @brief For copying private members like _target
         * 
         * @note This functions are mandatory and help to mantenance the encapsulation of the class
        */
		std::string getTarget() const;
};

/** Utils Functions (mandatory)
* @brief Includes functions as required by the subject guidelines of 42
* @see subject_en.pdf for more information
*/
std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& obj);

#endif