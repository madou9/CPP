/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:17:04 by ihama             #+#    #+#             */
/*   Updated: 2024/01/01 17:26:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // exercice 01
    std::cout<<"------------------------------------------------" << std::endl;
    const Animal *animalArray[5];
    size_t i;
    // Populate with Dog objects
    i = 0;
    while (i < 2)
    {
        /* code */
        animalArray[i] = new Dog();
        i++;
    }
    i = 2;
    while (i < 5)
    {
        /* code */
        animalArray[i] = new Cat();
        i++;
    }
    std::cout<<"------------------------------------------------" << std::endl;
    // Make sounds for each animal
    // in  = incre...
    for (size_t in = 0; in < 5; in++)
        animalArray[in]->makeSound();
    std::cout<<"------------------------------------------------" << std::endl;
    // Delete all objects
    // mt = ment;
    for (int mt = 0; mt < 5; mt++)
        delete animalArray[mt];
    std::cout<<"------------------------------------------------" << std::endl;
    // system("leaks Brain");
    return 0;
}
