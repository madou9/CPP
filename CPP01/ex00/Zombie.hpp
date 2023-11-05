/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:48 by ihama             #+#    #+#             */
/*   Updated: 2023/10/31 16:31:05 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
    public:

    Zombie(); //constructor
    Zombie(std::string name); // overload
    ~Zombie(); // destructor

    //Methode
    void announce(void);

    private:
    std:: string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif