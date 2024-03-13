/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:00 by ihama             #+#    #+#             */
/*   Updated: 2024/03/12 17:01:07 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 


#include <iostream>

template <typename T>
class Array {
private:
    T* _array; // Pointer to the dynamically allocated array
    unsigned int _size; // Size of the array

public:
    // Constructors
    Array(); // Default constructor
    Array(unsigned int n); // Constructor with size parameter
    Array(const Array& copy); // Copy constructor
    Array& operator=(const Array& other); // Assignment operator
    ~Array(); // Destructor

    // Overloaded subscript operator for element access
    T& operator[](unsigned int index);

    // Member function to retrieve the size of the array
    unsigned int size() const;

    // Nested exception class for out of bounds access
    class OutOfBounds: public std::exception {
    public:
        const char* what() const throw(); // Override what() function to provide exception message
    };
};

#include "Array.tpp"
