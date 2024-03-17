/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:24:33 by ihama             #+#    #+#             */
/*   Updated: 2024/03/15 16:17:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
    What is std::vector in C++?
    std::vector in C++ is the class template that contains the vector container and its member functions. It 
    is defined inside the <vector> header file. The member functions of the std::vector class provide various 
    functionalities to vector containers.
*/

int main(void) {

    try {
        std::vector<int> numbers(4); // Allocate space for 4 elements
        size_t i = 0;
        while (i++ < numbers.size()) numbers[i] = i + 1;
        std::vector<int>::iterator found = easyfind(numbers, 2);
        /*
            Return distance between iterators
            Calculates the number of elements between first and last.
        */
        std::cout << "Found value at index: " << std::distance(numbers.begin(), found) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
