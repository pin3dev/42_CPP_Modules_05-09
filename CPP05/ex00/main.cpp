/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:27 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/19 20:57:27 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" //to Bureaucrat class

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
		  Bureaucrat toHigh("ToHigh", 0); //Trying to create a Bureaucrat with grade 0, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    try
    {
		  Bureaucrat toLow("ToLow", 151);//Trying to create a Bureaucrat with grade 151, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails
    delete sef;
    delete aima;
}