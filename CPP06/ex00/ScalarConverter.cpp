/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:48 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:02:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"


/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/** Default Constructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
ScalarConverter::ScalarConverter(){/*std::cout << BKGRAY "[Scalar] Default Constructor called" RESET << std::endl;*/}

/** Copy Constructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
ScalarConverter::ScalarConverter(const ScalarConverter &src){(void)src;/*std::cout << BKGRAY "[Scalar] Copy constructor called" RESET << std::endl;*/}

/** Copy assignment operator
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){(void)src;/*std::cout << BKGRAY "[Scalar] Copy assignment operator called" << RESET << std::endl;*/return (*this);}

/** Destructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
ScalarConverter::~ScalarConverter(){/*std::cout << BKGRAY "[Scalar] Destructor called" RESET << std::endl;*/}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/** Convert
 * @brief This function classifies an input in types (char,int, float or doubles)
 *       and converts this to all others types (char, int, float and double)
 * @param input - the input to be converted
 * @warning This function is static and can be called without instanciating the class
 * @warning This function is public and can be called by users by the signature ScalarConverter::convert(input)
 * @warning the CHAR type is treated differently from the others, because the strold() function does not convert a char to a long double
 *          so i did the explicit typecast conversion by using the static_cast
 * 
 * @note the input will be interpreted as a char, int, float or double considering the following rules:
 *       - if the input is a single character, it will be interpreted as a char
 *       - if the input is a digital, it will be interpreted as an int, float or double
 *       - if the input is a pseudo number, it will be interpreted as pseudo
 * @note The logic behind this function is transforming any data into the largest data type possible (scalable types)
 *        and then converting it to the other data types, always checking the limits of each data types before printing
 * @note Was used an fall-through switch case to avoid code repetition.
 * 
 * @see typeInput() and typeNumb() functions below for more information
 * 
 * @note the std::strtold() could be replaced by std::stold(input) for C++11
 * @note the std::strtold() is a C-style function that converts a string to a long double like std::stold()
 * @note the std::strtold() is defined in the header <cstdlib>
 * @note the std::strtold() is used to ignore the alphabetic characters after the digits caracters in the input EXEMPLE: "123a" will be converted to 123
 * @note the std::strtold() return 0 if the first non-whitespace character is not a part of the set of characters: [+-][0-9]*[.][0-9]*[f] EXEMPLE: "a123" will be converted to 0
 * @note the std::strtold() has the following signature:
 *      long double strtold(const char* str, char** endptr, int base);
 *      - str: the string to convert, has to be null-terminated
 *      - endptr: a pointer to the character that stops the conversion
 *      - base: the base of the number (example: 10 for decimal, 16 for hexadecimal, etc...)
 */
void ScalarConverter::convert(std::string &input)
{
    _Input type = typeInput(input); //checks the type of the input
    long double numb = std::strtold(input.c_str(), NULL);  //converts the string until NULL to a long double
    
    print_t(type); //prints flag with type of the input as message
    switch (type)
    {
        case _PSEUDO:
            printPseudo(input); //try transforms the pseudo number to float and double
            break;
        case _ERROR:
            printError(numb); //prints flag with type ERROR as message
            break;
        case _CHAR:
            numb = static_cast<long double>(input[0]); //typecasts just the first character to long double
            
            //DEPRECATED BY FALL-THROUGH SWITCH CASE
            /* printChar(numb, input[0]);
            printInt(numb, static_cast<int>(input[0]));
            printFloat(numb, static_cast<float>(input[0]));
            printDouble(numb, static_cast<double>(input[0])); */
        default:
            printChar(numb, static_cast<char>(numb)); //try transforms the long double value of input to char
            printInt(numb, static_cast<int>(numb)); //try transforms the long double value of input to int
            printFloat(numb, static_cast<float>(numb)); //try transforms the long double value of input to float
            printDouble(numb, static_cast<double>(numb)); //try transforms the long double value of input to double
            break;
    }
}

/**!SECTION
 * ****************
 * SECTION - UTILS 
 * ****************
*/

/** SECTION - PRINT FUNCTIONS
 * @brief This function prints the type of the input as a flag message according to the type passed as parameter
 * @param t - the type of the input defined by the _Input ENUM 
 * 
 * @see mColors.hpp for ENUM more information
 */
static void print_t(_Input t)
{
    std::cout << CYAN "<<< ";
    switch (t)
    {
    case _CHAR:
        std::cout << "CHAR";
        break;
    case _INT:
        std::cout << "INT";
        break;
    case _FLOAT:
        std::cout << "FLOAT";
        break;
    case _DOUBLE:
        std::cout << "DOUBLE";
        break;
    case _PSEUDO:
        std::cout << "PSEUDO";
        break;
    default:
        std::cout << "ERROR";
        break;
    }
    std::cout << " >>>" RESET << std::endl;
}

