/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:21:11 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 21:41:42 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/*
    An abstract class is a class that is designed to be specifically used as a 
    base class. An abstract class contains at least one pure virtual function. 
    You declare a pure virtual function by using a pure specifier ( = 0 ) in the 
    declaration of a virtual member function in the class declaration.
*/

/*
    The following is an example of an abstract class:
    class AB 
    {
        public:
        virtual void f() = 0;
    };
*/

class AAnimal
{
protected:
    /* data */
    std::string type;
public:
    AAnimal(/* args */);
    AAnimal(std::string tp);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual std::string getType(void) const = 0;
    virtual void makeSound() const = 0;
    virtual ~AAnimal() = 0;
};

