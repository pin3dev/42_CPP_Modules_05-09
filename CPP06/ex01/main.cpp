/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:49:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 21:15:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
	//testing block 0: creating
	Data	*d = new Data; //creating a Data struct
	d->_str = "TESTANDO_SOM..."; //setting the _str attribute
	d->_x = -42; //setting the _x attribute
	d->_y = 42; //setting the _y attribute
	
	std::cout  
	<< "_str : " << d->_str 
	<< " | _x : " << d->_x 
	<< " | _y : " << d->_y 
	<< " | "<< std::endl; //printing the Data struct content
	
	//testing block 1: serialization
	uintptr_t cur = Serializer::serialize(d); //trying to serialize the pointer to Data struct
	
//>>>>>Printing
	std::cout << "Endereço de memória de 'data' em <Data*> hexadecimal: " << d << std::endl;
    std::cout << "Endereço de memória de 'data' em <uintptr> unsigned long: " << cur << std::endl;

	d = Serializer::deserialize(cur); //trying to deserialize the uintptr_t to Data struct
	
	std::cout  
	<< "_str : " << d->_str 
	<< " | _x : " << d->_x 
	<< " | _y : " << d->_y 
	<< " | "<< std::endl; //printing the Data struct content, has to be the same as the first print
	
	delete d;
}