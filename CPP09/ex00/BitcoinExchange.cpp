/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 15:35:15 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _DBacess(NULL){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){(void)src;};
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){(void)src; return (*this);};

BitcoinExchange::~BitcoinExchange()
{
    this->_INPUTfile.close();
    //(void)_DBacess; //REMOVER ISSO QUANDO FOR APLICADO EXCHANGE MÉTODO
}

BitcoinExchange::BitcoinExchange(const std::string &INPUTpath, const BitcoinDataBase *DBacess) : _DBacess(DBacess), _INPUTfile(INPUTpath.c_str())
{
    Checker::ckOpenFile(this->_INPUTfile); //PODE LANÇAR EXCEÇÃO 
}


void BitcoinExchange::findExchange(ValidPair pair)
{
    std::map<std::string, float>::const_iterator it;
    it = _DBacess->DBdata.upper_bound(pair.first);
    --it;
    std::cout << pair.first << " => " << pair.second << " = "
    << (pair.second * it->second) << std::endl;
}


void BitcoinExchange::exchange()
{
    if (_DBacess == NULL)
        throw std::runtime_error("No database to exchange");
    if (!this->_INPUTfile.is_open())
        throw std::runtime_error("No input file to exchange");
    std::string line;
    std::getline(this->_INPUTfile, line);
    ckFirstLine(line, "date | value");
    while (std::getline(this->_INPUTfile, line))
    {
        try
        {
            ckFormat(line, INPUT_SEPARATOR, true); //PODE LANÇAR EXCEÇÃO MAS TERÁ TRATAMENTO
            //std::cout << line << " OK" << std::endl; //COMENTÁR ESSA LINHA
            //InputPair pair = makeValidPair();
            findExchange(makeValidPair());
        }
        catch(const std::exception& e){std::cerr << e.what();} //TRATAMENTO DE EXCEÇÃO
        
    }
}

