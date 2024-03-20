/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/20 14:22:53 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm> //to std::find
#include <utility> //to std::pair
#include <iostream> //to std::cout, std::cin, std::endl
#include <exception> //to exception class
#include <fstream> //to std::ifstream, std::ofstream, etc
#include <sstream> //to std::stringstream
#include <string> //to std::string, std::getline
#include <map> 
#include "Checker.hpp"

#define DB_PATH "data.csv"
#define DB_SEPARATOR ','
#define INPUT_SEPARATOR '|'

class BitcoinExchange : public Checker
{
    private:
        //ATRIBUTOS
        std::map<std::string, float> DBdata;
        //ALIAS
        typedef std::map<std::string, float>::iterator itDB;
        typedef std::pair<std::string, float> validPairDB;
        //METODOS        
        void DB(void);
        validPairDB storeDB(std::string &line);

    public:
        void exchange(std::string &INPUTpath);
};

#endif
