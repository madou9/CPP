/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:47 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 20:14:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(/* args */): Animal("cat")
{
    std::cout<<"Default constructor for Cat is called !!"<<std::endl;
}

Cat::Cat(const Cat& ref)
{
    this->type = ref.getType();
}

/*
    if (this != &other): This check ensures that you are not assigning an object to itself
    If the address of the current object (this) is not equal to the address of the other object (&other), 
    then the assignment proceeds. This check is essential to avoid self-assignment issues and unnecessary work.
*/

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
std::string Cat::getType(void) const
{
    return (this->type);
}
void Cat::makeSound() const
{
    std::cout<<"CAT : MÏÁWWWWWW ..."<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Destructor for ~Cat is called!!"<<std::endl;
}