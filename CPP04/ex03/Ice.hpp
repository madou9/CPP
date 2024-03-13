/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:58:30 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 16:21:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
    /* data */
public:
    Ice(/* args */);
    Ice(const Ice& reff);
    Ice& operator=(const Ice& other);
    virtual AMateria* clone() const;

    virtual void use(ICharacter& target);
    ~Ice();
};
