/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:36:21 by ihama             #+#    #+#             */
/*   Updated: 2023/12/05 21:44:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* 
    the area of the triangle to determine if a point is inside it. 
    One way to achieve this is by comparing the sum of the areas of 
    three sub-triangles formed by the given point and each pair of 
    vertices of the original triangle.
*/

static float CalculTriangleArea(Point const a, Point const b, Point const c)
{
    return std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2);
}

// Function to check if a point is inside a triangle using area comparison
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
    //calcul the Total Area of the triangle.
    float totalArea = CalculTriangleArea(a, b, c);

    float area1 = CalculTriangleArea(point, b, c);
    float area2 = CalculTriangleArea(a, point, c);
    float area3 = CalculTriangleArea(a, b, point);

    // Check if the sum of sub-triangle areas is approximately equal to the total area
    std::cout<<"totalArea: " << totalArea << std::endl;
    std::cout<<"Addition for area(1 + 2 + 3): " << area1 + area2 + area3 << std::endl;
    return area1 + area2 + area3 == totalArea;
}
