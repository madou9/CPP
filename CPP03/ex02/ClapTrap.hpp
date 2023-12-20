/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:08:21 by ihama             #+#    #+#             */
/*   Updated: 2023/12/19 13:26:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
    /* data */
    std::string _Name; //Name, which is passed as parameter to a constructor
    int _hitPoint; //Hit points (10), represent the health of the ClapTrap
    int _EnergyPoint; //Energy points (10)
    int _attackDamage; //Attack damage (0)
    
public:
    ClapTrap(std::string Name);
    // ClapTrap(std::string name, int  hitpoint, int  energypoint, int  attackdamage);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string& getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackPoint() const;
};
// std::ostream& operator<<(std::ostream& os, const ClapTrap& clap);