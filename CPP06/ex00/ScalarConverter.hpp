/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:51 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 10:48:13 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

//TODO - VERIFICAR SE ESTÁ DENTRO DO PADRÃO DE RAW STRING

#include <iostream> //to std::cout and std::endl
#include <string> //to raw string
#include <limits> //to check the limits of the types
#include <cmath> //to std::isnan and std::isinf
#include "mColors.hpp" //to MACROS and ENUMS

//#include <sstream>
//#include <cfloat>
//#include <climits>

/** Class Declaration
 * @class ScalarConverter
 * @brief This class is responsible for converting a string to a scalar type
 * @warning This class must not be instanciable by users (mandatory)
*/
class	ScalarConverter
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
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

	public :
		/**
         * Additional Member Functions
         * @brief Includes member functions as 
         *        required by the subject guidelines of 42
         * @see subject_en.pdf for more information
        */
		static void	convert(std::string &input);
};

#endif