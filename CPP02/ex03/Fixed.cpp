/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:36:24 by ihama             #+#    #+#             */
/*   Updated: 2023/12/05 19:40:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(/* args */) : _fixedPointValue(0){}
/*
    The constructor with an integer parameter takes an integer value, left-shifts 
    it by the number of _fractionalBits, and stores the result in fixedPointValue. 
    This is done to convert the integer to a fixed-point representation.
*/

Fixed::Fixed(const int i_value) : _fixedPointValue(i_value << _fractionalBits){}

/*
    The constructor with a float parameter takes a float value, multiplies it by 2 
    raised to the power of _fractionalBits, rounds the result using roundf,and stores 
    it in fixedPointValue. This is done to convert the float to a fixed-point representation.
*/

Fixed::Fixed(const float f_valu) : _fixedPointValue(roundf(f_valu * (1 << _fractionalBits))){}

/*
    is a way to reuse the copy assignment operator (Fixed &Fixed::operator=(const Fixed &other)).
    Instead of duplicating the code that performs the actual copying, 
    it leverages the existing assignment operator to perform the copy.
    Instead of manually duplicating the code to copy the values, it simply calls the copy 
    assignment operator (*this = other;). This ensures consistency between the copy constructor 
    and the copy assignment operator.
*/

Fixed::Fixed(const Fixed &other)
{
    *this = other; //a way to reuse the copy assignment operator
}

//Copy Assignment Operator
Fixed &Fixed::operator=(const Fixed &other)
{
    Fixed::_fixedPointValue = other.getRawBits();
    return *this;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
    // return static_cast<float>(_fixedPointValue);
}

int Fixed::getRawBits(void) const
{
    return (Fixed::_fixedPointValue);
}

/*
    The toInt member function converts the fixed-point 
    value to an integer by right-shifting fixedPointValue 
    by the number of _fractionalBits.
*/

int Fixed::toInt(void) const
{
    return (Fixed::_fixedPointValue >> Fixed::_fractionalBits);
}

void Fixed::setRawBits(int const raw)
{
    Fixed::_fixedPointValue = raw;
}
/*
    The << operator is overloaded to insert a floating-point representation 
    of the fixed-point number into the output stream. It calls the toFloat 
    member function and then outputs the result to the stream.
*/

std::ostream & operator << (std::ostream &out, const Fixed &c)
{
    return (out << c.toFloat());
}

bool Fixed::operator>(const Fixed& other) const
{
    return Fixed::_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return Fixed::_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return Fixed::_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return Fixed::_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return Fixed::_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return Fixed::_fixedPointValue != other.getRawBits();
}

//Arithmetic Operators:
float Fixed::operator+(Fixed& other)const
{
    return (this->toFloat() + other.toFloat());
}

//Arithmetic Operators:
float Fixed::operator-(Fixed& other)const
{
    return (this->toFloat() - other.toFloat());
}

//Arithmetic Operators:
float Fixed::operator*(Fixed& other)const
{
    return (this->toFloat() * other.toFloat());
}

//Arithmetic Operators:
float Fixed::operator/(Fixed& other)const
{
    return (this->toFloat() / other.toFloat());
}

// pre-increment
Fixed Fixed::operator++()
{
    Fixed::_fixedPointValue += 1;
    return (*this);
}

// pre-decrement
Fixed Fixed::operator--()
{
    Fixed::_fixedPointValue -= 1;
    return (*this);
}

// post-increment
Fixed Fixed::operator++(int)
{
    Fixed temp;

    temp = *this;
    this->_fixedPointValue += 1;
    return (temp);
}

// post-decrement
Fixed Fixed::operator--(int)
{
    Fixed temp;

    temp = *this;
    this->_fixedPointValue -= 1;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a <= b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a >= b)
        return a;
    else
        return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a <= b)
        return a;
    else
        return b;  
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a >= b)
        return a;
    else
        return b;  
}
Fixed::~Fixed(){}