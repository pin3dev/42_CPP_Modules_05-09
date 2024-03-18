/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:36 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:53:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iomanip>

static void	printHeader(std::string header)
{
	std::cout << std::setw(50) << MAGENTA "-----" << header << "-----" RESET << std::endl;
}

int main()
{
    //testing block 0: creating
    printHeader("TEST 0:DEFAULT CONSTUCTORS");
    Array<int> _int_null; //Creating a Array with default constructor type int
    std::cout << _int_null << std::endl; //Printing the Array content, should be empty

    Array<std::string> _str_null; //Creating a Array with default constructor type std::string
    std::cout << _str_null << std::endl; //Printing the Array content, should be empty

    printHeader("TEST 1:CONSTUCTORS WITH PARAMETER AND INIT BY []");

	Array<std::string> _str(3); //Creating a Array type std::string with 3 slots
	std::cout << _str << std::endl; //Printing the Array content, should be empty

	_str[0] = "Hello"; //Using the operator overload[] to init the first element
	_str[1] = "World"; //Using the operator overload[] to init the second element
	_str[2] = "!"; //Using the operator overload[] to init the third element
	std::cout << _str << std::endl; //Printing the Array content, should be "Hello World !"

    Array<int> _int(13); //Creating a Array type int with 13 slots
	std::cout << _int << std::endl; //Printing the Array content, should be empty

    for (size_t i = 0; i < 13; i++) //Running the array from the index 0 until 12
        _int[i] = i;  //Filling the array with the index value
    std::cout << _int << std::endl; //Printing the Array content, should be "0 1 2 3 4 5 6 7 8 9 10 11 12"

    //testing block 2: overload operator
    printHeader("TEST 2:UNITARY ACCESS BY []");


    try {_str[1] = GREEN "trying " RESET; _str[2] = GREEN "access..." RESET; } //try to acess the index 1 and 2 and change the value
    catch(const std::exception& e){std::cerr << "TEST 2.1 <STR>: " << e.what() << '\n';} //if the index is out of bounds, should throw an exception, but it's not the case
	std::cout << _str << std::endl; //Printing the Array content, should be "Hello trying access..."
    
    try {_int[7] = -10;_int[12] = 0;} //try to acess the index 7 and change the value
    catch(const std::exception& e){std::cerr << "TEST 2.2 <INT>: " << e.what() << '\n';} //if the index is out of bounds, should throw an exception, but it's not the case
	std::cout << _int << std::endl; //Printing the Array content, should be "0 1 2 3 4 5 -10 7 8 9 10 11 0"


    //testing block 3: exceptions
    printHeader("TEST 3:EXCEPTIONS");

    try {_str[-1] = "OK"; _str[2] = "?";} //try to acess the index -1 and 2 and change the value, should throw an exception
    catch(const std::exception& e){std::cerr << RED "TEST 3.1 <STR>: " << e.what() << '\n';} //catch the exception and print the message
    std::cout << _str << std::endl; //Printing the Array content, should be "Hello trying access..." as the previous test

    try {_str[1] = YELLOW "Where " RESET; _str[-2] = YELLOW "are u?" RESET;} //try to acess the index 1 and -2 and change the value, should throw an exception
    catch(const std::exception& e){std::cerr << RED "TEST 3.2 <STR>: " <<e.what() << '\n';} //catch the exception and print the message
    std::cout << _str << std::endl; //Printing the Array content, should be "Hello Where access..."

    try {_int[-10] = -10;} //try to acess the index -10 and change the value, should throw an exception
    catch(const std::exception& e){std::cerr << RED "TEST 3.3 <INT>: " << e.what() << '\n';} //catch the exception and print the message
    std::cout << _int << std::endl; //Printing the Array content, should be "0 1 2 3 4 5 -10 7 8 9 10 11 0" as the previous test

     try {_int[13] = 10000;} //try to acess the index 13 and change the value, should throw an exception
    catch(const std::exception& e){std::cerr << RED "TEST 3.4 <INT>: " << e.what() << '\n';} //catch the exception and print the message
	std::cout << _int << std::endl; //Printing the Array content, should be "0 1 2 3 4 5 -10 7 8 9 10 11 0" as the previous test

    return 0;
}