/** 
 * @brief This function prints the error message for all types of should the input be converted
 * @param[out] data a long double that represents the input to be converted
 * 
 * @note This function is called when the input is not valid as a char, int, float or double
 * @note the parameter data is not used, but still there to avoid warnings of unused variables in this case (type==_ERROR)
 * 
 * @see mColors.hpp for ENUM more information
 */
static void printError(const long double &data)
{
    (void)data;
    std::cout << "char: " << RED "-----error-----" RESET << std::endl;
    std::cout << "int: " << RED "-----error-----" RESET << std::endl;
    std::cout << "float: " << RED "-----error-----" RESET << std::endl;
    std::cout << "double: " << RED "-----error-----" RESET << std::endl;
}

/** 
 * @brief This function prints the input as a int, if the value is between the limits of a char
 * @param[out] data a long double that represents the value of the input (scalable type) to be compared and converted/printed
 * @param c the char that was converted from long double to be printed
 * 
 * @warning This function calls the limitsInput() function to check if "long double data" is between the limits of "char c"
 * @warning the data could be transformed to 'char c' and dont be an characater printed 
 *          like any between 0 and 31 or 127 to this cases the function isprint() 
 *          is used to check if the character is printable
 * 
 * @note the idea of passing both (long double and char) is to compare the limits 
 *       of the 'long double data' with the limits of the 'char c' through the function limitsInput()
 * @note the data is aready transformed to 'char c' trough the static_cast called in convert() function
 * @see mColors.hpp for ENUM more information
 */
static void printChar(const long double &data, char c)
{
    std::cout << "char: ";
    if (limitsInput(_CHAR, data))
    {
        if (isprint(c))
            std::cout << "'" GREEN << c << RESET "'" << std::endl;
        else
            std::cout << YELLOW "Non displayable" RESET << std::endl;
    }
    else
        std::cout << RED "Overload" RESET << std::endl;
}

/** 
 * @brief This function prints the input as a int, if the value is between the limits of a int
 * @param[out] data a long double that represents the value of the input (scalable type) to be compared and converted/printed
 * @param n the int that was converted from long double to be printed
 * 
 * @warning This function calls the limitsInput() function to check if "long double data" is between the limits of "int n"
 * 
 * @note the idea of passing both (long double and int) is to compare the limits 
 *       of the 'long double data' with the limits of the 'int n' through the function limitsInput()
 * @note the data is aready transformed to 'int n' trough the static_cast called in convert() function
 * @see mColors.hpp for ENUM more information
 */
static void printInt(const long double &data, int n)
{
    std::cout << "int: ";
    if (limitsInput(_INT, data))
        std::cout << n << std::endl;
    else
        std::cout << RED "Overload" RESET << std::endl;
}

/** 
 * @brief This function prints the input as a float, if the value is between the limits of a float
 * @param[out] data a long double that represents the value of the input (scalable type) to be compared and converted/printed
 * @param n the float that was converted from long double to be printed
 * 
 * @warning This function calls the limitsInput() function to check if "long double data" is between the limits of "float n"
 * 
 * @note the idea of passing both (long double and float) is to compare the limits 
 *       of the 'long double data' with the limits of the 'float n' through the function limitsInput()
 * @note the data is aready transformed to 'float n' trough the static_cast called in convert() function
 * 
 * @see mColors.hpp for ENUM more information
 */
static void printFloat(const long double &data, float n)
{
    std::cout << "float: ";
    if (limitsInput(_FLOAT, data))
    {
        if (n == std::floor(n))
            std::cout << n << ".0f" << std::endl;
        else
            std::cout << n << "f" << std::endl;
    }
    else /* if (std::isinf(static_cast<float>(n)) || std::isnan(static_cast<float>(n))) */
        std::cout << RED "Overload" RESET << std::endl;
}

/** 
 * @brief This function prints the input as a double, if the value is between the limits of a double
 * @param[out] data a long double that represents the value of the input (scalable type) to be compared and converted/printed
 * @param n the double that was converted from long double to be printed
 * 
 * @warning This function calls the limitsInput() function to check if "long double data" is between the limits of "double n"
 * 
 * @note the idea of passing both (long double and double) is to compare the limits 
 *       of the 'long double data' with the limits of the 'double n' through the function limitsInput()
 * @note the data is aready transformed to 'double n' trough the static_cast called in convert() function
 * @see mColors.hpp for ENUM more information
 */
