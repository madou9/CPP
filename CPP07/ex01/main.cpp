/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:19:41 by ihama             #+#    #+#             */
/*   Updated: 2024/03/11 15:18:26 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int tabArray[] = {1, 2, 3, 4, 5};
    double tabArray1[] = {1, 2, 3, 4, 5};
    std::cout<<"--------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Start with Print with specifique data type argument like printMessage(int array)"<<std::endl;
    std::cout<<"--------------------------------------------------------------------------------"<<std::endl;

    iter(tabArray, 5, printMessage);

    std::cout<<"--------------------------------------"<<std::endl;
    std::cout<<"End of Print with specifique data type"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;

    std::cout<<"\n"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Start with Print without specifique data type type argument like printMessage(T array)"<<std::endl;
    std::cout<<"--------------------------------------------------------------------------------------"<<std::endl;
    iter(tabArray1, 5, printMessage);
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"End with Print without specifique data type"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;
}