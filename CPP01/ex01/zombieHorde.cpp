/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:47:05 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 18:00:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    /*Dynamic Memory Allocation for Objects 
    If you were to allocate an array of four Hordeee objects, 
    the Simple constructor would be called fou
    times and similarly while deleting these objects, 
    destructor will also be called same number of times.*/
    Zombie* Hordeee = new Zombie[N];

    for (size_t i = 0; i < N; i++)
    {
        //set for each name Hallooo
        Hordeee[i].stName(name);
    }
    return (Hordeee);
}