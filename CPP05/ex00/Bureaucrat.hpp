/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:25 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 10:19:17 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream> //to std::cout and std::endl
#include <string> //to std::string
#include <exception> //to std::exception
#include "mColors.hpp" //to define the colors MACROS and ENUM

/**
 * Classe Definition
 * @class Bureaucrat
 * @brief This class is a representation of a Bureaucrat, a person who has name and grade.
 * @param _name a const string that represents the name of the Bureaucrat
 * @param _grade an integer that represents the grade of the Bureaucrat 
 * 		 (1 is the highest grade and 150 is the lowest)
 * @throws exceptions if the grade is higher than 1 or lower than 150
 * 
 * More details in class
*/
class Bureaucrat
{
	private :
		std::string const  _name;
		int		 		 _grade;
		
        /**
         * Utils Members
         * @brief Functions help to implement the exception verification
         *
         * This function is optional and contribute to the logic of my implementation
        */
		void ckOutLimitGrade(checkGrade type, int grade);
	public :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		Bureaucrat(std::string const name, int grade);
		void	increment();
		void	decrement();

		/**
         * Getters
         * @brief For copying private members 
         * like _name and _grade
         * 
         * This functions are mandatory 
		 * and help to mantenance the encapsulation of the class
        */
		std::string const	getName() const ;
		int		getGrade() const ;
		
		
		/**
         * Bureaucrat Exceptions Classes
         * @brief classes that are used to throw exceptions 
		 * 		 when the grade is higher than 1 
		 * 
		 * @note Includes exception classes inherited from std::exception
		 * 		and overload of what() method
        */
		class	GradeTooHighException : public std::exception
		{
			public :
				/**
				 * @brief overrided what() method from std::exception.
				 * @note The const throw() is a specification that indicates that the function does not throw exceptions.
				 * @note The virtual is a specification that indicates that the function can be overrided by a derived class.
				*/
				virtual const char* what() const throw();
		};
		/**
         * Bureaucrat Exceptions Classes
         * @brief classes that are used to throw exceptions 
		 * 		 when the grade is lower than 150
		 * 
		 * @note Includes exception classes inherited from std::exception
		 * 		and overload of what() method
        */
		class	GradeTooLowException : public std::exception
		{
			public :
				/**
				 * @brief overrided what() method from std::exception.
				 * @note The const throw() is a specification that indicates that the function does not throw exceptions.
				 * @note The virtual is a specification that indicates that the function can be overrided by a derived class.
				*/
				virtual const char* what() const throw();
		};
};

/** Utils Functions (mandatory)
* @brief Includes functions as required by the subject guidelines of 42
* @see subject_en.pdf for more information
*/
std::ostream &operator<<(std::ostream& out, const Bureaucrat& obj);

#endif