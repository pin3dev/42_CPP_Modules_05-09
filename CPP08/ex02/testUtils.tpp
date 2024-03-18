/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:02:20 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/14 20:05:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Template OVERLOAD OPERATOR GENERAL
 * @brief Prints the value of each integer stored in "MutantStack" object
 * @param[out] out The output stream where the values will be printed.
 * @param[out] obj The MutantStack object whose values will be printed.
 * @return a reference to the output stream.
 * 
 * This Template function is optional and helps facilitate cleaner debugging tests
 * NOTE - the typename must to be replaced on c++11 by "auto" flag
 *        example: for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, const MutantStack<T>&obj)
{
    typename MutantStack<T>::const_iterator it_b = obj.begin(); 
    typename MutantStack<T>::const_iterator it_e = obj.end(); 
    it_e--;
    it_b--;

    out << CYAN "--------STACK--------" << std::endl
        << BKGRAY ">>> size: "  << obj.size() << RESET << std::endl
        << BKGRAY ">>> top: " << obj.top() << RESET << std::endl;
    for (unsigned int i = obj.size(); it_e != it_b; --it_e, --i)
    {   
        if (i == obj.size())
            out << YELLOW "[ TOP]:" RESET << *it_e << std::endl;
        else if (i == 1)
            out <<  YELLOW "[BASE]:" RESET << *it_e << std::endl;
        else
            out << CYAN "[" << std::setw(4) << i << "]:" RESET << *it_e << std::endl;
    }
    out << CYAN "---------------------" << std::endl;
    return (out);
}

/**
 * Template function implemantation
 * @brief Prints the value of each integer stored in "AnyContainer" object
 * @param[out] out The output stream where the values will be printed.
 * @param[out] obj The AnyContainer object whose values will be printed, could be list,vector,deque,etc..
 * @return a reference to the output stream.
 * 
 * This Template function is optional and helps facilitate cleaner debugging tests
 * NOTE - the typename must to be replaced on c++11 by "auto" flag
 *        example: for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
 */
template<typename AnyContainer>
std::ostream& printContainer(std::ostream& out, const AnyContainer& obj)
{
    typename AnyContainer::const_iterator it_b = obj.begin();
    typename AnyContainer::const_iterator it_e = obj.end();

    out << MAGENTA "--------CONTAINER--------" << std::endl
        << BKGRAY ">>> size: "  << obj.size() << RESET << std::endl
        << BKGRAY ">>> last: " << *it_e << RESET << std::endl;
    for (unsigned int i = 1; it_b != it_e; ++it_b, ++i)
    {   
        if (i == 1)
            out << YELLOW "[FIRST]:" RESET << *it_b << std::endl;
        else if (i == obj.size())
            out <<  YELLOW "[ LAST]:" RESET << *it_b << std::endl;
        else
            out << MAGENTA "[" << std::setw(5) << i << "]:" RESET << *it_b << std::endl;
    }
    out << MAGENTA "-------------------------" RESET << std::endl;
    return (out);
};

/** 
 * NOTE to student - These functions use the same logic to print the values, 
 * but I decided it's a good idea to implement both functions to change the 
 * output design to MutantStack from AnyContainer.
 */
