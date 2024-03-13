/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:22:59 by ihama             #+#    #+#             */
/*   Updated: 2024/03/13 11:17:53 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
    The Array.tpp file is often used to separate 
    the implementation of the member functions of a class 
    template from its declaration
*/

//Array<T>&: This specifies that the function returns a reference to an Array object of type T
//Array<T>:: This scope resolution operator indicates that we're defining a member function of the Array template class.
template <typename T>
Array<T>::Array(/* args */): _size(0)
{
    Array<T>::_array = new T[0];  // Allocate for zero elements
    std::cout<<"Default contructor for Array is called"<<std::endl;
}

// Constructor with size parameter
template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
    if (n < 0)
        throw OutOfBounds();
    else if (_size == 0)
        Array<T>::_array = NULL; //// Handle size 0 case
    else
        Array<T>::_array = new T[n];
}
// Copy constructor
template <typename T>
Array<T>::Array(const Array& copy): _size(copy._size)
{
    Array<T>::_array = new T[copy._size];
    unsigned int i = 0;
    while (i < Array<T>::_size){
        this->_array[i] = copy._array[i];
        i++;
    }
    // *this = copy;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
    //checks for self-assignment (this == &other) to avoid unnecessary operations.
    if (this != &other)
    {
        delete[] _array; // Deallocate existing memory
        Array<T>::_size = other._size;
        if (other._array != NULL) //This indicates that the other object has a valid array allocated.
        {
            Array<T>::_array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = other._array[i];
            }
        }
        else
            this->_array = NULL;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (Array<T>::_array)
        delete [] Array<T>::_array;
    std::cout<<"Destructor for Array is called!"<<std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw OutOfBounds();
    else
         return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
    return "Error: index Out of Bounds";
}