/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:43 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 11:31:49 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOOTOMYREQUESTFORM_HPP
#define ROBOOTOMYREQUESTFORM_HPP

#include "AForm.hpp" //to inherit from AForm class
#include <cstdlib> //to srand() and rand()
/**
 * Classe Definition
 * @class RobotomyRequestForm 
 * @brief This class is a derived class from AForm abstract class and represents a form to robotomize a person (_target)
 * @param _target a const string that represents the name of the person to be robotomized
 * 
 * @note These parameters are mandatory and must be passed to the constructor of the derived class
 * 
 * More details in class
*/
class RobotomyRequestForm : public AForm
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
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target); //Adicional member functions: Constructor w/ parameter
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		
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
std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& obj);

#endif