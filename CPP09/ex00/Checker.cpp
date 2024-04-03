/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/03 16:23:13 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/
/**
 * Default constructor
 * @brief Initialize the Checker object and the Struct Stock calling the default constructor
 *        And sets the default values to Stock atributes       
 *        The default values are 0 for day, month, year, and ex_rate
*/
Checker::Checker() : _valid()
{
    _valid.day = 0;
    _valid.month = 0;
    _valid.year = 0;
    _valid.ex_rate = 0;
}
/**
 * Copy Constructor
 * @deprecated Copy constructor is not used in this class, just exists to fill the requirements of Canonical Form
 * @param[out] src an const reference to the instance to be copied, it is ignored
 */
Checker::Checker(const Checker& src){(void)src;};

/**
 * Copy Assignment Operator
 * @deprecated Copy assignment operator is not used in this class, just exists to fill the requirements of Canonical Form
 * @param[out] src an const reference to the instance to be copied, it is ignored
 * @return Checker& a reference to the instance Checker
 */
Checker& Checker::operator=(const Checker& src){(void)src; return (*this);};

/**
 * Destructor
 * @brief Destroy the Checker object
 * 
 * @note The default destructor is enough to destroy the Checker object and the Struct Stock
 *       because the none of thoses objects have any dynamic memory allocation
*/
Checker::~Checker(){};

