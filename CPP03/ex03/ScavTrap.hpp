/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:16:10 by ihama             #+#    #+#             */
/*   Updated: 2023/12/17 15:17:42 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/*
    virtual can be written before or after the public. Now only one copy of data/function member 
    will be copied to class FragTrap and class ScavTrap and class ClapTrap becomes the virtual base class.
    Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances.
*/

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);

        void guardGate();
        void attack(const std::string& target);
        ~ScavTrap();
};


