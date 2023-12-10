/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:01 by ihama             #+#    #+#             */
/*   Updated: 2023/12/04 15:32:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(/* args */):_fixedPointValue(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed &other)
{
    std::cout <<"Copy constructor called" << std::endl;
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout<<"Copy assignment operator called" << std::endl;
    this->_fixedPointValue = other.getRawBits();
   return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{ 
    this->_fixedPointValue = raw;
}
Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}


// $> ./a.out
// Default constructor called
// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called
// $>
