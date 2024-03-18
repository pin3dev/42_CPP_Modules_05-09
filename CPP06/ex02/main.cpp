/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:51:25 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 09:04:24 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**
 * This is an main function to test the 
 * @warning Should run several unit tests to check these methods:
 * - Generating a random pointer to Base class;
 * - Generating a random reference to Base class;
 * - Checking the identify function with a pointer to Base class generated;
 * - Checking the identify function with a reference to Base class generated;
 * @see This main depends on some MACROS and ENUMS in @file mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}