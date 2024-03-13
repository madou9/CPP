/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:53 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 19:31:31 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout<<"Default constructor for Dog is called !!"<<std::endl; 
}
Dog::Dog(const Dog& ref)
{
    this->type = ref.getType();
}
/*
    if (this != &other): This check ensures that you are not assigning an object to itself
    If the address of the current object (this) is not equal to the address of the other object (&other), 
    then the assignment proceeds. This check is essential to avoid self-assignment issues and unnecessary work.
*/

Dog &Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

std::string Dog::getType(void) const
{
    return (this->type);
}

void Dog::makeSound() const
{
    std::cout<<"DOG: WAOUFFFFFFFF ..."<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Destructor for ~Dog is called !!"<<std::endl;
}