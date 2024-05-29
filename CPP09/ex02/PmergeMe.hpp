/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 01:25:25 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream> //to use cout
#include <stdexcept> //to use throw, try, catch
#include <limits.h> //to use INT_MAX and INT_MIN
#include <vector> //to use vector
#include <deque> //to use deque
#include <cstdlib> 
#include <time.h> //to use clock()
#include <utility> //to use pair
#include <algorithm> //to use sort
#include "mColors.hpp" //to use colors
#include "Logger.hpp" //to use Logger


class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		Logger *_log;

		void	_verifyArgs(int av, char **ac);
		void	_fillContainers(int av, char **ac);

		void	_binarySearchInsertVEC(std::vector<int>& main_chain, int b);
		void   algorithmFordJohnsonVEC();
		void   algorithmFordJohnsonDEQ();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& src);
		~PmergeMe();

		PmergeMe(int av, char **ac);
		
		void	runMergeInsertion();
		void	setLogger(Logger *log);
		
		typedef std::pair<int, int> intPair;
};

template <typename T>
void printContainer(std::string debug, T const &container);

# endif