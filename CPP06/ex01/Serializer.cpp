/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:37:04 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 10:13:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(/* args */)
{
    std::cout<<"Default constructor for Serializer is called"<<std::endl;
}
Serializer::Serializer(const Serializer& copy){
        *this = copy;
}

Serializer& Serializer::operator=(const Serializer& other){
        if (this != &other)
            return *this;
        return *this;
}

/*
In the context of the Serializer class, 
we are converting between a pointer (Data*) and an unsigned integer (uintptr_t).
This conversion involves reinterpretation of the memory address of the object, which is 
not a standard type conversion. Therefore, reinterpret_cast is the appropriate choice because it explicitly 
conveys that the conversion involves reinterpretation of the underlying bit pattern.
*/

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}

/*
Using static_cast for this purpose might compile without errors, but it would not accurately 
reflect the intent of the code and could potentially hide the fact that the conversion involves 
reinterpretation of memory addresses, which could lead to confusion or errors
in understanding the code. Therefore, reinterpret_cast is the more appropriate choice in this scenario.
*/
uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::~Serializer()
{
    std::cout<<"Destructor for Serializer is called"<<std::endl;
}

// std::ostream& operator<<(std::ostream& os, Serializer const& serializer) {
//     os << "Serializer";
//     return os;
// }
