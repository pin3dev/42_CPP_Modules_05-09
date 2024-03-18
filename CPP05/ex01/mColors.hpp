/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mColors.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:55:41 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 09:28:09 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MCOLORS_HPP
# define MCOLORS_HPP

/**
 * @file mColors.hpp
 * @brief definition of MACROS to color the output of the program and ENUMS to check the grade
*/

#define HIGHER_GRADE 1 
#define LOWER_GRADE 150 

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