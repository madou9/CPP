/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:04 by ihama             #+#    #+#             */
/*   Updated: 2023/12/04 16:16:31 by ihama            ###   ########.fr       */
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
    //A constructor that takes a constant integer as a parameter
    Fixed(const int i_value);
    //A constructor that takes a constant floating-point number as a parameter
    Fixed(const float f_valu);
    Fixed &operator = (const Fixed &other);
    ~Fixed();
    float toFloat ( void ) const;
    int toInt ( void ) const;
    int getRawBits( void ) const; // that returns the raw value of the fixed-point value.
    void setRawBits( int const raw ); //that sets the raw value of the fixed-point number
    // Overload the insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};