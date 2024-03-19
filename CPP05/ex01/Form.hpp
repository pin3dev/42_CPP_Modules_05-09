/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:12 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 09:34:26 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" //to Bureaucrat class
#include "mColors.hpp" //to define the colors MACROS and ENUM


class Bureaucrat; //Forward declaration because of the circular dependency


/**
 * Classe Definition
 * @class Form
 * @brief This class is a representation of Form that has a name, a grade to sign and a grade to execute.
 * @param _name a const string that represents the name of the Form
 * @param _toSign an integer that represents the grade minimum to an Bureaucrat sign the form
 * @param _toExec an integer that represents the grade minimum to an Bureaucrat execute the form
 * 		 (1 is the highest grade and 150 is the lowest)
 * @throws exceptions if the grade is higher than 1 or lower than 150
 * 
 * More details in class
*/
class Form 
{
	private :
		std::string const   _name;
		int const           _toSign;
		int const           _toExec;
		bool                _signed;
        
        /**
         * Utils Members (optional)
         * @brief Functions help to implement the logic of the class
        */
		void ckOutLimitGrade(int grade);
        void	signIt();
	public :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */		
		Form();
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        Form(std::string name, int const toSign, int const toExec);
		void beSigned(Bureaucrat const &grade);
		
		/**
         * Getters
         * @brief For copying private members 
         * like _name, _toSign, _toExec and _signed
         * 
         * This functions are mandatory 
		 * and help to mantenance the encapsulation of the class
        */		
        std::string	getName() const;
		int			getToSign() const;
		int			getToExec() const;
		bool		getStatus() const ;
		
        
	/**
	 * Form Exceptions Classes
	 * 
	 * @note Includes exception classes inherited from std::exception
	 * 		and overload of what() method
	 * @note The exception classes are declared internally to the Form class
	 * 		and are used only by the Form class, so they are private.
	 * @note Every class inherits from std::exception must implement the what() method overrided.
	 * @note The what() method must return a const char pointer to a string that represents the exception message.
	 * @note The const throw() at end of what() method indicates that the function does not throw exceptions.
	 * @note The virtual flag indicates that the function can be overrided by a derived class, and must stay in the derived class.
	*/

	/**
	 * @class GradeTooHighException
	 * @brief classes that are used to throw exceptions 
	 * 		 when the grade is higher than 1 
	*/
	class GradeTooHighException : public std::exception
    {
		public :
			/**
			 * @brief overrided what() method from std::exception.
			*/
			virtual const char* what() const throw();
	};
	/**
	 * @class GradeTooLowException
	 * @brief classes that are used to throw exceptions 
	 * 		 when the grade is lower than 150
	*/
	class GradeTooLowException : public std::exception
    {
		public :
			/**
			 * @brief overrided what() method from std::exception.
			*/
			virtual const char* what() const throw();
	};
	/**
	 * @class alreadySigned
	 * @brief classes that are used to throw exceptions 
	 * 		 when the Form is aready signed
	*/
	class alreadySigned : public std::exception
    {
		public :
			/**
			 * @brief overrided what() method from std::exception.
			*/
			virtual const char* what() const throw();
	};
};

/** Utils Functions (mandatory)
* @brief Includes functions as required by the subject guidelines of 42
* @see subject_en.pdf for more information
*/
std::ostream &operator<<(std::ostream& out, const Form& obj);

#endif