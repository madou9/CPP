/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:32:46 by ihama             #+#    #+#             */
/*   Updated: 2023/12/28 17:55:13 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
    The Character possesses an inventory of 4 slots, which means 4 Materias at most. The inventory is empty at construction
*/
/*
    Initializes the _name attribute with the provided name.
    Initializes the inventory array with nullptr pointers (4 slots).
    Prints a message indicating that the default constructor for Character has been called.
*/
Character::Character(std::string const& name) : _name(name)
{
    std::cout<<"Default constructor for Character called!!"<<std::endl;
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
    {
        inventory[i] = nullptr;
    }
    
}
/*
    Copy Constructor (Character::Character(const Character& other)):
    Performs a deep copy of the Character object.
    Copies the name.
    For each slot in the inventory:
    If the source Character has a Materia in that slot, clone it and assign the clone to the current Character's inventory.
    If the source Character has no Materia in that slot, assign nullptr to the current Character's inventory.
*/

Character::Character(const Character& reff): _name(reff._name)
{
    std::cout<<"copy constructor for Character is called!!"<<std::endl;
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = nullptr;
            if (reff.inventory[i])
                inventory[i] = reff.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
}
/*
    During copy, the Materias of a Character must be deleted before 
    the new ones are added to their inventory. Of course, the Materias 
    must be deleted when a Character is destroyed.
*/

/*
    Copy Assignment Operator (Character& Character::operator=(const Character& other)):

    Performs a deep copy, similar to the copy constructor.
    Deletes existing Materias in the current Character's inventory before copying.
*/
Character &Character::operator=(const Character& other)
{
    size_t count = 4;

    if (this != &other)
    {
        this->_name = other._name;
        for (size_t i = 0; i < count; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = nullptr;
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
    }
    return *this;
}

/*
    Adds a Materia to the character's inventory.
    Finds the first empty slot in the inventory and assigns the Materia to that slot.
*/

void Character::equip(AMateria* m)
{
    size_t count = 4;
    for (size_t i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            std::cout << "Character " <<Character::_name << " equipped with " << m->getType() << std::endl;
            inventory[i] = m;
            return ;

        }
    }
    
}
/*
    Do nothing, but don't delete the Materia
    Unequipping doesn't delete the Materia, just removes the reference
*/
//The unequip() member function must NOT delete the Materia!

void Character::unequip(int idx)
{
    if (idx >=0 && idx < 4)
        inventory[idx] = nullptr;
}
/*
    The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], 
    and pass the target parameter to the AMateria::use function.
*/

/*
    Uses the Materia at the specified index in the inventory.
    Calls the use function of the Materia, passing the target ICharacter as a parameter.
*/
void Character::use(int idx, ICharacter& target)
{
     if (idx >=0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
 
std::string const& Character::getName() const
{
    return this->_name;
}

Character::~Character()
{
    size_t count = 4;
    for (size_t i = 0; i < count; i++)
    {
        delete inventory[i];
    }
    std::cout<<"Destructor for ~Character is called!!"<<std::endl;
}