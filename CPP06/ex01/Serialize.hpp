/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:49:54 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/15 15:58:40 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream> //to std::cout and std::endl
#include <inttypes.h> //<cstdint> c++11 //para uintptr_t
#include "mColors.hpp" //to color the output


/** Struct Declaration
 * @struct Data
 * @brief This struct is responsible for storing the data to be serialized
*/
struct	Data
{
	std::string		_str;
	int				_x;
	int				_y;
};

/** Class Declaration
 * @class Serializer
 * @brief This class is responsible for serializing and deserializing a Data struct
 * @warning This class must not be instanciable by users (mandatory)
*/
class	Serializer
{
	private :
		/**
         * Canonical Form
         * @brief Includes special member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
		 * @warning this class must not be instanciable by users (mandatory)
		 * 
		 * @note The following functions are declared private to prevent instanciation
        */
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
	public :
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif