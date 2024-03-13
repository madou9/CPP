/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:58:52 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:22:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(/* args */): AMateria("cure")
{
    std::cout<<"Default constructor for Cure is called!!"<<std::endl;
}
Cure::Cure(const Cure& reff): AMateria("cure")
{
    *this = reff;
    std::cout<<"copy constructor for Cure called"<<std::endl;
}
Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout<<"* heals "<< target.getName()<< "'s wounds *" <<std::endl;
}
/*
Cure(*this): This uses the copy constructor of the Cure class to create a new Cure object that is a copy of the current object.
new Cure(*this): This dynamically allocates memory for a new Cure object on the heap and initializes it with a copy of the current object.
return new Cure(*this);: This returns a pointer to the newly created Cure 
*/
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

Cure::~Cure()
{
    std::cout<<"Destructor for ~Cure is called!!"<<std::endl;
}