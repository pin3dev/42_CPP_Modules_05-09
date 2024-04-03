/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:00 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/02 23:08:25 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "BitcoinDataBase.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <file>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    BitcoinDataBase DB;
    try
    {
        std::cout << "---- TEST EXCHANGE WITHOUT DATABASE ----" << std::endl;
        BitcoinExchange a;
        a.exchange();
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    
    try
    {
        std::cout << "---- TEST EXCHANGE WITH DATABASE ----" << std::endl;
        BitcoinExchange b(input, &DB);
        b.exchange();
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
} 