/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:57:31 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 17:34:11 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp" //to Span class objects
#include "mColors.hpp" //to color MACROS
#include "testUtils.hpp" //to support functions of unit tests

int main()
{
    int array[] = {10, 22, 33345, 42342, -215, -2135, -2125}; //array values inicializer
    int len = sizeof(array) / sizeof(array[0]); //calculate len of array
    
    std::vector<int> base; //declare an vector base to fill the Span with iterators

    for (int i = 0; i < len; i++) //fill vector with array values
        base.push_back(array[i]);
    //coutVec(n);
    
    Span Vector_1(base.begin(), base.end()); //init Vector_1 with Constructor iterator param
    Span Vector_2(10000); //init Vector_2 as _N==100 and all numbers as 0 value
    try
    {
        printHeader("VECTOR_00");
        Span Vector_00(2); //creates Vector_0 with _N=2
        Vector_00.addNumber(3); //try add a new numbers, and succed bc _RemainsN!=0
        std::cout << Vector_00; //display Vector_00 content
        diffSpan(Vector_00); //try to find the shortest and longest, and Fail bc _vector.size() < 2
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails
    try
    {
        printHeader("VECTOR_0");
        Span Vector_0; //creates Vector_0 with _N=0
        std::cout << Vector_0;  //display Vector_0 content
        Vector_0.addNumber(base.begin(), base.end()); //try add new numbers from base vector, and Fail bc _RemainsN==0 cannot add new numbers 
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails
    try
    {
        printHeader("VECTOR_1");
        std::cout << Vector_1; //display vector_1 content on original order
        diffSpan(Vector_1); //redorder Vector_1 and display results to shortestSpan() and longestSpan()
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails

    int arr[] = {0, -1, 892}; //array values inicializer
    for (int i = 0; i < 3; i++)
        base.push_back(arr[i]); //add new 3 numbers from arr[] in base vector
    //coutVec(n);
    try
    {
        printHeader("VECTOR_2");
        Vector_2 = Vector_1; //copy assignment rearranged Vector_1
        std::cout << Vector_2; //display Vector_2 content as copy of Vector_1
        std::vector<int>::iterator it = std::find(base.begin(), base.end(), 0); //defined iterator to 0 in base vector
        Vector_2.addNumber(it, base.end()); //try add 3 new numbers from arr[] to Vector_2 {0, -1, 892}, and Suceed bc _RemainsN!=0
        std::cout << Vector_2;  //display Vector_2 content
        diffSpan(Vector_2); //redorder Vector_2 and display results
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails
    try
    {
        printHeader("VECTOR_3");
        Span Vector_3(Vector_2); //copy constructor of Vector_2
        Vector_3.addNumber(892); //try add a new numbers, and succed bc _RemainsN!=0
        std::cout << Vector_3; //display Vector_3 content
        diffSpan(Vector_3); //redorder Vector_1 and display results
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails
    try
    {
        printHeader("VECTOR_4");
        Span Vector_4(4); //creates Vector_4 with _N=4
        std::vector<int>::iterator it = std::find(base.begin(), base.end(), 0); //defined iterator to 0 in base vector
        Vector_4.addNumber(it, base.end()); //try add 3 new numbers from arr[] to Vector_4 {0, -1, 892}, and Suceead _RemainsN!=0
        Vector_4.addNumber(42); //try add a new numbers, and succed bc _RemainsN!=0
        std::cout << Vector_4; //display Vector_4 content
        diffSpan(Vector_4); //redorder Vector_4 and display results
        Vector_4.addNumber(-42); //try add a new numbers, and Fail bc _RemainsN==0
    }
    catch(const std::exception& e){std::cerr << RED <<  e.what() << '\n' << RESET;} //prints exception message when try() fails

    return 0;
}