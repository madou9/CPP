/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:44:12 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 10:50:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Data
{
private:
    /* data */
    int _value;
    std:: string _name;
public:
    Data(/* args */);
    Data(int value);
    Data(const Data& copy); // copy constructor for Data;
    Data& operator=(const Data& other); // copy assignment operator for Data;
    int getValue() const;
    ~Data();
};
// std::ostream& operator<<(std::ostream &os, Data const& other);

