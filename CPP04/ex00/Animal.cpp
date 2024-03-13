/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:17:01 by ihama             #+#    #+#             */
/*   Updated: 2023/12/23 23:58:35 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(/* args */)
{
    std::cout<<"Default constructor for Animal is called !!"<<std::endl;
}
Animal::Animal(std::string tp): type(tp){}

Animal::Animal(const Animal& other) : type(other.type){}

/*
    if (this != &other): This check ensures that you are not assigning an object to itself
    If the address of the current object (this) is not equal to the address of the other object (&other), 
    then the assignment proceeds. This check is essential to avoid self-assignment issues and unnecessary work.
*/

Animal &Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Animal::getType(void) const 
{
    return (this->type);
}

void Animal::makeSound() const{}

Animal::~Animal()
{
    std::cout<<"Destructor for ~Animal is called !!"<<std::endl;
}