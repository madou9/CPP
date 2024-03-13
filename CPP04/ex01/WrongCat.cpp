/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:59:33 by ihama             #+#    #+#             */
/*   Updated: 2023/12/23 23:12:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
    std::cout<<"Default constructor for WrongCat is called !!"<<std::endl;    
}
WrongCat::WrongCat(const WrongCat& ref)
{
    this->type = ref.getType();
}
WrongCat &WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout<<"WrongCat .."<<std::endl;
}

std::string WrongCat::getType(void) const 
{
    return (this->type);
}

WrongCat::~WrongCat()
{
    std::cout<<"Destructor for ~WrongCat is called !!"<<std::endl;
}