/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:16 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 12:34:39 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" //to class Bureaucrat
#include "Form.hpp" //to class Form
#include <memory> //to std::unique_ptr

/**
 * This is an main function to test the "Form" objects, Bureaucrat::signForm() and Form::beSigned() methods
 * NOTE 1 - Should run several unit tests to check this object:
 * - Default Constructor;
 * - Constructor with param int;
 * - Constructor with param iterator;
 * - Copy Constructor;
 * - Copy assignment operator;
 * - Destructor (memory leaks);
 * - Calling Form with lower and higher grade than the limits;
 * - Calling signForm with a Bureaucrat with lower and higher grade than the limits;
 * NOTE 2 - This main depends on some MACROS and ENUMS in @file mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main()
{
    //testing block 0: creating
    Form* doc = new Form("AR", 10, 30); //creating a form with a grade "AR" with a grade to sign as 10 and to execute 30
    std::cout << *doc; //Printing the Bureaucrat content

    //testing block 1: limits
    try
    {
        //TODO - verificar se o unique_ptr está funcionando com c++98
	    std::unique_ptr<Form> toHigh(new Form("ToHigh",  0, 20)); //Trying to create a Form with grade to sign as 0, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails

    try
    {
        //TODO - verificar se o unique_ptr está funcionando com c++98
        std::unique_ptr<Form> toLow(new Form("toLow",  10, 199)); //Trying to create a Form with grade to execute as 199, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails

    //testing block 2: signature permissions
    Bureaucrat* sef = new Bureaucrat("SEF", 5); //Creating a bureaucrat with a grade of 5 and name "SEF"
    std::cout << *sef; //displaying the bureaucrat's name and grade 5 higher than the form's "to sign" grade 
    sef->signForm(*doc); //Trying to sign the form "AR" with the bureaucrat "SEF", succeding
    std::cout << *doc; //displaying the form's name, signature status and signature grade, now signed by "SEF"
    sef->signForm(*doc); //Trying to sign the form "AR" with the bureaucrat "SEF" again, failing

    Form* pass = new Form("PASSPORT", 1, 1); //Creating a form with a grade "Passport" whit a grade of 1 to sign and to execute 1
    Bureaucrat* aima = new Bureaucrat("Aima", 12); //Creating a bureaucrat with a grade of 12 and name "Aima"
    aima->signForm(*pass); //Trying to sign the form "PASSPORT" with the bureaucrat "Aima", failing
    
    delete doc;
    delete sef;
    delete pass;
    delete aima;
}