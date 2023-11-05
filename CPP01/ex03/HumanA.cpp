/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:14 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 18:15:35 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string userName, Weapon& newArm): name(userName), weapon(newArm)
{
}
HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout<<this->name << " attacks with their " << this->weapon.getType() << std::endl;
}