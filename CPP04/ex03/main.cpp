/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:37:30 by ihama             #+#    #+#             */
/*   Updated: 2024/01/01 17:30:18 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() 
{
    std::cout << "------------------------------------------------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice"); //creates a new "Ice" materia using the createMateria method of src and assigns it to tmp
    me->equip(tmp); // equips the character with the "Ice" materia.
    tmp = src->createMateria("cure"); //creates a new "Cure" materia and assigns it to tmp
    me->equip(tmp);
    ICharacter* bob = new Character("bob");  //reates another character named "bob".
    me->use(0, *bob); // makes the character "me" use the materia in the first slot on the character "bob".
    me->use(1, *bob); // makes the character "me" use the materia in the second slot on the character "bob".
    delete bob; delete me; delete src;
    std::cout << "------------------------------------------------" << std::endl;
    // system("leaks AMateria");
    return 0;
}

//Should output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at bob *$ 
//  * heals bob's wounds *$