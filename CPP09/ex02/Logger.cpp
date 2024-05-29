/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:35 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 16:03:00 by pin3dev          ###   ########.fr       */
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

// Helper function to print the array
void Logger::printArray(const std::vector<int>& arr)
{
    // Imprime os números com bordas laterais
    this->_logfile << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << "----+";
    }
    this->_logfile << std::endl;

    // Imprime os números do array
    this->_logfile << "|";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << std::setw(3) << arr[i] << " |";
    }
    this->_logfile << std::endl;

    // Imprime a linha inferior da tabela
    this->_logfile << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        this->_logfile << "----+";
    }
    this->_logfile << std::endl;
}

// Função para imprimir as posições de left e right em uma tabela fixa
void Logger::printBinary(const std::vector<int>& arr, int left, int right)
{
    // Imprime os indicadores L e R com bordas laterais
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

    // Imprime a linha inferior da tabela
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
