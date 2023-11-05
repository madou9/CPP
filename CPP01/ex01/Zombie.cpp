/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:49:01 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 17:59:23 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout<<"zombie " << this->_name << "created" << std::endl;
}

Zombie::Zombie(std:: string zomName): _name(zomName)
{
}

void Zombie::announce(void)
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::stName(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << "deleted" << std::endl;
}