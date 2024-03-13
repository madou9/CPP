/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:31:49 by ihama             #+#    #+#             */
/*   Updated: 2023/12/29 20:34:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
private:
    /* data */
    Brain* _brain;
public:
    Cat(/* args */);
    Cat(const Cat& ref);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
    std::string getType(void) const;
    Brain* getBrain(void) const;
};
