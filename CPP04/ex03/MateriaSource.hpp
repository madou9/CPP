/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:22:39 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 16:09:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

/*
    • learnMateria(AMateria*)
    Copies the Materia passed as a parameter and store it in memory so it can 
    be cloned later. Like the Character, the MateriaSource can know at most 4 
    Materias. They are not necessarily unique.
*/

class MateriaSource : public IMateriaSource
{
private:
    /* data */
    AMateria* _learn[4];
public:
    MateriaSource(/* args */);
    MateriaSource(const MateriaSource& reff);
    MateriaSource& operator=(const MateriaSource& other);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const &type);
    ~MateriaSource();
};
