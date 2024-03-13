/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:53 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 21:06:20 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Upon construction, Dog and Cat will create their Brain using new Brain();
/*
    his dynamically allocates memory on the heap for a new Brain object 
    and assigns the address of this new object to the brain member.
    This process ensures that each Dog and Cat object has its own independent 
    Brain object. Each Brain object is created dynamically, and the responsibility 
    for deallocating the memory (using delete) lies with the destructors of Dog and Cat.
*/

Dog::Dog() : _brain(new Brain())
{
    std::cout<<"Default constructor for Dog is called !!"<<std::endl; 
}

//  Upon destruction, Dog and Cat will delete their Brain.
Dog::~Dog()
{
    delete Dog::_brain;
    std::cout<<"Destructor for ~Dog is called !!"<<std::endl;
}

Dog::Dog(const Dog& ref): _brain(new Brain(*(ref._brain)))
{
    this->type = ref.getType();
}

/*
    The new Brain object is a copy of the Brain object that the other object's brain member 
    is pointing to. This process ensures that each Dog object has its own independent copy 
    of the Brain object to avoid shallow copies, especially when copying Dog objects.
*/

Dog &Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        delete Dog::_brain;
        this->type = other.type;
        _brain = new Brain(*(other._brain));
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

Brain *Dog::getBrain(void) const
{
    return (this->_brain);
}

