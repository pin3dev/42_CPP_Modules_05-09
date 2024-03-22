/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:41 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 21:15:09 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, const char **av)
{
	if (ac == 2)
	{
        std::string input = av[1];
	    ScalarConverter::convert(input);
	}
	else
		std::cerr << "[Try] ./convert <numb or char>" << std::endl;
	return 0;
}