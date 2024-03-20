/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/20 14:26:10 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <algorithm> //to std::find, std::map
#include <utility> //to std::pair
#include <iostream> //to std::cout, std::cin, std::endl
#include <exception> //to exception class
#include <fstream> //to std::ifstream, std::ofstream, etc
#include <sstream> //to std::stringstream
#include <string> //to std::string, std::getline


class Checker
{
    private:
        void ckDate(std::string &line, const char separator);
        void ckValue(std::string &line, const char separator, bool maxValue);
        std::string &clearStr(std::string &str);
    protected:
        //typedef std::pair<std::string, float> validPair;
        void ckFormat(std::string line, const char separator, bool maxValue);
        void ck_FileErr(std::ios& file);
    public:  
};

#endif
