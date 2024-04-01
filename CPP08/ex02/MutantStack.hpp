/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:58:20 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 20:09:03 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack> //to class MutantStack
#include <iostream> //to std::cout
#include "mColors.hpp" //to color MACROS

/**
 * Template Class Definition
 * @class: MutantStack
 * @brief: A class that behaves like std::stack but with iterators.
 * @tparam T: Any type of data accepted by std::stack.
 * 
 * More details in class.
 */
template <typename T>
class MutantStack : public std::stack<T>
{
    public:
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        MutantStack(); //Default Constructor
        MutantStack(const MutantStack<T>& other); //Copy Constructor
        MutantStack& operator=(const MutantStack<T>& other); //Copy assignment operator
        ~MutantStack(); //Destructor
        
        /**
         * @typedef iterator
         * @brief Defines an alias for the iterator type of the underlying container of MutantStack.
         * 
         * This iterator type allows iteration over the elements stored in MutantStack and provides
         * access to modify those elements.
         *
         * @typedef const_iterator
         * @brief Defines an alias for the const_iterator type of the underlying container of MutantStack.
         * 
         * This const_iterator type allows iteration over the elements stored in MutantStack but does
         * not allow modification of those elements.
         */
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		    /**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        iterator begin(); //mimics begin original container method
        iterator end(); //mimics end original container method
        const_iterator begin() const; //mimics cbegin original container method
        const_iterator end() const; //mimics cend original container method
};

/**
 * @note This inclusion is optional but essential for separating 
 * the declaration of the function template from its implementation
*/
#include "MutantStack.tpp" 

#endif
