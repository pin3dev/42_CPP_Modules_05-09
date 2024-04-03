/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:58 by pin3dev           #+#    #+#             */
/*   Updated: 2024/04/03 15:56:37 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Checker.hpp" //to all libraries and Checker class
#include "BitcoinDataBase.hpp" //to BitcoinDataBase class

#define INPUT_SEPARATOR '|'

class BitcoinExchange : public Checker
{
    private:
        const BitcoinDataBase *_DBacess;
        void findExchange(ValidPair pair);
        
    public:
        //ATRIBUTOS
        std::ifstream _INPUTfile;
        //ALIAS
        //METODOS
        void exchange();
        //CONSTRUTORES
        BitcoinExchange();;
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();
        
        BitcoinExchange(const std::string &INPUTpath, const BitcoinDataBase *DBacess);
};

#endif
