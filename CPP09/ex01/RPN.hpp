/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:47 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/04 16:43:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream> //to std::cout
#include <string> //to std::string
#include <stack> //to std::stack
#include <sstream> //to std::istringstream
#include <stdexcept> //to throw exceptions, std::runtime_error
#include <cstdlib> //std::atoi
#include "mColors.hpp"

/** 
 * @enum token
 * @brief Enum to define the type of the token
 * @param NUM The token is a number
 * @param OP The token is an operator
 * @param ERROR The token is invalid
*/
enum token
{
    NUM,
    OP,
    ERROR
};

/**
 * Class Definition
 * @class RPN
 * @brief RPN class to process the Reverse Polish Notation (RPN) expression and calculate the result
 * @param _RPNorg a static stack to store the numbers and the result of the operations
 * @throws std::runtime_error if the notation is invalid
 * 
 * More details about the class
*/
class RPN
{
    private:
        static std::stack<double>   _RPNorg;
        /**
         * Utils Members Functions
         * @brief Functions help to implement the logic of the RPN class
        */
        static double do_op(const char type, double fst, double sec);
        static void displayRes();
        static token tokenType(std::string &token);
        /**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @note In this case, the private members is to avoid instantiation of objects
         *       because the only method and atributes are static
         * @see subject_en.pdf for more information
        */
        RPN();
        RPN(RPN const& src);
        RPN& operator=(RPN const& src);
        ~RPN();
    public:
        /**
         * Additional Member Functions
         * @brief Includes member function to process the RPN expression
        */
        static void RPN_operations(std::string const& input);
};

#endif