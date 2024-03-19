/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:16 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/19 21:05:31 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" //to class Bureaucrat
#include "Form.hpp" //to class Form

int main()
{
    //testing block 0: creating
    Form* doc = new Form("AR", 10, 30); //creating a form with a grade "AR" with a grade to sign as 10 and to execute 30
    std::cout << *doc; //Displaying the Form content, name, signature status and grade needed to sign and execute

    //testing block 1: limits
    try
    {
	    Form toHigh("ToHigh",  0, 20); //Trying to create a Form with grade to sign as 0, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails

    try
    {
        Form toLow("toLow",  10, 199); //Trying to create a Form with grade to execute as 199, should throw an exception
    }
    catch (std::exception & e){std::cerr << e.what() << std::endl;} //displaying the exception message when try() fails

    //testing block 2: signature permissions
    Bureaucrat* sef = new Bureaucrat("SEF", 5); //Creating a bureaucrat with a grade of 5 and name "SEF"
    std::cout << *sef; //displaying the bureaucrat's name and grade 5 higher than the form's AR "to sign" grade 
    sef->signForm(*doc); //Trying to sign the form "AR" with the bureaucrat "SEF", succeding
    std::cout << *doc; //displaying the form's name, signature status and signature grade, now signed by "SEF"
    sef->signForm(*doc); //Trying to sign the form "AR" with the bureaucrat "SEF" again, failing

    Form* pass = new Form("PASSPORT", 1, 1); //Creating a form with name "Passport" whit a grade of 1 to sign and to execute 1
    Bureaucrat* aima = new Bureaucrat("Aima", 12); //Creating a bureaucrat with a grade of 12 and name "Aima"
    std::cout << *pass; //displaying the form's pass, signature status and signature grade
    std::cout << *aima; //displaying the bureaucrat's name and grade 12, to lower to sign the "PASSPORT" form
    aima->signForm(*pass); //Trying to sign the form "PASSPORT" with the bureaucrat "Aima", failing
    std::cout << *pass; //displaying the form's name, signature status and signature grade, not signed yet

    delete doc;
    delete sef;
    delete pass;
    delete aima;
}
