/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/25 10:47:29 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"

//CANONICAL FORM
Checker::Checker() : _valid()
{
    _valid.day = 0;
    _valid.month = 0;
    _valid.year = 0;
    _valid.ex_rate = 0;
}
Checker::Checker(const Checker& src){(void)src;};
Checker& Checker::operator=(const Checker& src){(void)src; return (*this);};
Checker::~Checker(){};


//UTILS TO CHECK FUNCTIONS
static bool IsLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool IsValidDate(int day, int month, int year)
{
    if (year < 1 || month < 1 || day < 1 || month > 12 || year > 2024)
        return false;
    
    size_t mIndex = month - 1;
    int maxDaysperM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && IsLeapYear(year))
    {
        maxDaysperM[mIndex] = 29;
    }
    return (day >= 1 && day <= maxDaysperM[mIndex]);
}

std::string &Checker::clearStr(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    return (str);
}

//CHECKER FUNCTIONS

void Checker::ckOpenFile(std::ios& file)
{
	if (!file)
		throw (std::runtime_error("Fatal Error: Cannot open the file\n"));
}

void Checker::ckFirstLine(const std::string &line, const std::string firstLine)
{
    if (line != firstLine) //verifica conteúdo inicial do file
        throw (std::runtime_error("Format Error: Invalid first line instruction\n"));
}

void Checker::ckDate(std::string &line, const char separator)
{
    //int year, month, day;
    char hyphen1, hyphen2;
    size_t i_del = line.find(separator);
    std::string Cdate = line.substr(0, i_del);
    Cdate = clearStr(Cdate);
    std::istringstream ssdate(Cdate);
    
    ssdate >> _valid.year;
    ssdate >> hyphen1;
    ssdate >> _valid.month;
    ssdate >> hyphen2;
    ssdate >> _valid.day;

    if(ssdate.fail() || ssdate.bad() || !ssdate.eof() || hyphen1 != '-' || hyphen2 != '-')
        throw (std::runtime_error("Format Error: Invalid DATE format\n"));
    if (!IsValidDate(_valid.day, _valid.month, _valid.year))
        throw (std::runtime_error("Value Error: Invalid value to DATE\n"));
}

void Checker::ckValue(std::string &line, const char separator, bool maxValue)
{
    size_t i_del = line.find(separator);
    std::string Cvalue = line.substr(i_del + 1);
    Cvalue = clearStr(Cvalue);
    std::istringstream ssvalue(Cvalue);

    ssvalue >> _valid.ex_rate;

    if(ssvalue.fail() || ssvalue.bad() || !ssvalue.eof())
        throw (std::runtime_error("Format Error: Invalid EXCHANGE format\n"));
    if (_valid.ex_rate < 0 || (maxValue && _valid.ex_rate > 1000))
        throw (std::runtime_error("Value Error: Invalid value to EXCHANGE\n"));
}

void Checker::ckFormat(std::string line, const char separator, bool maxValue)
{
    bool hasSep = line.find(separator) != std::string::npos && \
    line.find_first_of(separator) == line.find_last_of(separator);
    
    if (hasSep)
    {
        ckDate(line, separator);
        ckValue(line, separator, maxValue);
    }
    else
        throw (std::runtime_error("Format Error: Invalid INPUT format\n"));
}

std::string Checker::formatDate()
{
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << _valid.year << "-"
        << std::setw(2) << std::setfill('0') << _valid.month << "-"
        << std::setw(2) << std::setfill('0') << _valid.day;
    return (oss.str());
}

Checker::ValidPair Checker::makeValidPair()
{
    return (make_pair(formatDate(), _valid.ex_rate));
}


/**
 * @deprecated This function is not used in the final version of the program, because requires c++11
 * @brief Check if the date is in the correct format YYYY-MM-DD
 * @param line is an input string partitioned by the separator pipe '|' or comma ',' to be checked
 * @return true if the date is in the correct format, false otherwise
 * 
 * @warning This function uses the <regex> library to check the format of the date
 * @see https://en.cppreference.com/w/cpp/regex
 * 
 * @note regex stands for 'regular expression', a sequence of characters that define a search pattern
 * @note regex could be used to search, replace, and manipulate strings, is a powerful tool for text processing
 * @note the "^\\d{4}-\\d{2}-\\d{2}" is a regex pattern that matches the date in the format YYYY-MM-DD
 * @note the continuation ",\\d+(\\.\\d+)?$" is a regex pattern that matches the float number in the format XXXX.XX or XXXX
 * @note to declare a regex object, in this case, we pass the pattern as a string to the constructor
 *       '^' -> indicates the start of the string
 *       '$' -> indicates the end of the string
 *      '\d' -> indicates that could be fill by any decimal digit EXEMPLE: the range [0-9]
 *      '{N}' -> indicates that has to be fill with N repetitions of the previous character EXEMPLE: 'dddd'
 *       '-'  -> indicates that has to be fill with the character '-' explicitly EXEMPLE: dddd'-'dd'-'dd
 *       ','  -> indicates that has to be fill with the character ',' explicitly EXEMPLE: dddd'-'dd'-'dd', ...
 *       '+'  -> indicates that has to be fill with ONE or MORE repetitions of the previous character EXEMPLE: 'd', 'dd', 'ddd', 'dddd', ...
 *       '?'  -> indicates that has to be fill with ZERO or ONE repetitions of the previous character EXEMPLE: with '.' or without ''
 *       '()' -> indicates the a capture optional group that could be filled EXEMPLE: dd'.d' or dd
 *       '.'  -> indicates that has to be filled with the character '.' explicitly EXEMPLE: dd'.'d 
 * 
 * @note the expression "\\d+(\\.\\d+)?" means that the number could be an integer or a float EXEMPLE: 1234 or 1234.00
 * @note so the part of the expression (\\.\\d+)?  is a optional group that just appears together 
 * @note the '\d' was defined with scape character '\' to avoid the conflict with the C++ escape characters
*/
/* bool BitcoinExchange::ckFormat(std::string line, const std::string format)
{
    std::regex stdFormat(format); //defining the format of the date
    return (std::regex_match(line, stdFormat)); //checking if the date is in the correct format
} */