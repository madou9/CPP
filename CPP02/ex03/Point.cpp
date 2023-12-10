/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:40:40 by ihama             #+#    #+#             */
/*   Updated: 2023/12/07 16:00:38 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(/* args */) : _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(const Point &other): _x(other.getX()), _y(other.getY()){}

/*
    this copy assignment operator ensures that the coordinates of
    the current Point object are set to the coordinates of another
    Point object (other). The self-assignment check prevents unnecessary 
    work when assigning an object to itself.
*/

Point &Point::operator=(const Point& other)
{
    if (this != &other)
    {
        const_cast<Fixed &>(this->_x) = other.getX();
        const_cast<Fixed &>(this->_y) = other.getY();
    }
    return (*this);
}

const Fixed &Point::getX() const
{
    return _x;
}

const Fixed &Point::getY() const
{
    return _y;
}

/*
    The << operator is overloaded to insert a floating-point representation 
    of the fixed-point number into the output stream. It calls the toFloat 
    member function and then outputs the result to the stream.
*/

std::ostream & operator << (std::ostream &out, const Point &c)
{
    return (out << c.getX() << c.getY());
}

Point::~Point(){}