/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/04 09:48:04 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Checker.hpp" //to all libraries and Checker class
#include "BitcoinDataBase.hpp" //to BitcoinDataBase class

#define INPUT_SEPARATOR '|'

/**
 * Class Definition
 * @class BitcoinExchange
 * @brief BitcoinExchange class to compare the data from the input file with the database file and
 *        do the exchange logic
 * @param _DBacess a pointer to BitcoinDataBase that will be used to compare the values
 * @param _INPUTfile a ifstream object to read the input file
 * @throws std::runtime_error if the database file is not found
 * 
 * @related Checker
 * @note All the functions used to check the availability if the input file and the
 *      content of the file are implemented in the Checker class, and any exception related
 *      with this errors will be thrown by the Checker class
 * @see Checker.cpp for more information
 * 
 * More details about the class
*/
class BitcoinExchange : public Checker
{
    private:
        const BitcoinDataBase *_DBacess;
        std::ifstream _INPUTfile;
        /**
         * Util Member Function
         * @brief Function help to implement the exchange logic
        */
        void findExchange(ValidPair pair);
        
    public:
        /**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

		/**
         * Additional Member Functions
         * @brief Includes member functions to implement the SOLID logic
        */
        BitcoinExchange(const std::string &INPUTpath, const BitcoinDataBase *DBacess);
        void exchange();
};

#endif
