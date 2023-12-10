/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:36:27 by ihama             #+#    #+#             */
/*   Updated: 2023/12/05 19:41:19 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    //An integer to store the fixed-point number value
    int _fixedPointValue;
    //A static constant integer to store the number of fractional bits Its values will always be the integer literal 8
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int i_value); // Member function to convert to int
    Fixed(const float f_valu); // Member function to convert to float
    Fixed &operator = (const Fixed &other);
    // The 6 comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    // The 4 arithmetic operators: +, -, *, and /.
    float operator+(Fixed& other)const;
    float operator-(Fixed& other)const;
    float operator*(Fixed& other)const;
    float operator/(Fixed& other)const;
    //The 4 Increment/Decrement Operators:
    Fixed operator++(); // pre-increment
    Fixed operator--(); // pre-decrement
    Fixed operator++(int); // post-increment
    Fixed operator--(int); // post-decrement
    /*Static Member Functions:*/
    //A static member function min that takes as parameters two references
    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    //• A static member function min that takes as parameters two references to constant fixed-point numbers
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    ~Fixed();
    float toFloat ( void ) const;
    int toInt ( void ) const;
    int getRawBits( void ) const; // that returns the raw value of the fixed-point value.
    void setRawBits( int const raw ); //that sets the raw value of the fixed-point number
    // Overload the insertion operator
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};