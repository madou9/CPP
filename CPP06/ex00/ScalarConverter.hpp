/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:32:40 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 12:32:45 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter(/* args */); // constructor
    ScalarConverter(const ScalarConverter& copy); //copy constructor
    ScalarConverter& operator=(const ScalarConverter& other); //copy assignment operator
    ~ScalarConverter(); //destructor

    static void convert(const std::string& str);
};
