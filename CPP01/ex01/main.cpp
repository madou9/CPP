/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:46:19 by ihama             #+#    #+#             */
/*   Updated: 2023/11/01 15:41:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *Hordeee;

    int size = 5;
    Hordeee = zombieHorde(size, "Hallooo");
    for (int i = 0; i < size; i++)
    {
        Hordeee[i].announce();
    }
    delete [] Hordeee;
}