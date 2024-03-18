/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUnits.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:03:25 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 20:08:03 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TESTUNITS_HPP
# define TESTUNITS_HPP

#include "MutantStack.hpp" //to MutantStack object
#include "mColors.hpp" //to color MACROS
#include <iostream> //to std::ostream and std::cout
#include <iomanip> //to std::setw
#include <algorithm> //to template AnyContainer
#include <vector> //to main unit tests
#include <list> //to main unit tests
#include <deque> //to main unit tests

/**
 * @file testUtils.hpp
 * @brief definition of functions and template functions to help unit tests
*/

template <typename T>
std::ostream &operator<<(std::ostream &out, const MutantStack<T>&obj);
template<typename AnyContainer>
std::ostream& printContainer(std::ostream& out, const AnyContainer& obj);
void	printHeader(std::string header);

/**
 * NOTE to students: This inclusion is optional but essential for separating 
 * the declaration of the function template from its implementation
*/
#include "testUtils.tpp"

# endif