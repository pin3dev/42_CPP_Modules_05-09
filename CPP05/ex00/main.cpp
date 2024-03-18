/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:27 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 15:29:00 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" //to Bureaucrat class
#include <memory> //to std::unique_ptr

/**
 * This is an main function to test the "Bureaucrat" objects
 * NOTE 1 - Should run several unit tests to check this object:
 * - Default Constructor;
 * - Constructor with param int;
 * - Constructor with param iterator;
 * - Copy Constructor;
 * - Copy assignment operator;
 * - Destructor (memory leaks);
 * - Calling Bureaucrat with lower and higher grade than the limits;
 * - Calling Bureaucrat with the limits;
 * NOTE 2 - This main depends on some MACROS and ENUMS in @file mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main()
{
    //testing block 0: creating
    Bureaucrat* sef = new Bureaucrat("SEF", 2); //Creating a Bureaucrat with grade 2
    Bureaucrat* aima = new Bureaucrat("Aima", 149); //Creating a Bureaucrat with grade 149
    
    //testing block 1: incrementing
    try
    {
        std::cout << *sef; //Printing the Bureaucrat content
        sef->increment(); //Incrementing the Bureaucrat
        std::cout << *sef; //Printing the Bureaucrat content
        sef->increment(); //Incrementing the Bureaucrat
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    //testing block 2: decrementing
    try
    {
        std::cout << *aima; //Printing the Bureaucrat content
        aima->decrement(); //Decrementing the Bureaucrat
        std::cout << *aima; //Printing the Bureaucrat content
        aima->decrement(); //Decrementing the Bureaucrat
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    //testing block 3: limits
    try
    {
        //TODO - verificar se o unique_ptr está funcionando com c++98
        //TODO - verificar LEAKS
		std::unique_ptr<Bureaucrat> toHigh(new Bureaucrat("ToHigh", 0)); //Trying to create a Bureaucrat with grade 0, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    try
    {
        //TODO - verificar se o unique_ptr está funcionando com c++98
        //TODO - verificar LEAKS
		std::unique_ptr<Bureaucrat> toLow(new Bureaucrat("ToLow", 151));//Trying to create a Bureaucrat with grade 151, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    delete sef;
    delete aima;
}