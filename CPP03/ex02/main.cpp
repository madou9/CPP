/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:51:53 by ihama             #+#    #+#             */
/*   Updated: 2023/12/15 14:16:41 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    // Test frap
    FragTrap frap("Kaïdo");

        std::cout<<"NAME : " << frap.getName() <<std::endl;
    std::cout<<"Hit point : " << frap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << frap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< frap.getAttackPoint() <<std::endl;
    
    frap.takeDamage(10);
    frap.beRepaired(5);
    frap.attack("One Piece");
    frap.highFivesGuys();  // New frap function

    //Display updated state
    std::cout<<"\nupdated state :" <<std::endl;
    std::cout<<"NAME : " << frap.getName() <<std::endl;
    std::cout<<"Hit point : " << frap.getHitPoint() << std::endl;
    std::cout<<"Energy Point : " << frap.getEnergyPoint() <<std::endl;
    std::cout<<"Attack Point : "<< frap.getAttackPoint() <<std::endl;
    return 0;
}