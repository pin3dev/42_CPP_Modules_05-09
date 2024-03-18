/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:06:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp" //to inherit from AForm class

/**
 * Classe Definition
 * @class PresidentialPardonForm 
 * @brief This class is a derived class from AForm abstract class and represents a form to pardon a person (_target)
 * @param _target a const string that represents the name of the person to be pardoned
 * 
 * @note These parameters are mandatory and must be passed to the constructor of the derived class
 * 
 * More details in class
*/
class PresidentialPardonForm : public AForm
{
	private :
		std::string		_target;
	public :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target); //Adicional member functions: Constructor w/ parameter
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		void	execute(Bureaucrat const &executor) const ;
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
std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& obj);

#endif