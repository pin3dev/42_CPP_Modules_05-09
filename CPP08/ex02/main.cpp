/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:58:24 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 17:44:52 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp" //to MutantStack class objects
#include "testUnits.hpp" //to support functions of unit tests

int main()
{
    int arr_1[] = {10, 22, 33345, 42342, -215, -2135, -2125}; //array values inicializer
    int arr_2[] = {1032, 2212, 345, 442, -5, -15, -21}; //array values inicializer
    int arr_3[] = {0, 90, 575, 502, -86, -150, -67}; //array values inicializer
    
    printHeader("Stack Tester");
    MutantStack<int> MyMutantStack; //declare an MutantStack object to test iterators and methods
    
    int len = sizeof(arr_1) / sizeof(arr_1[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_1[i]); //fill MutantStack with arr_1 values
    std::cout << MyMutantStack; //display all values of MutantStack

    len = sizeof(arr_2) / sizeof(arr_2[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_2[i]); //add to MutantStack the arr_2 values
    std::cout << MyMutantStack; //display all values of MutantStack
    
    len = sizeof(arr_3) / sizeof(arr_3[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_3[i]); //add to MutantStack the arr_3 values
    std::cout << MyMutantStack; //display all values of MutantStack
    
    printHeader("Any Container Tester");
    std::list<int> AnyContainer;
    //std::vector<int> AnyContainer;
    //std::deque<int> AnyContainer; //declare an container object to test iterators and methods
    
    len = sizeof(arr_1) / sizeof(arr_1[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        AnyContainer.push_back(arr_1[i]); //fill container with arr_1 values
    printContainer(std::cout, AnyContainer); //display all values of container

    len = sizeof(arr_2) / sizeof(arr_2[0]); //calculate len of arr_2
    for (int i = 0; i < len; i++)
        AnyContainer.push_back(arr_2[i]); //add to container the arr_2 values
    printContainer(std::cout, AnyContainer); //display all values of container
    
    len = sizeof(arr_3) / sizeof(arr_3[0]); //calculate len of arr_3
    for (int i = 0; i < len; i++)
        AnyContainer.push_back(arr_3[i]); //add to container the arr_3 values
    printContainer(std::cout, AnyContainer); //display all values of container
    return 0;
}