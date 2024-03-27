/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:57:36 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 16:37:48 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

#include "mColors.hpp" //to color MACROS
#include <vector> //std::vector
#include <iostream> //to std::ostream and std::cout
#include <iomanip> //to std::setw

/**
 * Classe Definition
 * @class Span
 * @brief a Class that can store a maximum of _N integers
 * @param _Vnumb std::vector<int> used to store integers
 * @param _N unsigned int specifies the maximum capacity of _Vnumb.
 * @param _remainsN unsigned int number of available slots remaining for storing integers.
 * 
 * More details in class
*/
class Span
{
    private:
        std::vector<int> _vector;
        unsigned int    _N;
        unsigned int    _remainsN;
    public:
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        Span(); //Default Constructor
        Span(Span const &src); //Copy Constructor
		Span &operator=(const Span &src); //Copy assignment operator
        ~Span(); //Destructor
        
        /**
         * @typedef it
         * @brief Defines an alias for a vector<int>::iterator.
         * 
         * Simplifies subsequent references to this data type.
         */
        typedef std::vector<int>::iterator it;
        
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        Span(unsigned int N); //Constructor with unsigned int param (mandatory)
        Span(it first, it last); //Constructor with iterator param (optional)
        void addNumber(int numb); //(mandatory)
        void addNumber(it first, it last); //Override to original addNumber function (optional)
        int shortestSpan(); //(mandatory)
        int longestSpan(); //(mandatory)

		/**
         * Setters and Getters
         * @brief For copying and strictly manipulating private members 
         * like _Vnumb, _N, and _remainsN
         * 
         * These functions are optional but recommended to 
         * ensure the encapsulation of the class
        */
        int getContent(unsigned int i)const;
        unsigned getN()const;
        unsigned int getRemainsN()const ;
        std::vector<int> getVector()const;
        void setRemainsN();

        /**
         * Utils Members
         * @brief checks the value of _remainsN
         *
         * This function is optional and contribute to the logic of my implementation
        */
        bool ifRemainsN(unsigned int n);
};


# endif
