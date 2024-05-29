/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 18:45:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream> //to use cout
#include <stdexcept> //to use throw, try, catch
#include <limits.h> //to use INT_MAX and INT_MIN
#include <vector> //to use vector
#include <deque> //to use deque
#include <sstream>
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
		void 	_verifyDuplicate();

		//vectors
		void	_mergeTwoVEC(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);
		void	_mergeSortVEC(std::vector<int> &vector);
		void	_binaryInsertVEC(std::vector<int>& main_chain, int b);
		void  	_FordJohnsonVEC();

		//list
		void	_mergeTwoDEQ(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq);
		void	_mergeSortDEQ(std::deque<int> &deq);
		void	_binaryInsertDEQ(std::deque<int>& main_chain, int b);
		void  	_FordJohnsonDEQ();

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