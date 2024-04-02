/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:47 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/26 14:27:53 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <cstdlib>

enum token
{
    NUM,
    OP,
    ERROR
};

class RPN
{
    private:
        static std::stack<double>   _RPNorg;
        static  void displayRes();
        static token tokenType(std::string &token);

        RPN();
        RPN(RPN const& obj);
        RPN& operator=(RPN const& obj);
        ~RPN();
    public:

        static void RPN_operations(std::string const& input);
};

#endif