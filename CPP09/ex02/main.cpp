/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:29 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/28 16:10:26 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if(argc < 2)
		return(std::cout << "Error(1)" << std::endl, 1);
	for(int i = 1; i < argc; i++)
	{
		if(std::atol(argv[i]) < 0 || std::atol(argv[i]) > INT_MAX  || std::atol(argv[i]) < INT_MIN)
			return(std::cout << "Error(2)" << std::endl, 1);
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			if(!isdigit(argv[i][j]))
				return(std::cout << "Error(3)" << std::endl, 1);
		}
	}

	PmergeMe	numbers(argv, argc);//inicia o vector e o deque com os numeros

	numbers.sorting();
	return(0);
}