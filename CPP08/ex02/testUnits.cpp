/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUnits.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:03:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 19:47:44 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testUnits.hpp"

/**
 * @brief prints a aligned line to set regions of test
 * @param header std::string to be printed
*/
void	printHeader(std::string header)
{
	std::cout << std::setw(50) << RED "-----" << header << "-----" RESET << std::endl;
}