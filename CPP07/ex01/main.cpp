/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:46 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:43:12 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/**
 * This is an main function to test the functions templates
 * @warning Should run several unit tests to check these functions:
 * - Generate 3 different type array
 * - Checking application of iter through all arrays types
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main(void)
{
	int _int[5] = {0, 1, 2, 3, 4}; //creating int array
	char _char[3] = {'a', 'b', 'c'}; //creating char array
	std::string _str[4] = {"abc", "def", "ghi", "jkl"}; //creating std::string array

	std::cout << "---INT ARRAY---" << std::endl; //printing headline
	iter(_int, 5, printarray<int>); //applying printarray() function to each member of array of ints
	std::cout << "---CHAR ARRAY---" << std::endl; //printing headline
	iter(_char, 3, printarray<char>); //applying printarray() function to each member of array of chars
	std::cout << "---STR ARRAY---" << std::endl; //printing headline
	iter(_str, 4, printarray<std::string>); //applying printarray() function to each member of array of std::strings

	return (0);
}