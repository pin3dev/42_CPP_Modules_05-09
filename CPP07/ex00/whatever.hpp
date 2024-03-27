/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:52:51 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 15:06:11 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/**
 * @brief Swaps two values provided as parameters.
 * @tparam T The type of data for both values, which must be the same.
 * @param[out] var1 The first value to swap.
 * @param[out] var2 The second value to swap.
 */
template <typename T>
void	swap(T &var1, T &var2)
{
	T	temp = var1;
	var1 = var2;
	var2 = temp;
}
/**
 * @brief Compares two values provided as parameters.
 * @tparam T The type of data for both values, which must be the same.
 * @param[out] var1 The first value to compare.
 * @param[out] var2 The second value to compare.
 * @return The smaller value between var1 and var2, or var2 if they are equal.
 * 
 * @note this function just is valid to types 'T' that supports comparison operators like: <, >, <=, >=, ==, !=
 * @note the std::string is a valid type to use this function bc it supports comparison operators
 * @note the comparison between strings is made by lexicographical orders automatically
 */
template <typename T>
T	min(T var1, T var2)
{
	if (var1 < var2)
		return var1;
	return var2;
}
/**
 * @brief Compares two values provided as parameters.
 * @tparam T The type of data for both values, which must be the same.
 * @param var1 The first value to compare.
 * @param var2 The second value to compare.
 * @return The larger value between var1 and var2, or var2 if they are equal.
 * 
 * @note this function just is valid to types 'T' that supports comparison operators like: <, >, <=, >=, ==, !=
 * @note the std::string is a valid type to use this function bc it supports comparison operators
 * @note the comparison between strings is made by lexicographical orders automatically
 */
template <typename T>
T	max(T var1, T var2)
{
	if (var1 > var2)
		return var1;
	return var2;
}

#endif