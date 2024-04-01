/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:59:18 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 17:33:06 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Template Class Default Constructor
 * @brief Initializes the MutantStack as usual by automatically
 *        and prints a message to the console.
 *  calling the default constructor of std::stack.
 */
template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << BKGRAY "[MutantStack] Default Constructor called" RESET << std::endl;
}

/**
 * Template Class Copy Constructor
 * @brief Initializes the MutantStack by copying the provided MutantStack object
 *       and prints a message to the console.
 * @tparam src Constant reference to a MutantStack object that will be ignored.
 * 
 * The canonical form is implemented here as standard, but
 * the class has no private members that could be changed.
 */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    (void)src;
     std::cout << BKGRAY "[MutantStack] Copy constructor called" RESET << std::endl;
}

/**
 * Copy Assignment operator / OVERLOAD OPERATOR
 * @deprecated This operator does not modify the standard implementation and will be ignored.
 */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    (void)other;
    std::cout << BKGRAY "[MutantStack] Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

/**
 * Template Class Destructor
 * @brief Deletes the MutantStack object, either by an explicit call (delete Span) in case of heap memory allocation
 *        or automatically in case of stack memory allocation, and prints a message to the standard output.
 * 
 * This behavior is standard and mandatory.
 */
template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << BKGRAY "[MutantStack] Destructor called" RESET << std::endl;
}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * @brief Returns an iterator pointing to the beginning of the MutantStack.
 * @tparam T Type of data stored in the MutantStack.
 * @return An iterator pointing to the beginning of the MutantStack.
 * @warning The std::stack uses std::deque as the default container,
 *         and therefore stores this data as a public member class called 'c'
 *         which could be accessed directly.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

/**
 * @brief Returns an iterator pointing to the end of the MutantStack.
 * @tparam T Type of data stored in the MutantStack.
 * @return An iterator pointing to the end of the MutantStack.
 * @warning The std::stack uses std::deque as the default container,
 *         and therefore stores this data as a public member class called 'c'
 *         which could be accessed directly.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

/**
 * @brief Returns an const_iterator pointing to the beginning of the MutantStack.
 * @tparam T Type of data stored in the MutantStack.
 * @return An const_iterator pointing to the beginning of the MutantStack.
 * @warning The std::stack uses std::deque as the default container,
 *         and therefore stores this data as a public member class called 'c'
 *         which could be accessed directly.
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

/**
 * @brief Returns an const_iterator pointing to the end of the MutantStack.
 * @tparam T Type of data stored in the MutantStack.
 * @return An const_iterator pointing to the end of the MutantStack.
 * @warning The std::stack uses std::deque as the default container,
 *         and therefore stores this data as a public member class called 'c'
 *         which could be accessed directly.
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
};