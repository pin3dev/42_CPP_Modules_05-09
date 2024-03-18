/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mColors.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:55:41 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 10:26:08 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MCOLORS_HPP
# define MCOLORS_HPP

/**
 * @file mColors.hpp
 * @brief definition of MACROS to color the output of the program and ENUMS to check the grade
*/

/**
 * @brief Macros def limits the higher and lower value to grade of Bureaucrats
*/
#define HIGHER_GRADE 1 
#define LOWER_GRADE 150 
/**
 * @brief Macros def limits to be set by AForm/Robotomy derived concrete class objects
 * to the lower grade to sign and execute it
 * 
*/
#define TO_SIGN_R 72
#define TO_EXEC_R 45
/**
 * @brief Macros def limits to be set by AForm/Shrubbery derived concrete class objects
 * to the lower grade to sign and execute it
 * 
*/
#define TO_SIGN_S 145
#define TO_EXEC_S 137
/**
 * @brief Macros def limits to be set by AForm/Presidential derived concrete class objects
 * to the lower grade to sign and execute it
 * 
*/
#define TO_SIGN_P 25
#define TO_EXEC_P 5

enum checkGrade
{
	checkAll,
	checkHigher,
	checkLower
};

#define RESET    "\x1b[0m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RED    "\x1b[31m"
#define GRAY  "\x1b[37m"
#define MAGENTA "\x1b[35m"
#define BKGRAY	"\x1b[47;90m"
#define CYAN    "\x1b[36m"

# endif