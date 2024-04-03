/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDataBase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/03 16:37:09 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinDataBase.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/
/**
 * Default constructor
 * @brief Initialize the BitcoinDataBase object with the data from a constant file
 *        and store it in a std::map if the data is valid, checked by following some rules
 *        estipulated by the Checker class
 * 
 * @warning The file path is defined by the constant DB_PATH
 * @see DB_PATH definition in BitcoinDataBase.hpp
 * 
 * @throws std::runtime_error if the file is not found or 
 *          for some reason could not be opened, or if the first line of the file was wrong
 *          and this exception will be caught by the main function
 *          stopping the program execution
 * @note Any throw exception will be thrown by the Checker class
 * 
 * @note The function skFormat is called passing the false bool, because
 *       the ex_value provided by the database.csv file is not checked for validity
 *       and this behavor is choiced by ME
*/
BitcoinDataBase::BitcoinDataBase()
{
    std::ifstream	DBfile(DB_PATH);
    Checker::ckOpenFile(DBfile); //could throw exception
    
    std::string line;
    std::getline(DBfile, line);
    Checker::ckFirstLine(line, "date,exchange_rate"); //could throw exception
    while (std::getline(DBfile, line))
    {
        ckFormat(line, DB_SEPARATOR, false); //could throw exception
        this->DBdata.insert(makeValidPair());
    }
}
/**
 * Copy constructor
 * @deprecated Copy constructor is not used in this class, just exists to fill the requirements of Canonical Form
*/
BitcoinDataBase::BitcoinDataBase(const BitcoinDataBase& src){(void)src;};
/**
 * Copy assignment operator
 * @deprecated Copy assignment operator is not used in this class, just exists to fill the requirements of Canonical Form
*/
BitcoinDataBase& BitcoinDataBase::operator=(const BitcoinDataBase& src){(void)src; return (*this);};
/**
 * Destructor
 * @deprecated Destructor is not expecified in this class, just exists to fill the requirements of Canonical Form
*/
BitcoinDataBase::~BitcoinDataBase(){};