/** !SECTION 
 * ****************
 * SECTION - UTILS 
 * ****************
*/
/**
 * @brief Check if the year is a leap year
 * @param year is an integer that represents the year to be checked
 * @return true if the year is a leap year, false otherwise
 * 
 * @note A leap year is a year that is exactly divisible by 4 except for years that are exactly divisible by 100
 *       The years that are exactly divisible by 100 are leap years only if they are exactly divisible by 400
 *       EXEMPLE: 2000 is a leap year, but 1700, 1800, and 1900 are not leap years
 * @note calculating from 0 year, the leap years are 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, ...
 *       so the leap years are multiples of 4, but not multiples of 100, except multiples of 400
*/
bool Checker::IsLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
/**
 * @brief Check if the date is valid considering the day, month, and year
 * @param day is an integer that represents the day to be checked
 * @param month is an integer that represents the month to be checked
 * @param year is an integer that represents the year to be checked
 * @return true if the date is valid, false otherwise
 * 
 * @warning if the year is less than 1 or greater than 2024, or
 *          if the month is less than 1 or greater than 12, or
 *          if the day is less than 1 or greater than the maximum days of the month
 *          the function returns false
 * @warning the mIndex is the index of the month in the array maxDaysperM
 * @warning the maxDaysperM is an array that stores the maximum days of each month
 * @warning the maxDaysperM[1] is 28, but if the year is a leap year, the maxDaysperM[1] is 29
 *          and this is the max number of days in February
 * @warning if the day is between 1 and the maxDaysperM[mIndex] the function returns true
 * @note This function checks values stored in the struct Stock by ckDate() method
*/
bool Checker::IsValidDate(int day, int month, int year)
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
/**
 * @brief Format the date in the format YYYY-MM-DD with the values stored in the struct Stock
 *        and concatenate the values in a string
 * @return a string with the date in the format YYYY-MM-DD 
 * 
 * @warning the data used to format the date is stored in the struct Stock
 * 
 * @note This function not need any parameter because the values are stored in the struct Stock
 *       when the ckDate() method is called, after that the values are checked by IsValidDate() method
*/
std::string Checker::formatDate()
{
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << _valid.year << "-"
        << std::setw(2) << std::setfill('0') << _valid.month << "-"
        << std::setw(2) << std::setfill('0') << _valid.day;
    return (oss.str());
}
/**
 * @brief Remove the white spaces from a string
 * @param str is a reference to the string to be cleaned
 * @return a reference to the string cleaned
 * 
 * @note This function uses the std::remove_if() algorithm to remove the white spaces from the string
 * @note The std::remove_if() algorithm is used to remove elements from a container that satisfy a condition
 * @note The std::isspace() function is used to check if the character is a white space
 * @note The std::erase() method is used to remove the elements from the container
 * @note The std::erase() method receives two iterators, the first is the beginning of the range to be removed
 *       and the second is the end of the range to be removed
 * @note The std::erase() method returns an iterator to the element that follows the last element removed
 * @note The std::erase() method is used to remove the elements from the container
 * @note The std::erase() method is used to remove the elements from the container
 * 
 * 
 * TODO - DOCUMENTAR ISSO AQUI 
 * 
 * 
*/
std::string &Checker::clearStr(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    return (str);
}
/**
 * @brief Check the date in the format Y-M-D
 * @param line is an input string partitioned by the separator pipe '|' or comma ',' to be checked
 * @param separator is a char that represents the separator used to split the string, could be '|' or ','
 * @throws std::runtime_error if the date is not in the correct format
 * 
 * @warning This function uses a string, transform it to a std::istringstream 
 *          and uses the std::istringstream to convert the string to the integer values
 *          by the overloaded operator '>>'
 * 
 * @warning Many variables are used to store the values to help the conversion, like:
 *          - hyphen1 and hyphen2 to store the hyphens
 *          - i_del to store the index of the separator
 *          - Cdate to store the first part of the string before the separator, that represents the date
 *          - ssdate to store the std::istringstream to convert the string into integers and hyphens and checks
 * 
 * @warning if the conversion suceeds, the values of date (e.g. day, month, year)
 *          are stored in the struct Stock as integers
 * 
 * @note the stored values just needs to be in the correct format, but
 *       the values are checked by the IsValidDate() method once the conversion is done and
 *       the values are stored in the struct Stock
 * 
 * @note The conversion try to convert the 'line' into 'int', and this will be done
 *       while the content are numbers, if the content is not a number the conversion stops, 
 *       and so, trys to convert the content to the next variable, in this case, the hyphen,
 *       so the 'line' has to be in the format 'int'-'int'-'int' to be converted correctly, otherwise
 *       the conversion will fail
 * @note The std::istringstream is a stream class to operate on strings as if they were input streams
 * @note the std::istringstream has methods to check if the conversion was successful, like fail(), bad(), and eof()
 * 
*/
void Checker::ckDate(std::string &line, const char separator)
{
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

/**
 * @brief Check the value in the format XXXX.XX or XXXX
 * @param line is an input string partitioned by the separator pipe '|' or comma ',' to be checked
 * @param separator is a char that represents the separator used to split the string, could be '|' or ','
 * @param maxValue is a boolean that represents if the value has to be checked as a maximum value
 * @throws std::runtime_error if the value is not in the correct format
 * 
 * @warning This function uses a string, transform it to a std::istringstream 
 *          and uses the std::istringstream to convert the string to the integer values
 *          by the overloaded operator '>>'
 * 
 * @warning Many variables are used to store the values to help the conversion, like:
 *          - i_del to store the index of the separator
 *          - Cvalue to store the second part of the string after the separator, that represents the value
 *          - ssvalue to store the std::istringstream to convert the string into integers and checks
 * 
 * @warning if the conversion suceeds, the values of ex_rate
 *          are stored in the struct Stock as float
 * 
 * @note the stored values just needs to be in the correct format, and
 *       the values are checked if the bool maxValue is true, the value has to be between 0 and 1000
 *       and this is checked in case of checking input file values
 * 
 * @note The conversion try to convert the 'line' into 'float'
 * @note The std::istringstream is a stream class to operate on strings as if they were input streams
 * @note the std::istringstream has methods to check if the conversion was successful, like fail(), bad(), and eof()
*/
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

/** !SECTION 
 * **************************
 * SECTION - PUBLIC METHODS
 * **************************
*/

/**
 * @brief Check if the file is open
 * @param file is a reference to the file to be checked
 * @throws std::runtime_error if the file is not open
*/
void Checker::ckOpenFile(std::ios& file)
{
	if (!file)
		throw (std::runtime_error("Fatal Error: Cannot open the file\n"));
}
/**
 * @brief Check the first line of a file
 * @param line is an input string to be checked
 * @param firstLine is a string that represents the first line of the file
 * @throws std::runtime_error if the first line is not the expected
*/
void Checker::ckFirstLine(const std::string &line, const std::string firstLine)
{
    if (line != firstLine) //verifica conteúdo inicial do file
        throw (std::runtime_error("Format Error: Invalid first line instruction\n"));
}
/**
 * @brief Check the format of the input string
 * @param line is an input string partitioned by the separator pipe '|' or comma ',' to be checked
 * @param separator is a char that represents the separator used to split the string, could be '|' or ','
 * @param maxValue is a boolean that represents if the value has to be checked as a maximum value
 * @throws std::runtime_error if the format is not correct
 * 
 * @warning This function uses the ckDate() and ckValue() methods to check the date and the value
 *         and the values are stored in the struct Stock
 * @warning The bool hasSep is used to check if the separator is in the string 
 *          and if the separator is the only one in the string
*/
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

/**
 * @brief Make a pair with the date and the exchange rate stored in the struct Stock
 * @return a pair type std::pair<std::string, float> with the date and the exchange rate
 * 
 * @note this pair will be used to search the date (key) in the map of the BitcoinDataBase
 *        and compare the exchange rate (value) with the exchange rate stored in the map
*/
Checker::ValidPair Checker::makeValidPair()
{
    return (make_pair(formatDate(), _valid.ex_rate));
}


/** !SECTION 
 * **********************
 * SECTION - DEPRECATED
 * **********************
*/
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