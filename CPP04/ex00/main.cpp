/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:17:04 by ihama             #+#    #+#             */
/*   Updated: 2024/01/01 17:25:24 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) 
{
    std::cout << "------------------------------------------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* WrongAn = new WrongAnimal();
    const WrongAnimal* WrongCa = new WrongCat();

    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << "------------------------------------------------" << std::endl;
    WrongAn->makeSound();
    std::cout << "Type of wrong animal: " << WrongAn->getType() << std::endl;
    WrongCa->makeSound();
    std::cout << "Type of wrong cat: " << WrongCa->getType() << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    delete WrongCa;
    delete WrongAn;
    delete meta;
    delete i;
    delete j;
    std::cout << "------------------------------------------------" << std::endl;
    // system("leaks Polymorphism");
    return 0;
}
