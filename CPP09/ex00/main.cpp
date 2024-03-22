/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:00 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 14:37:15 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm> //to std::find, std::map
#include <utility> //to std::pair
#include <iostream> //to std::cout, std::cin, std::endl
#include <exception> //to exception class
#include <fstream> //to std::ifstream, std::ofstream, etc
#include <sstream> //to std::stringstream
#include <string> //to std::string, std::getline
#include "BitcoinExchange.hpp"
#include "BitcoinDataBase.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoin_exchange <line>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    try
    {
        BitcoinExchange a;
        a.exchange();
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    
    try
    {
        BitcoinDataBase DB;
        BitcoinExchange b(input, &DB);
        b.exchange();
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
} 