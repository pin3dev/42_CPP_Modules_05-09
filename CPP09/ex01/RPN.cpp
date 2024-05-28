/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:45 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/28 15:59:25 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Static stack to store the numbers and the result of the operations
 * 
 * @note Initialized as empty stack, because the stack is static and has to be
 *      initialized outside the class
*/
std::stack<double>   RPN::_RPNorg;

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/
/**
 * Default constructor
 * @deprecated Default constructor is not used in this class, just exists to fill the requirements of Canonical Form
 */
RPN::RPN(){}
/**
 * Copy constructor
 * @deprecated Copy constructor is not used in this class, just exists to fill the requirements of Canonical Form
*/
RPN::RPN(RPN const& src){(void)src;}
/**
 * Copy assignment operator
 * @deprecated Copy assignment operator is not used in this class, just exists to fill the requirements of Canonical Form
*/
RPN& RPN::operator=(RPN const& src){(void)src;return (*this);}
/**
 * Destructor
 * @deprecated Destructor is not used in this class, just exists to fill the requirements of Canonical Form
*/
RPN::~RPN(){}

/** !SECTION 
 * *******************************
 * SECTION - PUBLIC STATIC METHOD
 * *******************************
*/
/**
 * @brief This function is the main function of the class,
 *        it will take a string as input and will process it
 *        to calculate the result of the Reverse Polish Notation (RPN)
 * @param input The string to process
 * @throw std::runtime_error If the operator is invalid or if the notation is invalid
 * 
 * @note This function uses a stack to store the numbers and the result of the operations
 *       because the RPN is a stack-based notation
 *  
 * @warning The 'input' string is transformed into a stream of strings to be processed by spliting
 *          the original string into tokens by spaces, and stored in variable 'token', string by string
 *          EXAMPLE: "5 3 +" => token = "5", token = "3", token = "+"
 * @warning This function uses the 'tokenType', ´do_op´ and 'displayRes' functions to help the on the logic
 *         of the RPN calculation
 * @warning The type 'token' is an enum that helps to identify the type of the token, if it is a number, an operator or an error
 * @see RPN.hpp for more information
 * 
 * @note The function iterates over the tokens and checks if it is a number or an operator,
 *       if it is a number, it will push it into the _RPNorg stack,
 *       and if it is an operator, it will pop the last two numbers from the stack and apply the operation
 *       so, in the logic, the _RPNorg stack will always have at least two numbers to apply the operation,
 *       and the result will be pushed back into the stack, until the end of the tokens
 *       EXAMPLE: 
 *       [EXAMPLE 01] "5 3 +" => _RPNorg = [5, 3] > 5 + 3 => _RPNorg = [8]
 *       [EXAMPLE 02] "5 3 + 2 *" => _RPNorg = [5, 3] > 5 + 3 => _RPNorg = [8] => _RPNorg = [8, 2] > 8 * 2 => _RPNorg = [16]
*/
void RPN::RPN_operations(const std::string& input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) 
    {
        if (tokenType(token) == NUM)
        {
            _RPNorg.push(std::atoi(token.c_str()));
        }
        else if (tokenType(token) == OP && _RPNorg.size() >= 2)
        {
            double sec = _RPNorg.top(); _RPNorg.pop();
            double fst = _RPNorg.top(); _RPNorg.pop();
            double res = do_op(token[0], fst, sec);
            _RPNorg.push(res);
        } 
        else
        {
            throw std::runtime_error("Invalid operator: " + token + "\n");
        }
    }
    displayRes();
}
/** !SECTION 
 * ****************
 * SECTION - UTILS 
 * ****************
*/
/**
 * @brief This function will check the type of the token
 * @param token The string to check the type
 * @return token The type of the token defined by the enum token (NUM, OP, ERROR)
 * 
 * @warning The mandatory behavior is defined by the 42 SUbject, and the rules are:
 *          - NUM: The numbers used in this operation and passed as arguments will always be less than 10,
 *                 and don’t need to manage the brackets or decimal numbers.
 *          - OP: The operators used in this operation and passed as arguments will always be +, -, *, /
 *          - ERROR: An error message should be displayed on the standard output.
 * @note The rules to check the type are:
 *      - NUM: If the string/token has only one character and it is a digit (0-9)
 *      - OP: If the string/token has only one character and it is an operator (+, -, *, /)
 *      - ERROR: If the string/token has more than one character or if it is not a digit or an operator
*/
token RPN::tokenType(std::string &token)
{
    if (token.length() == 1 && isdigit(token[0]))
        return (NUM);
    if (token.length() == 2 && isdigit(token[1]) && token[0] == '-')
        return (NUM);
    else if (token.length() == 1 && token.find_first_not_of("-+/*") == std::string::npos)
        return (OP);
    return (ERROR);
}
/**
 * @brief This function will apply the operation defined by the operator passed as argument
 * @param type const char that represents the operator to apply (+, -, *, /)
 * @param fst double that represents the first number to apply the operation
 * @param sec double that represents the second number to apply the operation
 * @return double The result of the operation
 * @throw std::runtime_error If the operator is invalid
 * 
 * @note The function uses double to garantee the precision of the result, 
 *       in case of division, for example, the result can be a decimal number
*/
double RPN::do_op(const char type, double fst, double sec)
{
    switch(type)
    {
        case '+': 
            return fst + sec;
        case '-':
            return fst - sec;
        case '*':
            return fst * sec;
        case '/': 
/*             if (sec == 0) 
                throw std::runtime_error(std::string("Invalid operator: ") + type); */
            return fst / sec;
        default: 
            throw std::runtime_error(std::string("Invalid operator: ") + type + "\n");
    }
}
/**
 * @brief This function will display the result of the RPN calculation
 * @throw std::runtime_error If the notation is invalid format
 * 
 * @note the verification of size of the stack is to check if the notation is valid,
 *       because the result of the RPN calculation should be only one number in the stack
*/
void RPN::displayRes()
{
    if (_RPNorg.size() != 1)
    {
        throw std::runtime_error("Invalid notation\n");
    }
    std::cout << _RPNorg.top() << std::endl; 
}






