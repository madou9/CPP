/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:26 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 18:34:09 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){}

Weapon::~Weapon(){}

const std::string &Weapon::getType(void)
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}