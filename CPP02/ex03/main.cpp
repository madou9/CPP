/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:36:30 by ihama             #+#    #+#             */
/*   Updated: 2023/12/07 17:52:56 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    // Define three vertices of a triangle
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);

    // Define two points to test
    Point insidePoint(0.2f, 0.2f);
    Point outsidePoint(1.0f, 1.0f);

    // Check if the insidePoint is inside the triangle and print the result
    if (bsp(a, b, c, insidePoint))
        std::cout << "Inside point is inside the triangle." << std::endl;
    else
        std::cout << "Inside point is outside the triangle." << std::endl;
    // std::cout<<"totalArea: " << insidePoint << std::endl;
    // Check if the outsidePoint is inside the triangle and print the result
    if (bsp(a, b, c, outsidePoint))
        std::cout << "Outside point is inside the triangle." << std::endl;
    else 
        std::cout << "Outside point is outside the triangle." << std::endl;
    // std::cout<<"totalArea: " << outsidePoint << std::endl;
    return 0;
}
