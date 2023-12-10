/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:01:46 by ihama             #+#    #+#             */
/*   Updated: 2023/12/03 15:32:04 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;             // Default constructor, initializes a to 0
    Fixed const b(10);   // Constructor with int parameter, initializes b to the fixed-point representation of 10
    Fixed const c(42.42f); // Constructor with float parameter, initializes c to the fixed-point representation of 42.42
    Fixed const d(b);     // Copy constructor, initializes d to the value of b
    a = Fixed(1234.4321f); // Assignment, assigns the fixed-point representation of 1234.4321f to a

    // Output the values
    std::cout << "a is " << a << std::endl; // Outputs the floating-point representation of a
    std::cout << "b is " << b << std::endl; // Outputs the floating-point representation of b
    std::cout << "c is " << c << std::endl; // Outputs the floating-point representation of c
    std::cout << "d is " << d << std::endl; // Outputs the floating-point representation of d

    // Output the integer representations
    std::cout << "a is " << a.toInt() << " as integer" << std::endl; // Outputs the integer representation of a
    std::cout << "b is " << b.toInt() << " as integer" << std::endl; // Outputs the integer representation of b
    std::cout << "c is " << c.toInt() << " as integer" << std::endl; // Outputs the integer representation of c
    std::cout << "d is " << d.toInt() << " as integer" << std::endl; // Outputs the integer representation of d

    return 0;
}


// $> ./a.out
// Default constructor called
// Int constructor called
// Float constructor called
// Copy constructor called
// Copy assignment operator called
// Float constructor called
// Copy assignment operator called
// Destructor called
// a is 1234.43
// b is 10
// c is 42.4219
// d is 10
// a is 1234 as integer
// b is 10 as integer
// c is 42 as integer
// d is 10 as integer
// Destructor called
// Destructor called
// Destructor called
// Destructor called
// $>

