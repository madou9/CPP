/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:29:08 by ihama             #+#    #+#             */
/*   Updated: 2024/03/07 12:49:50 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

void    testPtr()
{
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Lest's check Condition for Base*" <<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    Base*ptrList[10];
    for (int i = 0; i < 10; ++i) ptrList[i] = generate();
    for (int i = 0; i < 10; ++i) identify(ptrList[i]);
    for (int i = 0; i < 10; ++i) delete ptrList[i];
    std::cout<<"-------------------------------"<<std::endl;
    std::cout<<"End of the Condition for Base*" <<std::endl;
    std::cout<<"-------------------------------"<<std::endl;
}

void    testRef()
{
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Lest's check Condition for Base&" <<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    Base* ptrList[10];
    for (int i = 0; i < 10; ++i) ptrList[i] = generate();
    for (int i = 0; i < 10; ++i) identify(*ptrList[i]);
    for (int i = 0; i < 10; ++i) delete ptrList[i];
    std::cout<<"-------------------------------"<<std::endl;
    std::cout<<"End of the Condition for Base&" <<std::endl;
    std::cout<<"-------------------------------"<<std::endl;
}

int main()
{
    testPtr();
    std::cout<<"\n"<<std::endl;
    testRef();
    // system("leaks Base");
    return 0;
}

