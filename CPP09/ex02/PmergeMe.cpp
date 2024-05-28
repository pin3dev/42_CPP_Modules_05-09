/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:35 by pin3dev           #+#    #+#             */
/*   Updated: 2024/05/28 16:14:42 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _vec(obj._vec), _deq(obj._deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if(this != &obj)
	{
		_vec = obj._vec;
		_deq = obj._deq;
	}
	return(*this);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **numbers, int numberCount)
{
	for(int i = 1; i < numberCount; i++)
	{
		_vec.push_back(std::atoi(numbers[i]));
		_deq.push_back(std::atoi(numbers[i]));
	}
}

void	PmergeMe::sorting()
{
	std::cout << "Before: ";
	//imprime o vector desordenado
	for(size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i];
		if(i != _vec.size() - 1)
			std::cout << " ";
	} 
	std::cout << std::endl;

	//atualiza o timestamp do inicio da operacao no vetor
	clock_t startVec = clock();
	//aplica o algoritmo ao vetor
	mergeInsertVector(_vec);
	//atualiza o timestamp do fim da operacao no vetor
	clock_t endVec = clock();

	//atualiza o timestamp do inicio da operacao no deque
	clock_t startDeq = clock();
	//aplica o algoritmo ao deque
	mergeInsertDeque(_deq);
	//atualiza o timestamp do fim da operacao no deque
	clock_t endDeq = clock();

	std::cout << "After: ";
	//imprime o vector ordenado
	for(size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i];
		if(i != _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	//calcula o tempo de execucao para vector e imprime
	double time_elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_elapsedVec << " s" << std::endl;
	//calcula o tempo de execucao para deque e imprime
	double time_elapsedDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time_elapsedDeq << " s" << std::endl;
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vector)
{
	if(vector.size() == 1)
		return;

	int	mid = vector.size() / 2;

	std::vector<int> left = std::vector<int>(vector.begin(), vector.begin() + mid);
	std::vector<int> right = std::vector<int>(vector.begin() + mid, vector.end());

	mergeInsertVector(left);
	mergeInsertVector(right);
	mergeVec(left, right, vector);
}

void	PmergeMe::mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector)
{
	size_t l = 0, r = 0, v = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			vector[v] = left[l];
			v++;
			l++;
		}
		else
		{
			vector[v] = right[r];
			v++;
			r++;
		}
	}
	while(l < left.size())
	{
		vector[v] = left[l];
		v++;
		l++;
	}
	while(r < right.size())
	{
		vector[v] = right[r];
		v++;
		r++;
	}
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deque)
{
	if(deque.size() == 1)
		return;

	int	mid = deque.size() / 2;

	std::deque<int> left = std::deque<int>(deque.begin(), deque.begin() + mid);
	std::deque<int> right = std::deque<int>(deque.begin() + mid, deque.end());

	mergeInsertDeque(left);
	mergeInsertDeque(right);
	mergeDeque(left, right, deque);
}

void	PmergeMe::mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deque)
{
	size_t l = 0, r = 0, v = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			deque[v] = left[l];
			v++;
			l++;
		}
		else
		{
			deque[v] = right[r];
			v++;
			r++;
		}
	}
	while(l < left.size())
	{
		deque[v] = left[l];
		v++;
		l++;
	}
	while(r < right.size())
	{
		deque[v] = right[r];
		v++;
		r++;
	}
}