static void printDouble(const long double &data, double n)
{
    std::cout << "double: ";
    if (limitsInput(_DOUBLE, data))
    {
        if (n == std::floor(n))
            std::cout << n << ".0" << std::endl;
        else
            std::cout << n << std::endl;
    }
    else /* if (std::isinf(static_cast<double>(n)) || std::isnan(static_cast<double>(n))) */
        std::cout << RED "Overload" RESET << std::endl;
}
/** 
 * @brief This function are called when the input is a pseudo number, and print the input transformed to float and double
 * @param[out] input a string that represents the input pseudo to be converted
 * 
 * @warning This function calls the typePseudo() function to check if the input is a pseudo is a float or a double
 * 
 * @note the psedo number never fits in a char or int, so the print of these types are impossible
 * @note the logic is that "inf" or "nan" are pseudo numbers and
 *       they could be represented with an 'f' at the end to be a float, or without 'f' to be a double
 * @note to solve the question with extra 'f' to representes an float pseudo number and
 *       following the results of typePseudo() function: 
 *        - When is an PseudoFloat: the last 'f' character is removed to print/transform the double version
 *        - When is an PseudoDouble: is added an 'f' character to print/transform the float version
 * 
 * @see mColors.hpp for ENUM more information
 */
static void printPseudo(std::string &input)
{
    _Input f = typePseudo(input);
    std::cout << "char: " << RED "impossible" RESET << std::endl;
    std::cout << "int: " << RED "impossible" RESET << std::endl;
    if (f == _FLOAT)
    {
        std::cout << "float: " << input << std::endl;
        input.erase(input.end() - 1);
        std::cout << "double: " << input << std::endl;
    }
    else if (f == _DOUBLE)
    {
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
}

/** SECTION - LEXER FUNCTIONS
 * @brief Checks if the input is a pseudo float or double, or an error
 * @param[out] input a string that represents the input to be checked
 * @return the type of the input as a _Input ENUM
 * 
 * @warning this function is called by the printPseudo() function 
 * @warning the logic to determine the type of the input is:
 *          - if the input have a "nan" acompanied by a 'f',
 *            or if have a "inf" and a "ff" too, so is a float EXEMPLE: (nanf),(inff),(+inff),(-inff)
 *          - if the input have a "nan" without a 'f',
 *            or if have a "inf" without a "ff" too, so is a double EXEMPLE: (nan),(inf),(+inf),(-inf)
 *
 * @note this function use the bool flags that are setted as true if the input have an sub-string like below:
 *       - hDF: checks if the input string have the sub-string "ff"
 *       - hF: checks if the input string have the caracter 'f'
 *       - nan: checks if the input string have the sub-string "nan"
 *       - inf: checks if the input string have the sub-string "inf"
 * @note the find() method search for the substring passed as parameter in the object string that calls the method
 * 
 * @see mColors.hpp for ENUM more information
 */
static _Input typePseudo(std::string &input)
{
    bool hDF = input.find("ff") != std::string::npos;
    bool hF = input.find('f') != std::string::npos;
    bool nan = input.find("nan") != std::string::npos;
    bool inf = input.find("inf") != std::string::npos;

    if ((nan && hF) || (inf && hDF))
        return _FLOAT;
    if ((nan && !hF) || (inf && !hDF))
        return _DOUBLE;
    else
        return _ERROR;
}

/**
 * @brief Check the type of the input and return the _Input type
 * @param[out] input a string that represents the input to be checked
 * @return the type of the input as a _Input ENUM
 * 
 * @warning first checks if the input is empty, if it is, returns _ERROR
 * @warning Then if the input is a single character and this char isnt an digit, returns _CHAR
 * @warning Then if the input is compose by chars represented by any of the "-+0123456789.f" string, 
 *          so call the typeNumb() function to checks what type of number is it.
 * @warning if the input dont fit in any of the above cases, 
 *          checks if the input type is a pseudo number calling the typePseudoOrError() function
 * 
 * @see mColors.hpp for ENUM more information
 */
static _Input typeInput(std::string &input)
{
    if (input.empty())
        return _ERROR;
    if (input.length() == 1 && !isdigit(input[0]))
        return  _CHAR;
    if (input.find_first_not_of("-+0123456789.f") == std::string::npos)
        return (typeNumb(input));
    else
        return (typePseudoOrError(input));
}

/** 
 * @brief check if the input is a pseudo number (nan, nanf, inf, inff, +inf, +inff, -inf, -inff) or an error
 * @param[out] input string that represents the input to be checked
 * @return the type of the input as a _Input ENUM
 * 
 * @note as the function was called in else of the typeInput() function, 
 *      then must to checks for errors too, bc until now just was error if the input was empty
 * 
 * @see mColors.hpp for ENUM more information
 */
static _Input typePseudoOrError(std::string &input)
{
    if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
        return _PSEUDO;
    else
        return _ERROR;
}

/** 
 * @brief check if the input is a number (int, float or double) or an error
 * @param[out] input string that represents the input to be checked
 * @return the type of the input as a _Input ENUM
 * 
 * @warning This function calls the ErrorInput() function to check if the 
 *          especials caracteristics ("+-.f") of the input are on the right place,
 *          otherwise returns _ERROR
 * 
 * @warning the logic to special characters is:
 *          - if the input have a dot and a 'f' and the dot is not glued to the 'f', so is a float
 *          - if the input have a dot and dont have a 'f', so is a double
 *          - if the input dont have a dot and a 'f', so is an int
 * 
 * @note The dot cannot be in the end or begin of the input, checks in ErrorInput()function
 * 
 * @note this function use the bool flags that are setted as true if the input have at least one of this specials caracteristics:
 *       - hSig: checks if some char in input was find like '-' or '+'
 *       - hDot: checks if some char in input was find like '.'
 *       - hF: checks if some char in input was find like 'f'
 * 
 * @see mColors.hpp for ENUM more information, and ErrorInput() function 
 */
static _Input typeNumb(std::string &input)
{
    bool hSig = input.find_first_of("-+") != std::string::npos; 
    bool hDot = input.find('.') != std::string::npos;
    bool hF = input.find('f') != std::string::npos;
    
    if (ErrorInput(input, hSig, hDot, hF)) //signals place tratament
        return _ERROR;
    if (!hDot && !hF) //if dont have a dot and a 'f'
        return _INT;
    if (hDot && !hF) //if have a dot and dont have a 'f'
        return _DOUBLE;
    if (hDot && hF && input.find('.') < input.length() - 2) //if have a dot and a 'f', and if the dot is not glued to the 'f'
        return _FLOAT;
    else //otherwhise is an error
        return _ERROR;
}

/** 
 * @brief check if the special characters of the input are in the wrong place, otherwise returns false
 * @param[out] input string that represents the input to be checked
 * @param[in] hSig bool flag that represents if the input have a signal
 * @param[in] hDot bool flag that represents if the input have a dot
 * @param[in] hF bool flag that represents if the input have a 'f'
 * @return bool set as true if the input have some special caracteristics in the wrong place
 * 
 * @warning the logic to special characters is:
 *          - if the input have a signal and have more than one signal, 
 *             or the signal is not in the begin of the input, so returns true to error EXEMPLE: (--1) or (1-) or (1+1) etc
 *          - if the input have a 'f' and have more than one 'f',
 *            or the 'f' is not in the end of the input, so returns true to error EXEMPLE: (ff) or (f.f) or (f1f) etc
 *          - if the input have a dot and have more than one dot,
 *            or the dot is in the end or begin of the input, so returns true to error EXEMPLE: (.1) or (1.) or (..1) or (1.0.) etc
 *          - if the input have a signal and a dot, 
 *            and the dot is in the second place, so returns true to error EXEMPLE: (-.1) or (+.1)
 *          - otherwise returns false to error
 * 
 * @see mColors.hpp for ENUM more information
 */
static bool ErrorInput(std::string &input, bool hSig, bool hDot, bool hF)
{
    if (hSig && (input.find_first_of("-+") != input.find_last_of("-+") || input.find_first_of("-+") != 0))
        return true;
    if (hF && (input.find_first_of('f') != input.find_last_of('f') || input[input.length() - 1] != 'f'))
        return true;
    if (hDot && (input.find_first_of('.') != input.find_last_of('.') || input[input.length() - 1] == '.' || input[0] == '.'))
        return true;
    if (hSig && hDot && input.find('.') == 1)
        return true;
    else    
        return false;
}

/** !SECTION
 * SECTION - LIMITS FUNCTIONS
 * @brief This function checks if the input is between the limits of the typeToCheck
 * @param[out] typeToCheck the type of the input data defined by the _Input ENUM that sets the limits to be checked
 * @param[out] numb a long double that represents the value of the input (scalable type) to be compared
 * @return bool set as true if the input is between the limits of the typeToCheck
*/
static bool limitsInput(_Input typeToCheck, const long double &numb)
{
    switch (typeToCheck)
    {
        case _CHAR:
            return (numb >= std::numeric_limits<char>::min() && numb <= std::numeric_limits<char>::max());
        case _INT:
            return (numb >= std::numeric_limits<int>::min() && numb <= std::numeric_limits<int>::max());
        case _FLOAT:
            return (numb >= -std::numeric_limits<float>::max()  && numb <= std::numeric_limits<float>::max());
        case _DOUBLE:
            return (numb >= -std::numeric_limits<double>::max() && numb <= std::numeric_limits<double>::max());
        default:    
            return false;
    }
}






















