/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDataBase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 15:34:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinDataBase.hpp"

BitcoinDataBase::BitcoinDataBase(const BitcoinDataBase& src){(void)src;};
BitcoinDataBase& BitcoinDataBase::operator=(const BitcoinDataBase& src){(void)src; return (*this);};
BitcoinDataBase::~BitcoinDataBase(){};


BitcoinDataBase::BitcoinDataBase()
{
    std::ifstream	DBfile(DB_PATH);
    Checker::ckOpenFile(DBfile); //throws exception
    
    std::string line;
    std::getline(DBfile, line);
    Checker::ckFirstLine(line, "date,exchange_rate");
    while (std::getline(DBfile, line))
    {
        ckFormat(line, DB_SEPARATOR, false); //throws exception
        this->DBdata.insert(makeValidPair());
    }
}
