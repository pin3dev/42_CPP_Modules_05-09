/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:02:37 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/26 17:26:39 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <limits.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <time.h>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);
		~PmergeMe();

		PmergeMe(char **numbers, int numberCount);

		void	sorting();

		void	mergeInsertVector(std::vector<int> &vector);
		void	mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);

		void	mergeInsertDeque(std::deque<int> &deque);
		void	mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deque);
};

# endif