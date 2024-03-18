/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:57:00 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 18:48:58 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp" //to template easyfind
#include "testUtils.hpp" //to colors and others macros

//[Optional]: Container types to test the "easyfind" on
#include <forward_list>
#include <list>
#include <vector>
#include <deque>

/**
 * This is an main function to test the "easyfind" function
 * NOTE 1 - Should run several unit tests to check this function:
 * - With a list<int> container object
 * - With a vector<int> container object
 * - With a deque<int> container object
 * - With a forward_list<int> container object
 * NOTE 2 - This main depends on some MACROS @ref BG and END in @file testUtils.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
int main()
{
    //declartion of diferents containers types to test
    std::list<int> _Lint;
    std::vector<int> _Vint;
    std::deque<int> _Dint;

    //filling the containers with integers from 0 to 2213, see MACROS in easyfind.hpp file
    for (int i = BG; i <= END; i++)
    {
        _Vint.push_back(i);
        _Lint.push_back(i);
        _Dint.push_back(i);
    }
    //testing the "easyfind" function on list<int> container
    try 
    {
        easyfind(_Lint, 0);
        easyfind(_Lint, 1023);
        easyfind(_Lint, 2213);
        easyfind(_Lint, -17870);
    } 
    catch(std::exception &e){std::cerr << RED << e.what() << RESET << std::endl;}
    //testing the "easyfind" function on vector<int> container
    try 
    {
        easyfind(_Vint, 0);
        easyfind(_Vint, 1023);
        easyfind(_Vint, 2213);
        easyfind(_Vint, -17870);
    } 
    catch(std::exception &e){std::cerr << RED << e.what() << RESET << std::endl;}
    //testing the "easyfind" function on deque<int> container
    try 
    {
        easyfind(_Dint, 0);
        easyfind(_Dint, 1023);
        easyfind(_Dint, 2213);
        easyfind(_Dint, -17870);
    } 
    catch(std::exception &e){std::cerr << RED << e.what() << RESET << std::endl;}
}  