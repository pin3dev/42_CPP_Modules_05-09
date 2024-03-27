/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:01:18 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 17:26:57 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testUtils.hpp"

/**
 * @brief executed public methods of Span (shortestSpan and longestSpan)
 * @param[out] obj reference to Span object used/test to execute public methods
*/
void diffSpan(Span &obj)
{
    std::cout << YELLOW "Shortest Span: " RESET << obj.shortestSpan() << std::endl;
    std::cout << YELLOW "Longest Span: " RESET << obj.longestSpan() << std::endl;
}

/**
 * @brief prints a aligned line to set regions of test
 * @param header std::string to be printed
*/
void	printHeader(std::string header)
{
	std::cout << std::setw(50) << MAGENTA "-----" << header << "-----" RESET << std::endl;
}

/**
 * operator<< OVERLOAD OPERATOR GENERAL
 * @brief Prints the value of each integer stored in "Span" (aka std::vector<int> _Vnumb).
 * @param[out] out The output stream where the values will be printed.
 * @param[out] obj The Span object whose values will be printed.
 * @return a reference to the output stream.
 * 
 * This function is optional and helps facilitate cleaner debugging tests
 */
std::ostream &operator<<(std::ostream &out, const Span&obj)
{
    out << CYAN "--------VECTOR--------" << std::endl
        //<< "address: " << &obj << std::endl
        << ">>> Max: " << obj.getN() << std::endl
        << ">>> Remains: " << obj.getRemainsN() << std::endl;
    for (unsigned int i = 0; i < obj.getVector().size(); i++)
        out << CYAN "[" << std::setw(4) << i << "]:" << obj.getContent(i) << std::endl;
    out <<  "----------------------" RESET << std::endl;
    return (out);
}

//DEPRECATED 
/* static void coutVec(std::vector<int> &n)
{
    std::cout << MAGENTA "--------GENERAL VECTOR--------" RESET << std::endl;
    for (size_t i = 0; i < n.size(); i++)
        std::cout << MAGENTA "[" << i << "]: " RESET << n[i] << std::endl;
} */