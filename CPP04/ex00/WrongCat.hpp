/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:59:30 by ihama             #+#    #+#             */
/*   Updated: 2023/12/23 23:12:15 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(/* args */);
        WrongCat(const WrongCat& ref);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();

        void makeSound() const;
        std::string getType(void) const;
};
