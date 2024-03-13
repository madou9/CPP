/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:59:36 by ihama             #+#    #+#             */
/*   Updated: 2023/12/23 23:11:56 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    /* data */
    std::string type;
public:
    WrongAnimal(/* args */);
    WrongAnimal(const WrongAnimal& ref);
    WrongAnimal& operator=(const WrongAnimal& ress);
    ~WrongAnimal();

    std::string getType(void) const;
    virtual void makeSound() const;
};
