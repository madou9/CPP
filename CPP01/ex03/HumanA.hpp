/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:17 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 11:50:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
    HumanA(); //constructor
    HumanA(std::string userName, Weapon& newArm); //overload contructor
    ~HumanA(); // destructor
    //methode
    void attack();

    private:
    std::string name;
    Weapon& weapon;
};
