/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:36:54 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 10:13:15 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer{
private:
    /* data */
    // Serializer();
public:
    Serializer(/* args */);
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& other);
    
    static Data* deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data.
    static uintptr_t serialize(Data* ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.


    ~Serializer();
};
// std::ostream& operator<<(std::ostream &os, Serializer const& serializer);

