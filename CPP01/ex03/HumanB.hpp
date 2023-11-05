/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:23 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 11:51:06 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:
    HumanB(); // constructor
    HumanB(std::string userName); // overload
    ~HumanB(); // destructor
    //methode
    void attack();
    void setWeapon(Weapon &arm);
    private:
    std::string name;
    Weapon* weapon;
};
