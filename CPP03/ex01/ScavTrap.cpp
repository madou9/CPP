/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:26:28 by ihama             #+#    #+#             */
/*   Updated: 2023/12/14 17:39:26 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

 // Use initialization list for base class constructor
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_EnergyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "Default constructor for ScavTrap called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<getName()<<" is now in get keeper mode "<<std::endl;
}

// Call base class copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _Name << " has been cloned for guarding!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << _Name << " has been reassigned for guarding!" << std::endl;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_EnergyPoint > 0)
    {
        _EnergyPoint--;
        std::cout << getName() <<" attack " << target <<std::endl;
    }
}

ScavTrap::~ScavTrap()
{
    std::cout<<"Destructor for ScavTrap is called and is out of the action" << std::endl;
}
