/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:26:22 by ihama             #+#    #+#             */
/*   Updated: 2023/12/17 15:17:28 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
    virtual can be written before or after the public. Now only one copy of data/function member 
    will be copied to class FragTrap and class ScavTrap and class ClapTrap becomes the virtual base class.
    Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances.
*/
class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        void highFivesGuys(void);
};

