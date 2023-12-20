/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:26:11 by ihama             #+#    #+#             */
/*   Updated: 2023/12/15 14:13:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_EnergyPoint = 100;
    this->_attackDamage = 30;
    std::cout<<"Default constructor for FragTrap called"<<std::endl;
}

// Call base class copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _Name << " has been cloned for guarding!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << _Name << " has been reassigned for guarding!" << std::endl;
    }
    return *this;
}
 void FragTrap::highFivesGuys(void)
 {
    std::cout<<"FragTrap " << getName() << "is asking for high fives!" <<std::endl;
 }

FragTrap::~FragTrap()
{
    std::cout<<"Destructor for FragTrap is called and is out of the action"<<std::endl;
}