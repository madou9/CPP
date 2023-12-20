/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:58:01 by ihama             #+#    #+#             */
/*   Updated: 2023/12/19 14:20:10 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* Initialize all my Class to get the same name */
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    FragTrap::_hitPoint = 100; // Use the hitPoint from FragTrap
    ScavTrap::_EnergyPoint = 50; // Use the EnergyPoint from ScavTrap
    FragTrap::_attackDamage = 30;  // Use the attackDamage from FragTrap
    std::cout<<"Default constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    _name = other._name;
    std::cout << "DiamondTrap " << _name << " has been cloned!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
        std::cout << "DiamondTrap " << _name << " has been reassigned!" << std::endl;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "[whoAmI] "<< "I am " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor for DiamondTrap is called and is out of the action " << std::endl;
}
