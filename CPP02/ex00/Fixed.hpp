/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:40:58 by ihama             #+#    #+#             */
/*   Updated: 2023/12/04 15:33:15 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

class Fixed
{
private:
    //An integer to store the fixed-point number value
    int _fixedPointValue;
    //A static constant integer to store the number of fractional bits Its values will always be the integer literal 8
    static const int _fractionalBits = 8;
public:
    //A default constructor that initializes the fixed-point number value to 0.
    Fixed(/* args */);
    //A copy constructor.
    Fixed(const Fixed &other);
    //A copy assignment operator overload.
    Fixed &operator =(const Fixed &other);
    //A destructor
    ~Fixed();
    int getRawBits( void ) const; // that returns the raw value of the fixed-point value.
    void setRawBits( int const raw ); //that sets the raw value of the fixed-point number
};
