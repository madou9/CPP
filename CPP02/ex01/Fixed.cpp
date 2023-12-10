/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:20 by ihama             #+#    #+#             */
/*   Updated: 2023/12/07 19:25:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp" 

Fixed::Fixed(/* args */) : _fixedPointValue(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}
/*
    The constructor with an integer parameter takes an integer value, left-shifts 
    it by the number of _fractionalBits, and stores the result in fixedPointValue. 
    This is done to convert the integer to a fixed-point representation.
*/

Fixed::Fixed(const int i_value) : _fixedPointValue(i_value << _fractionalBits)
{
    std::cout<<"Int constructor called"<<std::endl;
}

/*
    The constructor with a float parameter takes a float value, multiplies it by 2 
    raised to the power of _fractionalBits, rounds the result using roundf,and stores 
    it in fixedPointValue. This is done to convert the float to a fixed-point representation.
*/

Fixed::Fixed(const float f_valu) : _fixedPointValue(roundf(f_valu * (1 << _fractionalBits)))
{
    std::cout<<"Float constructor called" <<std::endl;
}
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
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other; //a way to reuse the copy assignment operator
}

//Copy Assignment Operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout<<"Copy assignment operator called" << std::endl;
    Fixed::_fixedPointValue = other.getRawBits();
    return *this;
}

/*
    A Cast operator is a unary operator which forces one data type to be converted 
    into another data type. static_cast<float> is to make for exemple an integer to 
    float like 4 to 4.00 static_cast <dest_type> (source);
*/

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

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

