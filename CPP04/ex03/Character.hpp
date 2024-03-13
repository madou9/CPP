/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:32:41 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:55:00 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class AMateria;

class Character : public ICharacter
{
private:
    /* data */
    std::string _name;
    AMateria* inventory[4];
public:
    Character(std::string const& name);
    Character(const Character& reff);
    Character& operator=(const Character& other);

    virtual std::string const & getName() const; 
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    ~Character();
};
