/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDataBase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/04 09:44:22 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP

#include "Checker.hpp" //to all libraries and Checker class

/**
 * @def DB_PATH the path to the database file
 * @def DB_SEPARATOR the separator used in the database file
*/
#define DB_PATH "data.csv"
#define DB_SEPARATOR ','

/**
 * Class Definition
 * @class BitcoinDataBase
 * @brief BitcoinDataBase class to store the data from the database file
 * @param DBdata a map to store the data from the database in the form of a key-value pair
 * @throws std::runtime_error if the database file is not found
 * 
 * @related Checker
 * @note All the functions used to check the availability if the database file and the
 *      content of the file are implemented in the Checker class, and any exception related
 *      with this errors will be thrown by the Checker class
 * @see Checker.cpp for more information
 * 
 * More details about the class
*/
class BitcoinDataBase : public Checker
{
    public:
        std::map<std::string, float> DBdata;

		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */  
        BitcoinDataBase();;
        BitcoinDataBase(const BitcoinDataBase& src);
        BitcoinDataBase& operator=(const BitcoinDataBase& src);
        ~BitcoinDataBase();
};

#endif
