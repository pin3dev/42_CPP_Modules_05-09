/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/04 09:58:21 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include "mColors.hpp"
#include <algorithm> //to std::find
#include <utility> //to std::pair
#include <iostream> //to std::cout, std::cin, std::endl
#include <iomanip> //to std::setw, std::setfill
#include <exception> //to exception class
#include <fstream> //to std::ifstream, std::ofstream, etc
#include <sstream> //to std::stringstream
#include <string> //to std::string, std::getline
#include <map> //to std::map

/**
 * Struct Definition
 * @struct Stock
 * @brief A struct to store the valid data related to date-exchange content of the file
*/
struct Stock
{
    int day;
    int month;
    int year;
    float ex_rate;
};

/**
 * Class Definition
 * @class Checker
 * @brief Checker class to check the content and availability any file passed as argument
 * @param _valid a Stock struct to store the valid data related to date-exchange content of the file
 * @throws std::runtime_error if the file is not available or the content is not valid
 * 
 * More details about the class
*/
class Checker
{
    private:
        /**
         * Utils Members Functions
         * @brief Functions help to implement the logic of the Checker class
        */
        bool IsLeapYear(int year); // used by IsValidDate()
        bool IsValidDate(int day, int month, int year); //used by ckDate()
        void ckDate(std::string &line, const char separator); //used by ckFormat()
        void ckValue(std::string &line, const char separator, bool maxValue); //used by ckFormat()
        std::string &clearStr(std::string &str); //used by ckDate and ckValue()
        std::string formatDate(); //used by MakeValidPair()

    protected:
        /**
         * @typedef ValidPair
         * @brief Defines an alias for a pair of string and float.
         * 
         * Simplifies subsequent references to this data type.
         */
        typedef std::pair<std::string, float> ValidPair;
        //TODO - VERIFICAR O USO DO CONSTRUCTOR NO PROTECTED
        /**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
        Checker();
        Checker(const Checker& src);
        Checker& operator=(const Checker& src);
        ~Checker();
        
        /**
         * Additional Member Functions
         * @brief Includes member functions to implement the SOLID logic
        */
        void ckFirstLine(const std::string &line, const std::string firstLine); //used by BitcoinDataBase constructor 
        void ckFormat(std::string line, const char separator, bool maxValue); //used by BitcoinDataBase and BitcoinExchange
        void ckOpenFile(std::ios& file); //used by BitcoinDataBase and BitcoinExchange
        ValidPair makeValidPair(); //used by BitcoinDataBase and BitcoinExchange
        
        /**
         * @struct Stock
         * @brief A struct to store the valid data related to date-exchange content of the file
        */
        Stock _valid;
};

#endif
