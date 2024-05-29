/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 01:18:02 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <fstream>

class Logger
{
	private:
		std::ofstream	_logfile;
	public:
		Logger();
		Logger(const Logger& src);
		Logger&	operator=(const Logger& src);
		~Logger();

		typedef std::pair<int, int> intPair;

		void printArray(const std::vector<int>& arr);
		void printBinary(const std::vector<int>& arr, int left, int right);
		void printPair(const std::vector<intPair>& pair);
		void printMsg(const std::string& msg);
};

# endif