/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:08:02 by ihama             #+#    #+#             */
/*   Updated: 2023/12/14 15:07:00 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap ClapTrap("One Piece");

    //Display the initial state
    std::cout<<"initial state :" <<std::endl;
    std::cout<<"NAME : " << ClapTrap.getName() <<std::endl;
    std::cout<<"Hit point : " << ClapTrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << ClapTrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< ClapTrap.getAttackPoint() <<std::endl;

    //Test Attack, takeDamage, and beRepaired
    ClapTrap.attack("Kaïdo");
    ClapTrap.takeDamage(6);
    ClapTrap.beRepaired(3);

    //Display updated state
    std::cout<<"\nupdated state :" <<std::endl;
    std::cout<<"NAME : " << ClapTrap.getName() <<std::endl;
    std::cout<<"Hit point : " << ClapTrap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << ClapTrap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< ClapTrap.getAttackPoint() <<std::endl;

}
