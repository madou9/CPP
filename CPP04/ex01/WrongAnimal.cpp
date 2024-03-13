/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:59:41 by ihama             #+#    #+#             */
/*   Updated: 2023/12/23 23:20:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
    std::cout<<"Default constructor for WrongAnimal is called !!"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
    this->type = ref.getType();
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& ress)
{
    if (this != &ress)
    {
        this->type = ress.type;
    }
    return *this;
}

std::string WrongAnimal::getType(void) const 
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout<<"wrong animal"<<std::endl; 
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"Destructor for ~WrongAnimal is called !!"<<std::endl;
}