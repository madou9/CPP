/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:16:59 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 21:10:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/*
    The virtual keyword is used to declare a member function as virtual. In C++, 
    virtual functions enable polymorphism, allowing derived classes to provide their 
    own implementation of the function.
*/

class Animal
{
protected:
    /* data */
    std::string type;
public:
    Animal(/* args */);
    Animal(std::string tp);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    std::string getType(void) const;
    virtual void makeSound() const;
    /*
        Virtual destructor:
        Every destructor down gets called no matter what. virtual makes sure it
        starts at the top instead of the middle.

        Virtual destructors are useful when you might potentially delete an instance 
        of a derived class through a pointer to base class:
    */
    virtual ~Animal();
};
// Overload the insertion operator
// std::ostream& operator<<(std::ostream& os, const Animal fixed);
