/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:50 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 15:18:05 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype> 

/**
 * @brief Applies a function to each member of an array from the first until index + size.
 * @tparam T The type of elements in the array.
 * @tparam Func The type of function to be applied.
 * @param array A pointer to an array of any type.
 * @param size The size of each member of the array, used for iteration.
 * @param function a function to be applied to the members of the array.
 * 
 * @warning if the array is null or the size is 0, the function will print an error message and return.
 * 
 * @note in c++ a function could be treated as a type, which allows us to pass a function as a parameter to another function.
 * 		in this case, the function passed as a parameter must have a single parameter of the same type as the array.
 * @note in c++11 'if constexpr (std::is_invocable_v<Func, T>)' to check if the function is callable with the type T.
 */
template<typename T, typename Func>
void iter(T *array, size_t size, Func function)
{
	if (!array || size == 0)
	{
		std::cerr << "ERROR: Invalid array!" << std::endl;
		return;
	}
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