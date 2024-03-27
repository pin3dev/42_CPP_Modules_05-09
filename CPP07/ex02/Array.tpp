/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:55:54 by pin3dev           #+#    #+#             */
/*   Updated: 2024/03/27 18:30:16 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * **************************
 * SECTION - CANONICAL FORM
 * **************************
*/

/**
 * Default Constructor
 * @brief Initializes the private attributes with default values.
 *        The default value for the _array is 0
 * 		  The default value for the _size is 0
 * 		  Could display a message to the standard output.
 * @tparam T the type of the array
 * @warning the _array is initialized with size 0,
 *          because the subject specifies that the array should be created empty.
 * 
 * @note A NULL pointer is not the same as a pointer to an array of size 0,
 *      A pointer to an array of size 0 is a valid pointer, but it cannot be dereferenced.
 * 
 * @note This behavior is optional and reflects a design choice; it is subject to modification.
 */
template<typename T>
Array<T>::Array() : _array(new T[0]()), _size(0)
{
    //std::cout << BKGRAY "[Array] Default Constructor called" RESET << std::endl;
}

/**
 * Copy Constructor
 * @brief Initializes the private attributes with the values of the instance passed by reference.
 * 		  Could display a message to the standard output.
 * @tparam T the type of the array
 * @param[out] src an const reference to the instance to be copied.
 * @warning is necessary initialize the data of _array with the same data of the src
 * 
 * @note This behavior is mandatory.
 */
template<typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]()), _size(src._size)
{
    for (unsigned int i = 0; i < this->_size; ++i)
        this->_array[i] = src._array[i];
	//std::cout << BKGRAY "[Array] Copy constructor called" << std::endl;
    //*this = src;
}

/**
 * Copy Assignment operator / OVERLOAD OPERATOR
 * @brief assigns the values of the private attributes of the instance passed by
 * 		  reference to the instance on the left side of the operator.
 * 		  Could display a message to the standard output.
 * @tparam T the type of the array
 * @param[out] src an const reference to the instance to be copied.
 * @return a reference to the instance on the left side of the operator.
 * @warning before the assingment, is necessary delete the _array to avoid memory leaks, and so,
 *          assign the data of src to the _array of the instance on the left side of the operator.
 * 
 * @note This behavior is mandatory.
 */
template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    if (this != &src)
    {
        delete[] this->_array;
        this->_size = src.size();
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; ++i)
            this->_array[i] = src._array[i];
    }
	//std::cout << BKGRAY "[Array] Copy assignment operator called" << std::endl;
    return *this;
}

/**
 * Destructor
 * @brief Deletes the Array object, either by an explicit call (delete Array) in case of heap memory allocation
 *        or automatically in case of stack memory allocation
 * 		  Could display a message to the standard output.
 * 
 * @note This behavior is standard and mandatory.
 */
template<typename T>
Array<T>::~Array()
{
    delete[] _array;
    _array = NULL;
	//std::cout << BKGRAY "[Shrubbery] Destructor called" RESET << std::endl;
}

/** !SECTION
 * **************************************
 * SECTION - ADDITIONAL MEMBERS FUNCTIONS
 * **************************************
*/

/**
 * Constructor with parameters (Mandatory)
 * @brief Initializes the private attributes with the values of the parameters passed by reference.
 *        Could display a message to the standard output.
 * @tparam T the type of the array
 * @param n an unsigned int that represents the size of the array.
 * 
 * @note This behavior is mandatory.
 * @note In c++11 is possible to initialize the array with new T[n]() to avoid garbage memory for both primitive types and objects (def constructors)
 */
template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) 
{
    //std::cout << BKGRAY "[Array] Constructor called to array w/ size: " << n << RESET << std::endl;
}

/**
 * Overload Operator []
 * @brief Overloads the operator [] to access the elements of the array.
 * @tparam T the type of the array
 * @param i an unsigned int that represents the index of the array.
 * @return a reference to the element of the array at the index i.
 * @warning if the index is out of the array bounds, throws an exception.
 * 
 * @note This signature is valid to access the elements of the array in a unitary way,
 *      giving the possibility to change the value of the element.
 * 
 * @note To avoid the change of the value of the element, is possible to create
 *      a const version of this function by 
 *      const T &Array<T>::operator[](unsigned int i) const
 * 
 * @note This behavior is mandatory.
 */
template<typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->size() || this->_array == NULL || this->_size == 0) 
        throw (Array::OutOfBounds());
    return (this->_array[i]);
}

/** !SECTION
 * ****************************
 * SECTION - EXCEPTIONS
 * ****************************
*/

/**
 * OutOfBounds Exception
 * @brief Exception class message to be thrown when the index is out of the array bounds.
 * 
 * @note This behavior is mandatory.
 */
template<typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
    return (RED "[Array_Exception] Index is out of array bounds!" RESET);
}

/** !SECTION
 * ****************************
 * SECTION - GETTERS & SETTERS
 * ****************************
*/

/**
 * @brief Returns the value of the private attribute _size.
 * @tparam T the type of the array
 * @return the value of the private attribute _size.
 */
template<typename T>
unsigned int Array<T>::size(void) const
{
    return (this->_size);
}

/**
 * @brief Returns the value of the private attribute _array in a specific index provided by parameter.
 * @tparam T the type of the array
 * @return the value of the private attribute _array in a index i.
 */
template<typename T>
T Array<T>::getTContent(unsigned int i) const
{
    return (this->_array[i]);
}

/** !SECTION
 * ****************
 * SECTION - UTILS 
 * ****************
*/

/**
 * operator<< OVERLOAD OPERATOR GENERAL
 * @brief displays the content of the Array object in the standard output.
 * @tparam T the type of the array
 * @param[out] out the reference to the output stream.
 * @param[out] obj an const reference to the Array object to be printed.
 * @return a reference to the output stream.
 * 
 * @note This function is not mandatory but helps facilitate cleaner debugging tests
 */
template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T>&obj)
{
    out << CYAN "--------ARRAY--------" << std::endl
        << "> size: " RESET << obj.size() << std::endl;
    for (size_t i = 0; i < obj.size(); i++)
        out << CYAN "> array[" << i << "]: " RESET 
        << obj.getTContent(i) << std::endl;
    return (out);
};

/**!SECTION
 * 
*/
