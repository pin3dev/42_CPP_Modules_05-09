/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDataBase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/22 15:28:37 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP

#include "Checker.hpp" //to all libraries and Checker class

#define DB_PATH "data.csv"
#define DB_SEPARATOR ','

class BitcoinDataBase : public Checker
{
    public:
        //ATRIBUTOS
        std::map<std::string, float> DBdata;
        //METODOS        
        BitcoinDataBase();;
        BitcoinDataBase(const BitcoinDataBase& src);
        BitcoinDataBase& operator=(const BitcoinDataBase& src);
        ~BitcoinDataBase();
};

#endif
