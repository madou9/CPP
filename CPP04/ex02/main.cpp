/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:17:04 by ihama             #+#    #+#             */
/*   Updated: 2024/01/01 17:27:35 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) 
{
    // Abstract class pointers
    std::cout << "------------------------------------------------" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    const WrongAnimal* WrongAn = new WrongAnimal();
    const WrongAnimal* WrongCa = new WrongCat();
    std::cout<<"Abstract class :" <<std::endl;
    std::cout << "------------------------------------------------" << std::endl;


    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 

    j->makeSound();
    std::cout << "Type of dog: " << j->getType() << std::endl;
    i->makeSound();
    std::cout << "Type of cat: " << i->getType() << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    
    std::cout<<"non abstract class :" <<std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    WrongAn->makeSound();
    std::cout << "Type of wrong animal: " << WrongAn->getType() << std::endl;
    WrongCa->makeSound();
    std::cout << "Type of wrong cat: " << WrongCa->getType() << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    delete WrongCa;
    delete WrongAn;
    delete i;
    delete j;
    std::cout << "------------------------------------------------" << std::endl;
    // system("leaks abstract");
    return 0;
}
