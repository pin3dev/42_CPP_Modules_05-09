/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:35 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 18:33:54 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger() : _logfile("log.txt"){}

Logger::Logger(const Logger& src) {(void)src;}

Logger& Logger::operator=(const Logger& src){(void)src;return (*this);}

Logger::~Logger()
{
    if (_logfile.is_open())
        _logfile.close();
}

void Logger::printArray(const std::vector<int>& arr)
{
    this->_logfile << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << "----+";
    }
    this->_logfile << std::endl;

    this->_logfile << "|";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << std::setw(3) << arr[i] << " |";
    }
    this->_logfile << std::endl;

    this->_logfile << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << "----+";
    }
    this->_logfile << std::endl;
}

void Logger::printBinary(const std::vector<int>& arr, int left, int right)
{
    this->_logfile << "|";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if ((int)i == left && (int)i == right)
        {
            this->_logfile << std::setw(3) << "LR" << " |";
        }
        else if ((int)i == left)
        {
            this->_logfile << std::setw(3) << "L" << " |";
        }
        else if ((int)i == right)
        {
            this->_logfile << std::setw(3) << "R" << " |";
        }
        else
        {
            this->_logfile << std::setw(3) << " " << " |";
        }
    }
    this->_logfile << std::endl;

    this->_logfile << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << "----+";
    }
    this->_logfile << std::endl;
}

void Logger::printPair(const std::vector<intPair>& pair)
{
    for (size_t i = 0; i < pair.size(); ++i)
    {
        this->_logfile << std::setw(3) << "|" << pair[i].first 
        << " " 
        << std::setw(3) << pair[i].second << " |" << std::endl;
    }
    this->_logfile << std::endl;
}
void Logger::printMsg(const std::string& msg)
{
    this->_logfile << msg << std::endl;
}

void Logger::printOss(std::ostringstream oss)
{
    this->_logfile << oss;
}
