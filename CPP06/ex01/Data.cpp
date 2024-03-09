/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:36:30 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 11:22:51 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(/* args */):_value(586)
{
    std::cout<<"Default constructor for Data is called" <<std::endl;
}
Data::Data(int value):_value(value){}

Data::Data(const Data& copy): _value(copy.getValue())
{
    *this = copy;   
}

Data& Data::operator=(const Data& other)
{
    (void)other;
    return *this;
}

int Data::getValue() const {
    return (Data::_value);
}

Data::~Data()
{
    std::cout<<"Destructor for Data is called" <<std::endl;
}