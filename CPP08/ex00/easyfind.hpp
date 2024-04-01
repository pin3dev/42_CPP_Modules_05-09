/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 16:09:31 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream> //to std::cout
#include <algorithm> //to std::find, container.begin() and container.end()
#include <iterator> //to std::distance

/**
 * Template Function declaration "easyfind"
 * 
 * @note the 'T' param can represent any type of data, including but not limited to 
 * int, string, double, float, std::vector<int>, std::liststd::string, etc. 
 * However, the internal processing within the easyfind() function 
 * specifies that the data be treated as a container of integers (container<int>).
*/
template <typename T>
void easyfind(const T &container, int n);

/**
 * @note This inclusion is optional but essential for separating 
 * the declaration of the function template from its implementation,
 * and it is a good pratice to include in the last line of the header file.
*/
#include "easyfind.tpp"

#endif
