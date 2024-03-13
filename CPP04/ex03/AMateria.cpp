/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:38:35 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:22:30 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

AMateria::AMateria(std:: string const & type): _type(type)
{
    std::cout<<"Default constructor for " <<this->_type << " is called!!"<<std::endl;
}
AMateria::AMateria(const AMateria& reff): _type(reff._type){}

AMateria &AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->_type = other.getType();
    }
    return *this;
}
std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout<<"AMateria used on" << target.getName() << std::endl;
}

AMateria::~AMateria()
{
    std::cout<<"Destructor for ~AMateria is called!!"<<std::endl;
}