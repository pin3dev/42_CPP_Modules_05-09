/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/03 16:49:12 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/
/**
 * Default constructor
 * @brief Initialize the BitcoinExchange object with a NULL pointer to BitcoinDataBase
 * 
 * This behavior is optional, but it was implemented to follow the SOLID principles
 */
BitcoinExchange::BitcoinExchange(): _DBacess(NULL){};

/**
 * Copy constructor
 * @deprecated Copy constructor is not used in this class, just exists to fill the requirements of Canonical Form
*/
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){(void)src;};

/**
 * Copy assignment operator
 * @deprecated Copy assignment operator is not used in this class, just exists to fill the requirements of Canonical Form
*/
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){(void)src; return (*this);};

/**
 * Destructor
 * @brief Close the input file if it is open
 * 
 * @note if the object was created by the default constructor, the input file will not be open
 *      otherwise, the input file will be open, and have to be closed
*/
BitcoinExchange::~BitcoinExchange() 
{
    if (this->_INPUTfile.is_open())
        this->_INPUTfile.close();
}
/** !SECTION 
 * ******************************
 * SECTION - ADDITIONAL FUNCTIONS 
 * ******************************
*/
/**
 * Constructor
 * @brief Initialize the BitcoinExchange object with a path to the input file and a pointer to BitcoinDataBase
 * 
 * @param INPUTpath Path to the input file that will be used to exchange the values
 * @param DBacess Pointer to BitcoinDataBase that will be used to compare the values
 * 
 * @throw std::runtime_error If the input file can't be opened
 * 
 * @warning The INPUTpath is a input file that will be opened by the constructor, 
 *          calling the _INPUTfile constructor passing the INPUTpath as const char*
 *          is the same as calling the _INPUTfile.open(INPUTpath.c_str())
 * @note the ckOpenFile function is an Checker method that will throw an exception if the file can't be opened
 * @see more in Checker.cpp
*/
BitcoinExchange::BitcoinExchange(const std::string &INPUTpath, const BitcoinDataBase *DBacess) : _DBacess(DBacess), _INPUTfile(INPUTpath.c_str())
{
    Checker::ckOpenFile(this->_INPUTfile);
}

/**
 * @brief Compare the value of exchange of input and database
 *        and calculate the exchange value by multiplying the value
 *        of the database by the value of the input
 * @param pair ValidPair that contains the pair type <std:::string, float> that contains
 *       the date at first place, and value of exchange in the secound place
 * 
 * @warning The function uses some variables that will be helpful to find the exchange value, like:
 *      - std::map<std::string, float>::const_iterator it; that will be used to iterate over the database map
 * 
 * @note The idea of findExchange is to a date (key) of input (pair.first) inside of
 *       the database map, and get the value of exchange (pair.second) and multiply by the value of the database
 *       and if the date is not found in the database, the function will get the value of the date imeadiatly before the input date
 *      and multiply by the value of the input
 * 
 * @note The upper_bound function of the map will return the first element that is greater than the key
 *       so, to get the element before the key, the function will decrement the iterator
 *       and this method is enough to all cases, because the map is ordered by the date
 *       EXAMPLE: map = {{"2024-02-22", 1.0}, {"2024-02-23", 2.0}, {"2024-02-24", 3.0}}
 *                findExchange({"2024-02-23", 2.0}) will return 2.0 * 2.0
 *                because the upper_bound of "2024-02-23" is "2024-02-24"
 *                and the iterator will be decremented to "2024-02-23"
 *      EXAMPLE: map = {{"2024-02-22", 1.0}, {"2024-02-23", 2.0}, {"2024-02-24", 3.0}}
 *               findExchange({"2024-02-25", 2.0}) will return 2.0 * 3.0
 *               because the upper_bound of "2024-02-25" is end() 
 *               and the iterator will be decremented to "2024-02-24"
 *      EXAMPLE: map = {{"2024-02-22", 1.0}, {"2024-02-23", 2.0}, {"2024-02-24", 3.0}}
 *               findExchange({"2021-02-21", 2.0}) will return exception "Value Error: ..."
 *               because dont have any another date lower compares with the provided
*/
void BitcoinExchange::findExchange(ValidPair pair)
{
    std::map<std::string, float>::const_iterator it;
    it = _DBacess->DBdata.upper_bound(pair.first);
    if (it == _DBacess->DBdata.begin())
        throw(std::runtime_error("Value Error: No lower date to compares to the provided input date\n"));
    --it;
    std::cout << pair.first << " => " << pair.second << " = "
    << (pair.second * it->second) << std::endl;
}

/**
 * @brief Read the input file and compares doing the exchange with the database values
 * 
 * @warning The function could throw an exception if the database is NULzL
 *          or if the input file is not open, and that exceptions are handled by the main function
 *          finilizing the program
 * @warning The function will read line by line the input file, and and after the check of format by checker class
 *          will call the findExchange function to calculate the exchange value
 *          so, if any exception is thrown by the checker of format, this function will catch and print the error
 *          without stop the program, and all the other lines will be read and checked
*/
void BitcoinExchange::exchange()
{
    if (_DBacess == NULL)
        throw std::runtime_error("Fatal Error: No database file to exchange\n");
    if (!this->_INPUTfile.is_open())
        throw std::runtime_error("Fatal Error: No input file to exchange\n");
    std::string line;
    std::getline(this->_INPUTfile, line);
    ckFirstLine(line, "date | value");
    while (std::getline(this->_INPUTfile, line))
    {
        try
        {
            ckFormat(line, INPUT_SEPARATOR, true);
            //std::cout << line << " OK" << std::endl; //comment this line, just for debug
            //InputPair pair = makeValidPair(); //comment this line, bc its better to call the function directly
            findExchange(makeValidPair());
        }
        catch(const std::exception& e){std::cerr << CYAN << e.what() << RESET;}
    }
}

