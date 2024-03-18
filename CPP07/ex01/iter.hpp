/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:50 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 09:16:53 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define ITER_HPP

#include <iostream>

//TODO - REVISAR

/**
 * @brief Applies a function to each member of an array from the first until index + size.
 * @tparam T The type of elements in the array.
 * @tparam Func The type of function to be applied.
 * @param array A pointer to an array of any type.
 * @param size The size of each member of the array, used for iteration.
 * @param function A pointer to a function to be applied to the members of the array.
 */
template<typename T, typename Func>
void iter(T *array, size_t size, Func function)
{
    if (!array || !size || !function)
		return ;
	for (size_t i = 0; i < size ; i++)
		function(array[i]);
}

/**
 * @brief Prints a data value.
 * @tparam T The type of data to be printed.
 * @param var The data value to be printed.
 */
template<typename T>
void printarray(const T &var)
{
	std::cout << var << std::endl;
}

#endif