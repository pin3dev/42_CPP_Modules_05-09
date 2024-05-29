/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:35 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/29 12:55:30 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src) : _vec(src._vec), _deq(src._deq), _log(NULL) {(void)src;}

PmergeMe& PmergeMe::operator=(const PmergeMe& src){(void)src;return (*this);}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(int ac, char **av)
{
	this->_verifyArgs(ac, av);
	this->_fillContainers(ac, av);
}

void PmergeMe::_binarySearchInsertVEC(std::vector<int>& main_chain, int b)
{
    int left = 0;
    int right = main_chain.size();
	this->_log->printMsg("\n---------BINARY INSERTION---------\n");
	std::ostringstream oss;
	oss << "B: " << b << std::endl;
	std::string msg = oss.str();
	this->_log->printMsg(msg);

    this->_log->printArray(main_chain);
	this->_log->printBinary(main_chain, left, right);
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (main_chain[mid] < b)
        {
		    left = mid + 1;
    		this->_log->printArray(main_chain);
			this->_log->printBinary(main_chain, left, right);
		}
        else
		{
            right = mid;
    		this->_log->printArray(main_chain);
			this->_log->printBinary(main_chain, left, right);
		}
    }
	
	oss << "PUSHING TO MAIN CHAIN [ "<< left << " ] = " << b << "\n";
	msg = oss.str();
	this->_log->printMsg(msg);
    main_chain.insert(main_chain.begin() + left, b);
}

void PmergeMe::_algorithmFordJohnsonVEC()
{
    std::vector<PmergeMe::intPair> pairs;
    
	int size = this->_vec.size();

	for (int i = 0; i < (size - 1); i += 2)
        pairs.push_back(std::make_pair(this->_vec[i], this->_vec[i+1]));
    
    if (size % 2 != 0)
        pairs.push_back(std::make_pair(this->_vec[size - 1], this->_vec[size - 1]));

    this->_log->printMsg("------PARES DESORDENADOS------\n");
    this->_log->printPair(pairs);
	
	std::vector<int> main_chain;
    
	size = pairs.size();
	for (int i = 0; i < (size - 1); i++)
        main_chain.push_back(std::min(pairs[i].first, pairs[i].second));

    this->_log->printMsg("---------MAIN CHAIN DESORDENADO---------\n");
    this->_log->printArray(main_chain);  

	std::sort(main_chain.begin(), main_chain.end());

    this->_log->printMsg("---------MAIN CHAIN ORDENADO---------\n");
    this->_log->printArray(main_chain);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
	    _binarySearchInsertVEC(main_chain, std::max(pairs[i].first, pairs[i].second));
    	this->_log->printMsg("---------MAIN CHAIN---------\n");
    	this->_log->printArray(main_chain);
	}

    this->_vec = main_chain;
}

void PmergeMe::_binarySearchInsertDEQ(std::deque<int>& main_chain, int b)
{
    int left = 0;
    int right = main_chain.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (main_chain[mid] < b)
            left = mid + 1;
        else 
            right = mid;
    }
    main_chain.insert(main_chain.begin() + left, b);
}

void PmergeMe::_algorithmFordJohnsonDEQ()
{
    std::deque<PmergeMe::intPair> pairs;
    
	int size = this->_deq.size();
	
	for (int i = 0; i < (size - 1); i += 2)
        pairs.push_back(std::make_pair(std::min(this->_deq[i], this->_deq[i+1]), std::max(this->_deq[i], this->_deq[i+1])));
    
    if (size % 2 != 0)
        pairs.push_back(std::make_pair(this->_deq[size - 1], this->_deq[size - 1]));

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        main_chain.push_back(pairs[i].first);

    for (size_t i = 0; i < pairs.size(); ++i)
        _binarySearchInsertDEQ(main_chain, pairs[i].second);

    this->_deq = main_chain;
}

void	PmergeMe::runMergeInsertion()
{
	printContainer(RED "Before: " RESET, this->_vec);

	clock_t initVEC = clock();
	_algorithmFordJohnsonVEC();
	clock_t endVEC = clock();
	
	clock_t initDEQ = clock();
	_algorithmFordJohnsonDEQ();
	clock_t endDEQ = clock();

	printContainer(GREEN "After: " RESET, this->_vec);

	double processVEC = static_cast<double>(endVEC - initVEC) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << processVEC << " s" << std::endl;
	double processDEQ = static_cast<double>(endDEQ - initDEQ) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << processDEQ << " s" << std::endl;
}

/** !SECTION 
 * ***********************
 * SECTION - CLASS UTILS 
 * ***********************
*/

void PmergeMe::_verifyArgs(int ac, char **av)
{
	if(ac < 3 || ac > 3001)
		throw std::invalid_argument("Error: Wrong amount of arguments");
	for(int i = 1; i < ac; i++)
	{
		if(std::atol(av[i]) < 0 || std::atol(av[i]) > INT_MAX  || std::atol(av[i]) < INT_MIN)
		{
			std::string str = av[i];
			throw std::invalid_argument("Error: Value " + str + " out of range");
		}
		
		for(int j = 0; av[i][j] != '\0'; j++)
		{
			if(!isdigit(av[i][j]))
				throw std::invalid_argument("Error: Value '" + std::string (1, av[i][j]) + "' is not a digit");
		}
	}
}

void	PmergeMe::_fillContainers(int ac, char **av)
{
	for(int i = 1; i < ac; i++)
	{
		_vec.push_back(std::atoi(av[i]));
		_deq.push_back(std::atoi(av[i]));
	}
}

void	PmergeMe::setLogger(Logger *log){this->_log = log;}



/** !SECTION 
 * ***********************
 * SECTION - TEMPLATE UTILS 
 * ***********************
*/

template <typename T>
void printContainer(std::string debug, T const &container)
{
	std::cout << debug << ": ";
	for(size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i];
		if(i != container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

