/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:59:06 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 19:27:53 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Template Function implementation "easyfind"
 * @brief The function must print the first occurrence of integer n 
 *         within T container to the standard output cout
 * @param[out] T: Reference to any Container<int>
 * @param[in] n: integer to be find on Container<int>
 * @throw std::out_of_range if the integer 'n' was not found inside the container 'T'
 * 
*/
template <typename T>
void easyfind(const T &container, int n)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), n); //search for n in container
    if(it == container.end())
    {
        std::cerr << "Integer '" << n << "' not found! ";
        throw std::out_of_range("[Exception] Out of range");
    }
    std::cout << "Integer '" << n << "' found in position [" << std::distance(container.begin(), it) << "]" << std::endl;       
};

