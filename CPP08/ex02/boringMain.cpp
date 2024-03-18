/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boringMain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:51:51 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 19:33:33 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp" 
#include "mColors.hpp"
#include <iomanip> //to std::setw


int main()
{
    int arr_1[] = {10, 22, 33345, 42342, -215, -2135, -2125}; //array values inicializer
    int arr_2[] = {1032, 2212, 345, 442, -5, -15, -21}; //array values inicializer
    int arr_3[] = {0, 90, 575, 502, -86, -150, -67}; //array values inicializer
    
    std::cout << std::setw(50) << RED "-----" << "Stack Tester" << "-----" RESET << std::endl;
    MutantStack<int> MyMutantStack; //declare an MutantStack object to test iterators and methods
    MutantStack<int>::const_iterator it_b; //creat const_iterator of MutantStack<int>
    MutantStack<int>::const_iterator it_e; //creat const_iterator of MutantStack<int>
    
    
    int len = sizeof(arr_1) / sizeof(arr_1[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_1[i]); //fill MutantStack with arr_1 values
    
    //setting iterators to display content
    it_b = MyMutantStack.begin(); //creat Alias to const_iterator of MutantStack<int>
    it_e = MyMutantStack.end(); //creat Alias to const_iterator of MutantStack<int>

    //display all values of MutantStack
    std::cout << CYAN "--------STACK--------" << std::endl
    << BKGRAY ">>> size: "  << MyMutantStack.size() << RESET << std::endl
    << BKGRAY ">>> top: " << MyMutantStack.top() << RESET << std::endl;
    for (unsigned int i = 0; it_b != it_e; ++it_b, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_b << std::endl;
    std::cout << CYAN "---------------------" << std::endl;    
    
    len = sizeof(arr_2) / sizeof(arr_2[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_2[i]); //add to MutantStack the arr_2 values

     //setting iterators to display content
    it_b = MyMutantStack.begin(); //creat Alias to const_iterator of MutantStack<int>
    it_e = MyMutantStack.end(); //creat Alias to const_iterator of MutantStack<int>

    //display all values of MutantStack
    std::cout << CYAN "--------STACK--------" << std::endl
    << BKGRAY ">>> size: "  << MyMutantStack.size() << RESET << std::endl
    << BKGRAY ">>> top: " << MyMutantStack.top() << RESET << std::endl;
    for (unsigned int i = 0; it_b != it_e; ++it_b, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_b << std::endl;
    std::cout << CYAN "---------------------" << std::endl;   
            
    len = sizeof(arr_3) / sizeof(arr_3[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyMutantStack.push(arr_3[i]); //add to MutantStack the arr_3 values

    //setting iterators to display content
    it_b = MyMutantStack.begin(); //creat Alias to const_iterator of MutantStack<int>
    it_e = MyMutantStack.end(); //creat Alias to const_iterator of MutantStack<int>

    //display all values of MutantStack
    std::cout << CYAN "--------STACK--------" << std::endl
    << BKGRAY ">>> size: "  << MyMutantStack.size() << RESET << std::endl
    << BKGRAY ">>> top: " << MyMutantStack.top() << RESET << std::endl;
    for (unsigned int i = 0; it_b != it_e; ++it_b, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_b << std::endl;
    std::cout << CYAN "---------------------" << std::endl;  
    
    std::cout << std::setw(50) << RED "-----" << "Any Container Tester" << "-----" RESET << std::endl;

    //std::list<int> MyVector;
    //std::vector<int> MyVector;
    std::deque<int> MyVector; //declare an container object to test iterators and methods
    std::deque<int>::iterator it_bb; //creat const_iterator of deque<int>
    std::deque<int>::iterator it_ee; //creat Const_iterator of deque<int>

    len = sizeof(arr_1) / sizeof(arr_1[0]); //calculate len of arr_1
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_1[i]); //fill container with arr_1 values

    it_bb = MyVector.begin();
    it_ee = MyVector.end();
    
    //display all values of MutantStack
    std::cout << CYAN "--------CONTAINER--------" << std::endl
    << BKGRAY ">>> size: "  << MyVector.size() << RESET << std::endl
    << BKGRAY ">>> last:" << *it_ee << RESET << std::endl;
    for (unsigned int i = 0; it_bb != it_ee; ++it_bb, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_bb << std::endl;
    std::cout << CYAN "-------------------------" << std::endl;  
    
    len = sizeof(arr_2) / sizeof(arr_2[0]); //calculate len of arr_2
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_2[i]); //add to container the arr_2 values
    
    it_bb = MyVector.begin(); //creat Alias to const_iterator of deque<int>
    it_ee = MyVector.end(); //creat Alias to const_iterator of deque<int>
    
    //display all values of MutantStack
    std::cout << CYAN "--------CONTAINER--------" << std::endl
    << BKGRAY ">>> size: "  << MyVector.size() << RESET << std::endl
    << BKGRAY ">>> last:" << *it_ee << RESET << std::endl;
    for (unsigned int i = 0; it_bb != it_ee; ++it_bb, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_bb << std::endl;
    std::cout << CYAN "-------------------------" << std::endl;  
    
    len = sizeof(arr_3) / sizeof(arr_3[0]); //calculate len of arr_3
    for (int i = 0; i < len; i++)
        MyVector.push_back(arr_3[i]); //add to container the arr_3 values

    it_bb = MyVector.begin(); //creat Alias to const_iterator of deque<int>
    it_ee = MyVector.end(); //creat Alias to const_iterator of deque<int>
    
    //display all values of MutantStack
    std::cout << CYAN "--------CONTAINER--------" << std::endl
    << BKGRAY ">>> size: "  << MyVector.size() << RESET << std::endl
    << BKGRAY ">>> last:" << *it_ee << RESET << std::endl;
    for (unsigned int i = 0; it_bb != it_ee; ++it_bb, ++i)
        std::cout << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_bb << std::endl;
    std::cout << CYAN "--------------------------" << std::endl; 
    return 0;
}