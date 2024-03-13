/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:21:18 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 21:15:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(/* args */)
{
    std::cout<<"Default constructor for AAnimal is called !!"<<std::endl;
}
AAnimal::AAnimal(std::string tp): type(tp){}

AAnimal::AAnimal(const AAnimal& other) : type(other.type){}

/*
    if (this != &other): This check ensures that you are not assigning an object to itself
    If the address of the current object (this) is not equal to the address of the other object (&other), 
    then the assignment proceeds. This check is essential to avoid self-assignment issues and unnecessary work.
*/

AAnimal &AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

// std::string AAnimal::getType(void) const 
// {
//     return (this->type);
// }

// void AAnimal::makeSound() const{}

AAnimal::~AAnimal()
{
    std::cout<<"Destructor for ~AAnimal is called !!"<<std::endl;
}