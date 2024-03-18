/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:41 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 16:05:32 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

/**
 * This is an main function to test the ScalarConverter::convert methods
 * @warning - Should run several unit tests to check this methods/inputs:
 * - Message of Default Constructor - should not run;
 * - Message of Copy Constructor - should not run;
 * - Message of Copy assignment operator - should not run;
 * - Message of Destructor (memory leaks) - should not run;
 * - to INT: 
 * 		(1, -1, 0, 2147483647, -2147483648, 2147483648, -2147483649, 31, 128, 127, 10, 42, -42)
 * - to CHAR:
 * 		(a, '*', '!', H, '%', ' ')
 * - to FLOAT:
 * 		(1.0f, -1.0f, 0.0f, 0.f, -1.f, -1f., 1.f, 144324123e.1435f, 2147483647.0f, -2147483648.0f, 2147483648.0f, -2147483649.0f, 31.0f, 128.0f, 127.0f, 10.0f, 42.0f, -42.0f, 2147483647.1f, -2147483648.1f, 2147483648.1f, -2147483649.1f, 2147483647.9f, -2147483648.9f, 2147483648.9f, -2147483649.9f, 2147483647.f, 321.12f, 34234.12321.f, )
 * - to DOUBLE:
 * 		(1.0, -1.0, 0.0, 2147483647.0, -2147483648.0, 2147483648.0, -2147483649.0, 31.0, 128.0, 127.0, 10.0, 42.0, -42.0, 2147483647.1, -2147483648.1, 2147483648.1, -2147483649.1, 2147483647.9, -2147483648.9, 2147483648.9, -2147483649.9, 2147483647., 321.12, 34234.12321.)
 * - to PSEUDO:
 * 		(inf, -inf, nan, -nan, inff, -inff, nanf, -nanf)
 * - some big numbers to check the overflow of float and double
 * @see This main depends on some MACROS and ENUMS in @file mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main(int ac, const char **av)
{
	if (ac == 2)
	{
        std::string input = av[1];
	    ScalarConverter::convert(input);
	}
	else
		std::cerr << "[Try] ./convert <numb or char>" << std::endl;
	return 0;
}