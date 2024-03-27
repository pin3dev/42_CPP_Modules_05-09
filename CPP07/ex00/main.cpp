/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:52:47 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 15:16:45 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	//testing block 0: creating int data
	int a = 2; //min
	int b = 3; //max
	//testing block 1: testing swap
	::swap( a, b );
	//testing block 2: printing
	std::cout << "a = " << a << ", b = " << b << std::endl;
	//testing block 3: testing and printing min and max
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; //returns b
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl; //returns a
	//testing block 4: creating std::string data
	std::string c = "chaine1"; //min
	std::string d = "chaine2"; //max
	//testing block 5: testing swap
	::swap(c, d);
	//testing block 6: printing
	std::cout << "c = " << c << ", d = " << d << std::endl;
	//testing block 7: testing and printing min and max
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl; //returns d
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl; //returns c
	return 0;
}