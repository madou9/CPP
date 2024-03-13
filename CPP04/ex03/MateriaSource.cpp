/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:22:19 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:47:27 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*
    • _learn(AMateria*)
    Copies the Materia passed as a parameter and store it in memory so it can 
    be cloned later. Like the Character, the MateriaSource can know at most 4 
    Materias. They are not necessarily unique.
*/
/*
    createMateria(std::string const &)
    Returns a new Materia. The latter is a copy of the Materia previously 
    learned by the MateriaSource whose type equals the one passed as parameter. 
    Returns 0 if the type is unknown.
*/

MateriaSource::MateriaSource(/* args */)
{
 std::cout<<"Default constructor for MateriaSource called!!"<<std::endl;
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        _learn[i] = nullptr;
    }
}
/*
    Copy Constructor: Copies the content of another MateriaSource instance. It performs a deep 
    copy by cloning each material using the clone() method. Prints a message indicating that the 
    copy constructor is called.
*/

/*
    The _learn array is a private member of the MateriaSource class, and it stores pointers to 
    instances of AMateria (or its derived classes).The use of clone() ensures that new instances 
    are created, preventing issues with shallow copies.
*/
MateriaSource::MateriaSource(const MateriaSource& reff)
{
 std::cout<<"copy constructor for MateriaSource is called!!"<<std::endl;
    size_t count = 4;
    int i = 0;
    while (i < count)
    {
        if (_learn[i] != nullptr)
            delete _learn[i];
        _learn[i] = nullptr;
        if (reff._learn[i] != nullptr)
            _learn[i] = reff._learn[i]->clone();
        else
            _learn[i] = nullptr;
        i++;
    }
    // for (size_t i = 0; i < count; i++)
    //     {
    //         if (_learn[i] != nullptr)
    //             delete _learn[i];
    //         _learn[i] = nullptr;
    //         if (reff._learn[i] != nullptr)
    //             _learn[i] = reff._learn[i]->clone();
    //         else
    //             _learn[i] = nullptr;
    //     }
}

/*
    Copy Assignment Operator: Assigns the content of another MateriaSource instance to the current instance. 
    Similar to the copy constructor, it performs a deep copy and releases the existing resources. Returns a 
    reference to the current instance.
*/
MateriaSource&  MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        size_t count = 4;
        int i = 0;
        while (i < count)
        {
            if (_learn[i] != nullptr)
                delete _learn[i];
            _learn[i] = nullptr;
            if (other._learn[i] != nullptr)
                _learn[i] = other._learn[i]->clone();
            else
                _learn[i] = nullptr;
            i++;
        }
        
    }
    return *this; 
}

/*
    Learn Materia Method: Adds a new material to the _learn array. It checks 
    for the first empty slot and stores the material.If all slots are occupied, 
    it does nothing. This method is used to learn new "templates" of Materias.
*/

void MateriaSource::learnMateria(AMateria* m)
{
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
    {
        if (!_learn[i])
        {
            _learn[i] = m;
            return ;
        }
    }
}
/*
    Create Materia Method: Creates a new material based on the provided type. It searches through the _learn array 
    for a material with a matching type. If found, it returns a clone of that material; otherwise, it returns nullptr.
*/

AMateria* MateriaSource::createMateria(std::string const &type)
{
    size_t count = 4;
    int i = 0;
    while (i < count)
    {
        if (_learn[i] && _learn[i]->getType() == type)
               return _learn[i]->clone();
        i++;
    }
    return nullptr;
    
}

MateriaSource::~MateriaSource()
{
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
    {
        delete _learn[i];
    }
    std::cout<<"Destructor for the ~MateriaSource is called!!"<<std::endl;
}