/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:41 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/18 11:04:08 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_HPP
# define UTILS_HPP

/**SECTION - Print Functions */

static void print_t(_Input t);
static void printError(const long double &data);
static void printChar(const long double &data, char c);
static void printInt(const long double &data, int n);
static void printFloat(const long double &data, float n);
static void printDouble(const long double &data, double n);
static void printPseudo(std::string &input);

/**SECTION - Lexer Functions */
static _Input typePseudo(std::string &input);
static _Input typeInput(std::string &input);
static _Input typePseudoOrError(std::string &input);
static _Input typeNumb(std::string &input);
static bool ErrorInput(std::string &input, bool hSig, bool hDot, bool hF);

/**SECTION - Limits Functions */
static bool limitsInput(_Input typeToCheck, const long double &numb);

# endif