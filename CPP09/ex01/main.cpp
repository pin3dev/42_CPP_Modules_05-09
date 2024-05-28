/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:40 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/28 13:23:28 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << RED "Usage: ./RPN <RPNexpression>" RESET << std::endl;
        return 1;
    }
    try
    {
        std::string input(argv[1]);
        RPN::RPN_operations(input);
    }
    catch (std::exception& e)
    {
        std::cout << RED << e.what() << RESET;
        return 1;
    }
    return 0;
}