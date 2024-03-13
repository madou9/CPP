/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:55 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 19:14:52 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
private:
    /* data */
public:
    Dog(/* args */);
    Dog(const Dog& ref);
    Dog& operator=(const Dog& other);
    ~Dog();

    void makeSound() const;
    std::string getType(void) const;
};
