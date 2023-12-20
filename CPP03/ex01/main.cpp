/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:51:53 by ihama             #+#    #+#             */
/*   Updated: 2023/12/14 17:13:53 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // Test ScavTrap
    ScavTrap scavtrap("Kaïdo");

        std::cout<<"NAME : " << scavtrap.getName() <<std::endl;
    std::cout<<"Hit point : " << scavtrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << scavtrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< scavtrap.getAttackPoint() <<std::endl;
    
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);
    scavtrap.attack("One Piece");
    scavtrap.guardGate();  // New ScavTrap function

    //Display updated state
    std::cout<<"\nupdated state :" <<std::endl;
    std::cout<<"NAME : " << scavtrap.getName() <<std::endl;
    std::cout<<"Hit point : " << scavtrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << scavtrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< scavtrap.getAttackPoint() <<std::endl;
    return 0;
}