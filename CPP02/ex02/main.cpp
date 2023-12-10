/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:18:58 by ihama             #+#    #+#             */
/*   Updated: 2023/12/03 23:15:06 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;                                      // Default constructor called, initializes 'a' to 0
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // Constructs 'b' using the multiplication of two Fixed numbers

    std::cout << a << std::endl;                  // Outputs the value of 'a' (0)
    std::cout << ++a << std::endl;                // Pre-increments 'a' and then outputs the updated value (1)
    std::cout << a << std::endl;                  // Outputs the current value of 'a' (1)
    std::cout << a++ << std::endl;                // Outputs the current value of 'a' and then post-increments 'a' (1)
    std::cout << a << std::endl;                  // Outputs the updated value of 'a' after post-increment (2)
    std::cout << b << std::endl;                  // Outputs the value of 'b' (10.1)
    std::cout << Fixed::max( a, b ) << std::endl; // Outputs the maximum value between 'a' and 'b'

    return 0;
}



// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// $>