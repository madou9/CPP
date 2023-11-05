/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:29 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 11:49:36 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType(void);
    void setType(std::string type);
};

