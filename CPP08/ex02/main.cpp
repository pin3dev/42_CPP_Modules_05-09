/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:58:24 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 19:26:46 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp" //to MutantStack class objects
#include "testUnits.hpp" //to support functions of unit tests

/**
 * This is an main function to test the "MutantStack" iterators
 * NOTE 1 - Should run several unit tests to check this object:
 * - Default Constructor;
 * - Constructor with param int;
 * - Constructor with param iterator;
 * - Copy Constructor;
 * - Copy assignment operator;
 * - Destructor (memory leaks);
 * - Calling MutantStack to <AnyType>: string,int,float,double, etc...
 * - Calling push_back to all type of container<Anytype> list, vector, deque, etc...
 * NOTE 2 - This main depends on some MACROS and utils template functions in @file testUtils.tpp mColors.hpp
 * TODO - Create a Catch2 Test that includes all the above tests
 * TODO - Test to memory leaks
*/
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
    //std::list<int> MyVector;
    //std::vector<int> MyVector;
    std::deque<int> MyVector; //declare an container object to test iterators and methods
    
    len = sizeof(arr_1) / sizeof(arr_1[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_1[i]); //fill container with arr_1 values
    printContainer(std::cout, MyVector); //display all values of container

    len = sizeof(arr_2) / sizeof(arr_2[0]); //calculate len of arr_2
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_2[i]); //add to container the arr_2 values
    printContainer(std::cout, MyVector); //display all values of container
    
    len = sizeof(arr_3) / sizeof(arr_3[0]); //calculate len of arr_3
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_3[i]); //add to container the arr_3 values
    printContainer(std::cout, MyVector); //display all values of container
    return 0;
}