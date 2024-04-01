/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:57:43 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 16:46:45 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private members _N and _remainsN to 0 without requiring parameters,
 *        and prints a message to the standard output.
 * 
 * @note the std::vector does not require initialization, as it is a container that initializes itself
 * @note the std::vector does not require size initialization, as it is a container that dynamically resizes itself
 * 
 * This behavior is optional and reflects a design choice; it is subject to modification.
 */
Span::Span() : _N(0), _remainsN(0)
{
    std::cout << BKGRAY "[Span] Default Constructor called" RESET << std::endl;
}

/**
 * Copy Constructor
 * @brief Instantiates a Span object by deeply copying another one of the same type.
 *        A deep copy involves copying every value initialized in the private members of the source object,
 *        as _vector,_N and _remainsN
 * @param[out] src A reference to a const Span object to be copied.
 * @return A reference to the newly created Span object.
 * 
 * This behavior is mandatory.
 */
Span::Span(const Span &src) : _vector(src._vector), _N(src._N), _remainsN(src._remainsN)
{
    std::cout << BKGRAY "[Span] Copy constructor called" RESET << std::endl;
}

/**
 * Copy Assignment operator / OVERLOAD OPERATOR
 * @brief assign a Span object by deeply copying another one of the same type.
 *        A deep copy involves copying every value initialized in the private members of the source object,
 *        as _vector,_N and _remainsN
 * @param[out] src A reference to a const Span object to be copied.
 * @return A reference to the newly created Span object.
 */
Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->_N = src.getN();
        this->_vector = src.getVector();
        this->_remainsN = src.getRemainsN();
    }
	std::cout << BKGRAY "[Span] Copy assignment operator called" << RESET << std::endl;
    return(*this);
}

/**
 * Destructor
 * @brief Deletes the Span object, either by an explicit call (delete Span) in case of heap memory allocation
 *        or automatically in case of stack memory allocation, and prints a message to the standard output.
 * 
 * This behavior is standard and mandatory.
 */
Span::~Span()
{
    std::cout << BKGRAY "[Span] Destructor called" RESET << std::endl;
}


/**!SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * Constructor with unsigned int Parameter (Mandatory)
 * @brief Initializes the private members _N and _remainsN with the provided N parameter,
 *        and prints a message to the standard output.
 * @param N an unsigned int to be assigned to the private member _N.
 * @return a reference to a Span object that was created.
 * 
 * This behavior is mandatory.
 */
Span::Span(unsigned int N) : _N(N), _remainsN(N)
{
    std::cout << BKGRAY "[Span] Constructor with param N called" RESET << std::endl;
}

/**
 * Constructor with Iterator Parameter (Optional)
 * @brief Initializes the private members _N and _remainsN with 100 as the standard value,
 *        fills the _vector vector with all values between the first and last iterator parameters provided,
 *        and prints a message to the standard output.
 * @param[out] first an std::vector<int>::iterator for the first element of an output container.
 * @param[out] last an std::vector<int>::iterator for the last element of an output container.
 * @return a reference to a Span object that was created.
 * 
 * @warning the ifRemainsN() and setRemainsN() functions are called in this function.
 * @see utils section for more information
 * 
 * @note Filling the _vector with numerous values is mandatory, but the design approach is optional.
 * @note the initialization of containers non-associative values could be done by several ways:
 * 	- Initializing with the same value (e.g., 0) for all elements
 * 	EXAMPLE: std::vector<int> vec(5, 0); //creates a vector with 5 elements, all initialized with value 0
 * 	- Initializing with a range of values from an array
 * 	EXAMPLE: int arr[] = {1, 2, 3, 4, 5}; std::vector<int> vec(arr, arr + 5); //creates a vector with 5 elements, initialized with values 1,2,3,4,5
 * 	- Initializing with a range of values from another container
 * 	EXAMPLE: std::vector<int> vec2= {1, 2, 3, 4, 5}; std::vector<int> vec(vec2.begin(), vec2.end()) //creates a vector with 5 elements, initialized with values 1,2,3,4,5 copied from vec2 vector
 *	- Initialization with a list of values is provided, NOT AVAILABLE TO C++98
 *	EXAMPLE: std::vector<int> vec = {1, 2, 3, 4, 5}; //creates a vector with 5 elements, initialized with values 1,2,3,4,5
 */
Span::Span(it first, it last) 
{
    this->_N = 100;
    this->_remainsN = 100;
    unsigned int amountN = std::distance(first, last); //std::distance calculates the amount of numbers between first and last iteartor
    if (this->ifRemainsN(amountN))
        this->_vector.insert(_vector.end(), first, last);
    else
        this->_vector.insert(_vector.end(), first, (first + this->getRemainsN()));
    this->setRemainsN();
    std::cout << BKGRAY "[Span] Constructor with Iterator called" RESET << std::endl;
}

/**
 * addNumber Function
 * @brief adds a single number provided by the parameter to the "Span", aka _vector vector.
 * @param numb an integer to be added to the "Span", aka the _vector vector.
 * @throw std::runtime_error If there are no available slots remaining for storing integers, as indicated by _remainN.
 * 
 * @warning the ifRemainsN() and setRemainsN() functions are called in this function.
 * @see utils section for more information
 */
