/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:49:08 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 17:46:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
    Zombie();
    Zombie(std::string zomName);
    ~Zombie();
    //
    void announce(void);
    void stName(std::string zombieName);

    private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif