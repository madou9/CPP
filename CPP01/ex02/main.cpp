/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:48 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 18:10:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//Pointers: A pointer is a variable that holds the memory address of another variable;
//References:A reference, like a pointer, is also implemented by storing the address of an object. 

int	main(void)
{
    std::string str;
    //pointeur can take an reference
    std::string* stringPTR = &str;
    // reference can not take an pointeur because it's already an pointeur
    std::string& stringREF = str;

    str = "HI THIS IS BRAIN";
    std::cout << "memory adrress for string: " << &str << std::endl;
    std::cout << "memory adrress held by stringPTR: " << stringPTR << std::endl;
    std::cout << "memory adrress held by stringREF: " << &stringREF << std::endl;
    std::cout << "value of the string: " << str << std::endl;
    std::cout << "value pointed by stringPTR: " <<*stringPTR << std::endl;
    std::cout << "value pointed by sringREF: " << stringREF << std::endl;
    return (0);
}