void Span::addNumber(int numb)
{
    if (this->getRemainsN() == 0) //verify if still available slots remaining (aka _remainsN)
    {
        throw std::runtime_error("[Span_Exception]: Vector is full");
        return ;
    }
    if (this->ifRemainsN(1)) // Used to check if there are still available slots remaining (aka _remainsN) after subtracting one slot.
    {
        this->_vector.push_back(numb);
        this->setRemainsN(); // Updates the count of available slots remaining (aka _remainsN) after an addition operation.
    }
}

/**
 * addNumber Function
 * @brief adds a single number provided by the parameter to the "Span", aka _vector vector.
 * @param[out] first an std::vector<int>::iterator for the first element of an output container.
 * @param[out] last an std::vector<int>::iterator for the last element of an output container.
 * @throw std::runtime_error If there are no available slots remaining for storing integers, as indicated by _remainN.
 * 
 * @warning the ifRemainsN() and setRemainsN() functions are called in this function.
 * @see utils section for more information
 */
void Span::addNumber(it first, it last)
{
    unsigned int amountN = std::distance(first, last); //std::distance calculates the amount of numbers between first and last iteartor
    if (this->getRemainsN() == 0 || !this->ifRemainsN(amountN)) //verify if still available slots remaining (aka _remainsN)
    {
        throw std::runtime_error("[Span_Exception]: Vector is full");
        return ;
    }
    if (this->ifRemainsN(amountN)) // used to check if there are still available slots remaining (aka _remainsN) after subtracting "amount" slots.
        this->_vector.insert(_vector.end(), first, last); //copy all integers from "first" until "last" iterator
    this->setRemainsN(); // Updates the count of available slots remaining (aka _remainsN) after an addition operation.
}
/**
 * shortestSpan Function
 * @brief Calculates the shortest difference span value between all values stored in "Span" (aka _vector).
 * @throw std::runtime_error If there are fewer than 2 integers stored in "Span" (aka _vector).
 * @return Integer with the shortest difference span value calculated.
 */
int Span::shortestSpan()
{
    if (_vector.size() < 2) //verifies if the vector have int enough to compare
        throw std::runtime_error("[Span_Exception]: Insufficient number of integers in vector");
    std::sort(_vector.begin(), _vector.end()); //std::sort puts the vector in order
    int shortest = _vector[1] - _vector[0]; //estipulate the first diff as the shortest, to compare with the others
    for (size_t i = 2; i < _vector.size(); ++i) //run the vector values
    {
        int cur = _vector[i] - _vector[i - 1]; //checking if another diff is shorter than the current stored in "shortest"
        if (cur < shortest) 
            shortest = cur; //replace old shortest value with this new one shorter
    }
    return (shortest);
}

/**
 * longestSpan Function
 * @brief Calculates the longest difference span value between all values stored in "Span" (aka _vector).
 * @throw std::runtime_error If there are fewer than 2 integers stored in "Span" (aka _vector).
 * @return Integer with the longest difference span value calculated.
 */
int Span::longestSpan()
{
    if (_vector.size() < 2) //verifies if the vector have int enough to compare
        throw std::runtime_error("[Span_Exception]: Insufficient number of integers in vector");
    std::sort(_vector.begin(), _vector.end()); //std::sort puts the vector in order
    int min = _vector.front(); //takes the first (min value) int the vector
    int max = _vector.back(); //takes the last (max value) int the vector
    int longest = max - min; //calculates the longest diff between integers in the vector
    return longest;
}

/** !SECTION
 * ****************************
 * SECTION - GETTERS & SETTERS
 * ****************************
*/

/**
 * getN Function
 * @return an unsigned integer copy of _N value
 */
unsigned int Span::getN()const
{
    return(this->_N);
}

/**
 * getVector Function
 * @return an std::vector<int> copy of _vector container
 */
std::vector<int> Span::getVector()const
{
    return(this->_vector);
}

/**
 * getRemainsN Function
 * @return an unsigned integer copy of _remainsN value
 */
unsigned int Span::getRemainsN()const
{
    return (this->_remainsN);
}

/**
 * getContent Function
 * @brief runs through the container _vector until the index i provided by parameter
 * @param i an unsigned int to index of _vector
 * @return an integer copy of _vector[i] value
 */
int Span::getContent(unsigned int i)const
{
    return (this->_vector[i]);
}

/**
 * setRemainsN Function
 * @brief Updates the _reaminsN value by subtracting the size 
 * of the '_vector' container from the maximum size '_N'
 */
void Span::setRemainsN()
{
    this->_remainsN = (this->getN() - this->getVector().size());
}

/** !SECTION
 * ****************
 * SECTION - UTILS 
 * ****************
*/

/**
 * ifRemainsN Function
 * @brief Checks if there are still available slots remaining (aka _remainsN) after subtracting 'n' slots.
 * @param n an unsigned integer indicating how many slots the verification should subtract.
 * @return a boolean value set to true if there are remaining slots after subtraction.
 */
bool Span::ifRemainsN(unsigned int n)
{
    return (this->getRemainsN() - n >= 0);
}
