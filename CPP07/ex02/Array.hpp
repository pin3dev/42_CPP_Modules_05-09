/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:34 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 17:48:33 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include "mColors.hpp"

/**
 * Class Declaration
 * @class Array
 * @brief A class that represents an array of a given type
 * @param T The type of the array
 * @param _array The array of type T
 * @param _size The size of the array
 * 
*/
template<typename T>
class Array
{
	private :
		T*				_array;
		unsigned int	_size;
	public :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		Array();
		Array(const Array &src);
		Array &operator=(const Array &src);
		~Array();
		
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		Array(unsigned int n); //Constructor with parameter
		T &operator[](unsigned int i); //Operator Overload to access elements

		
		/**
         * Getters
         * @brief For copying private members 
         * like _array and _size
         * 
         * This functions are mandatory 
		 * and help to mantenance the encapsulation of the class
        */
    	T getTContent(unsigned int i) const;
		unsigned int size() const;
		
		/**
         * Array Exceptions Classes
         * @brief classes that are used to throw exceptions 
		 * 		 when the index is out of bounds
		 * 
		 * @note Includes exception classes inherited from std::exception
		 * 		and overload of what() method
        */
		class OutOfBounds : public std::exception
        {
			/**
			 * @brief overrided what() method from std::exception.
			 * @note The const throw() is a specification that indicates that the function does not throw exceptions.
			 * @note The virtual is a specification that indicates that the function can be overrided by a derived class.
			*/
			public :
				const char *what() const throw();
		};
		
};

/** Utils Functions (optional)
* @brief This function is used to print the Array content in the console.
* @note This function is optional, but it is very useful for debugging.
*/
template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T>&obj);

#include "Array.tpp" 

#endif
