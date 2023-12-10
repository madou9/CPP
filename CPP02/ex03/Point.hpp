/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:41:29 by ihama             #+#    #+#             */
/*   Updated: 2023/12/05 20:03:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
    //A Fixed const attribute x.
    const Fixed _x;
    //A Fixed const attribute y.
    const Fixed _y;

public:
    Point(/* args */); // Default constructor
    Point(const float x, const float y); // // Constructor with two floating-point parameters
    Point(const Point &other); // Copy constructor
    Point& operator= (const Point& other); // Copy assignment operator overload
    ~Point(); // Destructor
    
    const Fixed &getX() const;
    const Fixed &getY() const;

    friend std::ostream& operator<<(std::ostream& out, const Point& fixed);
};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);