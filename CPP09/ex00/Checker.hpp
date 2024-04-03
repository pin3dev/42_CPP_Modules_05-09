/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/02 22:20:16 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <algorithm> //to std::find
#include <utility> //to std::pair
#include <iostream> //to std::cout, std::cin, std::endl
#include <iomanip> //to std::setw, std::setfill
#include <exception> //to exception class
#include <fstream> //to std::ifstream, std::ofstream, etc
#include <sstream> //to std::stringstream
#include <string> //to std::string, std::getline
#include <map> //to std::map

struct Stock
{
    int day;
    int month;
    int year;
    float ex_rate;
};

class Checker
{
    private:
        bool IsLeapYear(int year);
        bool IsValidDate(int day, int month, int year);
        void ckDate(std::string &line, const char separator); //used by ckFormat
        void ckValue(std::string &line, const char separator, bool maxValue); //used by ckFormat
        std::string &clearStr(std::string &str); //used by ckDate and ckValue
        std::string formatDate(); //used by BitcoinDataBase and BitcoinExchange

    protected:
        typedef std::pair<std::string, float> ValidPair;
        //CANONNICAL FORM
        Checker();
        Checker(const Checker& src);
        Checker& operator=(const Checker& src);
        ~Checker();
        
        //METHODS
        void ckFirstLine(const std::string &line, const std::string firstLine); //used by BitcoinDataBase constructor 
        void ckFormat(std::string line, const char separator, bool maxValue); //used by BitcoinDataBase and BitcoinExchange
        void ckOpenFile(std::ios& file); //used by BitcoinDataBase and BitcoinExchange
        ValidPair makeValidPair(); //used by BitcoinDataBase and BitcoinExchange
        
        //ATTRIBUTES
        Stock _valid; //used by Checker 
};

#endif
