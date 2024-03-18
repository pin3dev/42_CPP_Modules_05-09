/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:52:47 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:42:15 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

/**
 * This is an main function to test the functions templates
 * @warning Should run several unit tests to check these functions:
 * - Generate 2 different values data of same type;
 * - Checking biggest and lowest between both
 * - Checking swap datas
 * @see This main depends on some MACROS and ENUMS in @file mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main()
{
	//testing block 0: creating int data
	int a = 2;
	int b = 3;
	//testing block 1: testing swap
	::swap( a, b );
	//testing block 2: printing
	std::cout << "a = " << a << ", b = " << b << std::endl;
	//testing block 3: testing and printing min and max
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	//testing block 4: creating std::string data
	std::string c = "chaine1";
	std::string d = "chaine2";
	//testing block 5: testing swap
	::swap(c, d);
	//testing block 6: printing
	std::cout << "c = " << c << ", d = " << d << std::endl;
	//testing block 7: testing and printing min and max
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}