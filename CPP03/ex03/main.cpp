/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:51:53 by ihama             #+#    #+#             */
/*   Updated: 2023/12/19 14:10:58 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("Hama");
    std::cout<<"\n initialise state :" <<std::endl;
    std::cout<<"NAME : " << diamondTrap.getName() <<std::endl;
    std::cout<<"Hit point : " << diamondTrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << diamondTrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< diamondTrap.getAttackPoint() <<std::endl;
    std::cout<<"\n" <<std::endl;
    // Specify the attack from FragTrap
    diamondTrap.FragTrap::attack("One Piece");

    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);

    // Specify the guardGate from ScavTrap
    diamondTrap.ScavTrap::guardGate();

    //Specify the guardGate from FragTrap
    diamondTrap.FragTrap::highFivesGuys();  // New frap function

    // Call DiamondTrap's whoAmI
    diamondTrap.whoAmI();

        std::cout<<"\nupdated state :" <<std::endl;
    std::cout<<"NAME : " << diamondTrap.getName() <<std::endl;
    std::cout<<"Hit point : " << diamondTrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << diamondTrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< diamondTrap.getAttackPoint() <<std::endl;

    return 0;
}
