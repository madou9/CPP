/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:58:22 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:22:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(/* args */): AMateria("ice")
{
    std::cout<<"Default constructor for Ice is called!!"<<std::endl;
}
Ice::Ice(const Ice& reff) : AMateria("ice")
{
    *this = reff;
    std::cout<<"copy constructor for Cure called"<<std::endl;
}
Ice &Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

/*
    Cure(*this): This uses the copy constructor of the Cure class to create a new Cure object that is a copy of the current object.
    new Cure(*this): This dynamically allocates memory for a new Cure object on the heap and initializes it with a copy of the current object.
    return new Cure(*this);: This returns a pointer to the newly created Cure 
*/

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout<<"* shoots an ice bolt at "<< target.getName() << "*" <<std::endl;
}

Ice::~Ice()
{
    std::cout<<"Destructor for ~Ice called!!"<<std::endl; 
}