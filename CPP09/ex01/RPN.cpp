/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:45 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/26 14:28:10 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<double>   RPN::_RPNorg;

RPN::RPN(){}

RPN::RPN(RPN const& obj){*this = obj;}

RPN::~RPN(){}

RPN& RPN::operator=(RPN const& obj){(void)obj;return (*this);}

static double do_op(const char type, double fst, double sec)
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
            throw std::runtime_error(std::string("Invalid operator: ") + type);
    }
}

void RPN::displayRes()
{
    if (_RPNorg.size() != 1)
    {
        throw std::runtime_error("Invalid notation\n");
    }
    std::cout << _RPNorg.top() << std::endl; 
}
token RPN::tokenType(std::string &token)
{
    if (token.length() == 1 && isdigit(token[0]))
        return (NUM);
    else if (token.length() == 1 && token.find_first_not_of("-+/*") == std::string::npos)
        return (OP);
    return (ERROR);
}

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
            throw std::runtime_error("Invalid operator: " + token);
        }
    }
    displayRes();
}



