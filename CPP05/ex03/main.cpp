/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:29 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/19 21:07:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    //testing block 0: creating
	Bureaucrat	sef("AIMA", 7); //Bureaucrat Constructor called to AIMA
	Intern 	me;	//Inter Default Constructor

	//testing block 1: creating forms by Interns calls
	AForm	*ptHOME = me.makeForm("shrubbery creation", "Casinha");	//Intern trying to create form [shrubbery creation]
	//AForm Constructor called to Def_Form_S
	//Shrubbery Constructor called to Casinha
	//Intern create [shrubbery creation] w/ name Def_Form_S
	AForm	*ptAF = me.makeForm("robotomy request", "An*fei*"); //Intern trying to create form [robotomy request]
	//AForm Constructor called to Def_Form_R
	//Robotomy Constructor called to An*fei*
	//Intern create [robotomy request] w/ name Def_Form_R
	AForm	*ptME = me.makeForm("presidential pardon", "Ivany"); //Intern trying to create form [presidential pardon]
	//AForm Constructor called to Def_Form_P
	//Presidential Constructor called to Ivany
	//Intern create [presidential pardon] w/ name Def_Form_P
	AForm	*ptERROR = me.makeForm("tadinha pobrezinha", "Ivany"); //Intern trying to create form [tadinha pobrezinha] + Error Result
	(void)*ptERROR;

	//testing block 2: Recreating the main of ex02

//>>>>>Downcasting
	ShrubberyCreationForm dptHOME = *static_cast<ShrubberyCreationForm*>(ptHOME); //Shrubbery Copy Constructor called to Casinha + AForm Constructor called to Def_Form_S
	RobotomyRequestForm dptAF = *static_cast<RobotomyRequestForm*>(ptAF); //Robotomy Copy Constructor called to An*fei* + AForm Constructor called to Def_Form_R
	PresidentialPardonForm dptME = *static_cast<PresidentialPardonForm*>(ptME); //Presidential Copy Constructor called to Ivany + AForm Constructor called to Def_Form_P

//>>>>>Printing
	std::cout << sef; //List of private members of Bureaucrat AIMA
	std::cout << dptHOME; //List of private members of Shrubbery Form Casinha
	std::cout << dptAF; //List of private members of Robotomy Form An*fei*
	std::cout << dptME; //List of private members of Presidential Form Ivany
//>>>>>Executing
	sef.executeForm(*ptHOME); //Bureaucrat AIMA trying to execute form Def_Form_S + Negative Results
	sef.executeForm(*ptAF); //Bureaucrat AIMA trying to execute form Def_Form_R + Negative Results
	sef.executeForm(*ptME); //Bureaucrat AIMA trying to execute form Def_Form_P + Negative Results

	sef.signForm(*ptHOME); //Bureaucrat AIMA trying to sign form Def_Form_S + Results (depends of initial number)
	sef.signForm(*ptAF); //Bureaucrat AIMA trying to sign form Def_Form_R + Results (depends of initial number)
	sef.signForm(*ptME); //Bureaucrat AIMA trying to sign form Def_Form_P + Results (depends of initial number)

//>>>>>Downcasting
	dptHOME = *static_cast<ShrubberyCreationForm*>(ptHOME); //Shrubbery Copy Constructor called to Casinha + AForm Constructor called to Def_Form_S
	dptAF = *static_cast<RobotomyRequestForm*>(ptAF); //Robotomy Copy Constructor called to An*fei* + AForm Constructor called to Def_Form_R
	dptME = *static_cast<PresidentialPardonForm*>(ptME); //Presidential Copy Constructor called to Ivany + AForm Constructor called to Def_Form_P

//>>>>>Printing
	std::cout << sef; //List of private members of Bureaucrat AIMA
	std::cout << dptHOME; //List of private members of Shrubbery Form Casinha
	std::cout << dptAF; //List of private members of Robotomy Form An*fei*
	std::cout << dptME; //List of private members of Presidential Form Ivany
//>>>>>Executing
	sef.executeForm(*ptHOME);  //Bureaucrat AIMA trying to sign form Def_Form_S + Results (depends of initial number)
	sef.executeForm(*ptAF); //Bureaucrat AIMA trying to sign form Def_Form_R + Results (depends of initial number)
	sef.executeForm(*ptME); //Bureaucrat AIMA trying to sign form Def_Form_P + Results (depends of initial number)

	delete ptHOME;
	delete ptAF;
	delete ptME;
}