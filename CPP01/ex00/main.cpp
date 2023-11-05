/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:54 by ihama             #+#    #+#             */
/*   Updated: 2023/10/31 16:40:07 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("Ado");
    zombie->announce();
    randomChump("didi");
    delete zombie;
    return (0);
}