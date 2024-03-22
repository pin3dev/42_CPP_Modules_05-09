/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:49:52 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 21:12:34 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/** Default Constructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
Serializer::Serializer(/*std::cout << BKGRAY "[Serializer] Default Constructor called" RESET << std::endl;*/){}

/** Copy Constructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
Serializer::Serializer(const Serializer &src){static_cast<void>(src);/*std::cout << BKGRAY "[Serializer] Copy constructor called" RESET << std::endl;*/}

/** Copy assignment operator
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
Serializer &Serializer::operator=(const Serializer &src){static_cast<void>(src);/*std::cout << BKGRAY "[Serializer] Copy assignment operator called" << RESET << std::endl;*/return (*this);}

/** Destructor
 * @deprecated This constructor is not used
 * @warning This constructor is private and should not be executed
 * 
 * @note This constructor serves to comply with the subject's canonical form
*/
Serializer::~Serializer(){/*std::cout << BKGRAY "[Serializer] Destructor called" RESET << std::endl;*/}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * @brief transform a Data pointer into a uintptr_t
 * @param[out] ptr is an pointer to Data
 * @return uintptr_t is an unsigned integer that can hold a pointer address to Data
 * 
 * @note uintptr_t is a type that can hold a pointer like a long int
 * @note the typecasting of reinterpret_cast is used in this case to convert a pointer to an integer
 * @note the reinterpret_cast is an low-level typecasting that can convert a pointer to another pointer type or to an integer,
 * 		 but it is not safe because it cannot check if the pointer is valid, even in compile time or execution time,
 * 		 and the programmer should be sure that the pointer is valid before using the reinterpret_cast
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (std::cerr << "Error" << std::endl, 0);
	std::cout << GREEN "Serialized: " << ptr << RESET << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief transform a uintptr_t into a Data pointer
 * @param[out] raw uintptr_t is an pointer to Data
 * @return uintptr_t is an unsigned integer that can hold a pointer address to Data
 * 
 * @warning REINTERPRET_CAST is a cast operator that converts an pointer to any other type of pointer
 * 			and does not perform any check whter the pointer converted is of the same type or not 
 * 
 * @note uintptr_t is a type that can hold a pointer like a long int
 * @note the typecasting of reinterpret_cast is used to convert a integer to an pointer
*/
Data* Serializer::deserialize(uintptr_t raw)
{
    if (raw == 0)
    {
		std::cerr << "Error" << std::endl;
		return (NULL); 
	}
	std::cout << RED "Deserialized: " << reinterpret_cast<Data*>(raw) << RESET << std::endl;
	return (reinterpret_cast<Data*>(raw));
}
