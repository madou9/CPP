/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:08:34 by ihama             #+#    #+#             */
/*   Updated: 2023/12/19 13:10:25 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name): _Name(Name), _hitPoint(10), _EnergyPoint(10), _attackDamage(0)
{
    std::cout<<"Default constructor for ClapTrap called"<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) :_Name(other._Name), _hitPoint(other._hitPoint), _EnergyPoint(other._EnergyPoint), _attackDamage(other._attackDamage)
{
    std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        std::cout << "ClapTrap " << _Name << " has been assigned!" << std::endl;
        ClapTrap::_Name = other._Name;
        ClapTrap::_hitPoint = other._hitPoint;
        ClapTrap::_EnergyPoint = other._EnergyPoint;
        ClapTrap::_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << _Name <<" attack " << target <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint > 0)
    {
        ClapTrap::_hitPoint -= amount;
        std::cout<< _Name << " takes -" << amount << " points of damage!" <<std::endl;
    }
    else
        std::cout<< _Name <<" is already out of the action" << std::endl;

}

/* Hit Point going to be 10 -6 = 4 + 3 = 7 and Energy -1 = 10 - 1 = 9 */
void ClapTrap::beRepaired(unsigned int amount)
{
    if ( _EnergyPoint > 0)
    {
        ClapTrap::_EnergyPoint--;
        ClapTrap::_hitPoint += amount;
        std::cout<<"ClapTrap " << _Name << " is being repaired, gaining +" << amount << " hit point!" <<std::endl;
    }
    else
        std::cout<<"ClapTrap " << _Name << " can't be repaired. No hit points or energy left." << std::endl;
}

const std::string& ClapTrap::getName() const
{
    return (ClapTrap::_Name);
}

int ClapTrap::getHitPoint() const
{
    return (ClapTrap::_hitPoint); 
}

int ClapTrap::getEnergyPoint() const
{
    return (ClapTrap::_EnergyPoint);
}

int ClapTrap::getAttackPoint() const
{
    return (ClapTrap::_attackDamage);
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Destructor for ClapTrap called and is out of the action" << std::endl;
}
