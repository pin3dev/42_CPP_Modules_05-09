/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:51:20 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 20:58:45 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
# define BASE_HPP

#include "mColors.hpp" //to colors output
#include <iostream> //to std::cout and std::endl
#include <cstdlib> //to srand()
#include <ctime>  //to time()

/** Class Declaration
 * @class Base
 * @brief This class is the Base class to another classes inheritance
 * @note This class is used to test the inheritance of the derived classes
 * @note This class is used to test the polymorphism
 * @note The destructor is virtual to allow the derived classes to have their additional destructors called
*/
class Base
{
    public:
        virtual ~Base();
};

/**
 * @brief These general functions are used to test the Base class inheritance and polymorphism
*/
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

# endif 
