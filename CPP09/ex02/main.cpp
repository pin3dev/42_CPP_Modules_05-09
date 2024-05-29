/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:29 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 11:36:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Logger.hpp"

//./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')

int	main(int ac, char **av)
{
	try
	{
		Logger log;
		PmergeMe program(ac, av);
		program.setLogger(&log);
		program.runMergeInsertion();
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}
}