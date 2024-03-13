/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:20:06 by ihama             #+#    #+#             */
/*   Updated: 2024/03/13 11:25:06 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

/*
    takes a generic type T as input (printMessage<T>). 
    This allows it to print elements of any data type T. 
    The output format includes the element followed by " <<<----- ".
*/
template <typename T>
void printMessage(T array)
{
    std::cout << array <<" <<<----- "  << std::endl;
}
/*
    handles integer arrays (printMessage(int array)). 
    It prints the integer elements with "----->>> " preceding them.
*/
void printMessage(int array)
{
    std::cout << "----->>> " << array << std::endl;
}
 /*
    This function takes an array array of generic type T, 
    its length (length), and a function pointer func as arguments
 */
template <typename T>
void iter(T* array, size_t length, void (*func)(T)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}
