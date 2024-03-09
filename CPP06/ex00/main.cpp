/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:24:36 by ihama             #+#    #+#             */
/*   Updated: 2024/03/08 19:17:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char** argv) {
    std::cout<<"--------------------------------------------------------"<<std::endl;
    if (argc != 2) {
        std::cout << "Wrong: there is not argument or Bad arguments given" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    ScalarConverter::convert(input);
    std::cout<<"--------------------------------------------------------"<<std::endl;
    // system("leaks ScalarConverter");
    return 0;
}

// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f 
// double: 0.0
// ./convert nan
//	char: impossible
// int: impossible
// float: nanf
// double: nan 
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f 
// double: 42.0