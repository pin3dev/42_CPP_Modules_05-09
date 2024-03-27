/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:59:06 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 16:23:12 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Template Function implementation "easyfind"
 * @brief The function must search the first occurrence of integer n within 'T' container type
 * @param[out] T: Reference to any Container<int>
 * @param[in] n: integer to be find on Container<int>
 * @throw std::out_of_range if the integer 'n' was not found inside the container 'T'
 * 
 * @warning the behavior of this function is defined by calculating the distance between the begin 
 *         of the container and the iterator returned by the find() function, or a throw exception if not found.
 * 
 * @note the subject specifies that no associative containers will be used,
 *      so this function will not be tested with std::map, std::set, std::multimap, std::multiset, etc...
 * 
 * @note the find() function is a member of the <algorithm> library,
 *      and could be used to search for a specific value in any
 *      container that provides iterators, such as std::vector, std::list, std::deque, etc...
 * 
 * @note the original find() function returns an iterator to the last element of the container if the value is not found
*/
template <typename T>
void easyfind(const T &container, int n)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), n); //search for n in container
    if(it == container.end())
    {
        std::cerr << "Integer '" << n << "' not found! ";
        throw std::out_of_range("[Exception] out of range");
    }
    std::cout << "Integer '" << n << "' found in position [" << std::distance(container.begin(), it) << "]" << std::endl;       
};

