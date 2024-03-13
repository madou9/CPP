/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:58:55 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 16:23:10 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    /* data */
public:
    Cure(/* args */);
    Cure(const Cure& reff);
    Cure& operator=(const Cure& other);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
    ~Cure();
};
