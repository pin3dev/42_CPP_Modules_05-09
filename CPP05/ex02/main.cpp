/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:29 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/19 21:07:03 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    //testing block 0: creating
	Bureaucrat	sef("SEF", 7); //creating a Bureaucrat with grade 7
	AForm	*ps = new ShrubberyCreationForm("ShrubberyHOME"); //creating a ShrubberyCreationForm with target "ShrubberyHOME"
	AForm	*pr = new RobotomyRequestForm("RobotomyNEIGHBOR"); //creating a RobotomyRequestForm with target "RobotomyNEIGHBOR"
	AForm	*pp = new PresidentialPardonForm("PresidentialMYSELF"); //creating a PresidentialPardonForm with target "PresidentialMYSELF"

//>>>>>Downcasting
	ShrubberyCreationForm dps = *static_cast<ShrubberyCreationForm*>(ps); //Downcasting to access the overload of the operator << in ShrubberyCreationForm class
	RobotomyRequestForm dpr = *static_cast<RobotomyRequestForm*>(pr); //Downcasting to access the overload of the operator << in RobotomyRequestForm class
	PresidentialPardonForm dpp = *static_cast<PresidentialPardonForm*>(pp); //Downcasting to access the overload of the operator << in PresidentialPardonForm class

//>>>>>Printing
	std::cout << sef; //Printing the Bureaucrat content
	std::cout << dps; //printing the ShrubberyCreationForm content
	std::cout << dpr; //printing the RobotomyRequestForm content
	std::cout << dpp; //printing the PresidentialPardonForm content

    //testing block 1: execution permissions on not signed forms

//>>>>>Executing
	sef.executeForm(*ps); //trying to execute a not signed ShrubberyCreationForm
	sef.executeForm(*pr); //trying to execute a not signed RobotomyRequestForm
	sef.executeForm(*pp); //trying to execute a not signed PresidentialPardonForm

	//testing block 2: signing forms

	sef.signForm(*ps); //signing the ShrubberyCreationForm
	sef.signForm(*pr); //signing the RobotomyRequestForm
	sef.signForm(*pp); //signing the PresidentialPardonForm

    //testing block 3: execution permissions on signed forms
	
//>>>>>Downcasting
	ShrubberyCreationForm ndps = *static_cast<ShrubberyCreationForm*>(ps);//Downcasting to access the overload of the operator << in ShrubberyCreationForm class
	RobotomyRequestForm ndpr = *static_cast<RobotomyRequestForm*>(pr); //Downcasting to access the overload of the operator << in RobotomyRequestForm class
	PresidentialPardonForm ndpp = *static_cast<PresidentialPardonForm*>(pp); //Downcasting to access the overload of the operator << in PresidentialPardonForm class

//>>>>>Printing
	std::cout << ndps; //printing the ShrubberyCreationForm content
	std::cout << ndpr; //printing the RobotomyRequestForm content
	std::cout << ndpp; //printing the PresidentialPardonForm content

//>>>>>Executing
	sef.executeForm(*ps); //executing the ShrubberyCreationForm
	sef.executeForm(*pr); //executing the RobotomyRequestForm
	sef.executeForm(*pp); //executing the PresidentialPardonForm

	delete ps;
	delete pr;
	delete pp;
}