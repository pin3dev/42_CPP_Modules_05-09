/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:58:26 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 18:41:58 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_HPP
# define UTILS_HPP

/**
 * @file testUtils.hpp
 * @def definition of MACROS to help tests
*/

/**
 *  COLORS
 *  @brief Definition of colors to be used in cout messages.
*/
#define RESET    "\x1b[0m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RED    "\x1b[31m"
#define GRAY  "\x1b[37m"
#define MAGENTA "\x1b[35m"
#define BKGRAY	"\x1b[47;90m"
#define CYAN    "\x1b[36m"

/**
 * BG and END
 * @brief MACROS to help fill containers to tests
*/
#define BG 0
#define END 2213

# endif