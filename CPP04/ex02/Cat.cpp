/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:47 by ihama             #+#    #+#             */
/*   Updated: 2023/12/26 19:59:47 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Upon construction, Dog and Cat will create their Brain using new Brain();
/*
    his dynamically allocates memory on the heap for a new Brain object 
    and assigns the address of this new object to the brain member.
    This process ensures that each Dog and Cat object has its own independent 
    Brain object. Each Brain object is created dynamically, and the responsibility 
    for deallocating the memory (using delete) lies with the destructors of Dog and Cat.
*/

Cat::Cat(/* args */): _brain(new Brain())
{
    std::cout<<"Default constructor for Cat is called !!"<<std::endl;
}

Cat::Cat(const Cat& ref): _brain(new Brain(*(ref._brain)))
{
    this->type = ref.getType();
    std::cout << "Copy constructor for Cat is called !!" << std::endl;
}

/*
    The new Brain object is a copy of the Brain object that the other object's brain member 
    is pointing to. This process ensures that each Dog object has its own independent copy 
    of the Brain object to avoid shallow copies, especially when copying Dog objects.
*/

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        delete Cat::_brain;
        this->type = other.type;
        _brain = new Brain(*(other._brain));
    }
    return *this;
}

std::string Cat::getType(void) const
{
    return (this->type);
}

Brain *Cat::getBrain(void) const
{
    return (this->_brain);
}

void Cat::makeSound() const
{
    std::cout<<"CAT : MÏÁWWWWWW ..."<<std::endl;
}

//Upon destruction, Dog and Cat will delete their Brain.
Cat::~Cat()
{
    delete Cat::_brain;
    std::cout<<"Destructor for ~Cat is called!!"<<std::endl;
}