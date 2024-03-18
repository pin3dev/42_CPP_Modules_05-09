/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:07:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 19:55:41 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_HPP
# define UTILS_HPP

#include <iomanip> //to std::setw
#include <string> //to std::string
#include <iostream> //to std::cout
#include "Span.hpp" //to Span object
#include "mColors.hpp" //to color MACROS

/**
 * @file testUtils.hpp
 * @brief definition of functions to help unit tests
*/

void    diffSpan(Span &obj);
void	printHeader(std::string header);
std::ostream &operator<<(std::ostream &out, const Span&obj);
//static void coutVec(std::vector<int> &n);

# endif