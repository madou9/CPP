/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:27:30 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 09:49:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout<<"[DEBUG]->: ";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout<<"[INFO]->: ";
    std::cout<< "I cannot believe adding extra bacon costs more money. You didn’t put \
    enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout<<"[WARNING]->: ";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
    years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout<<"[ERROR]->: ";
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    std::string eachLevel[4] = {"debug", "info", "warning", "error"};
    //function pointeur 
    // void (*f[4]()) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    // Define a type alias for a pointer to member function
    // std::string eachLevel[4] = {"debug", "info", "warning", "error"};
    ComplaintFunction complaints[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (eachLevel[i].compare(level) == 0)
        {
            (this->*complaints[i])();
            break;
        }
    }    
}

void Harl::filterComplain(std::string level)
{
    std::string eachLevel[4] = {"debug", "info", "warning", "error"};
    ComplaintFunction complaints[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (eachLevel[i].compare(level) == 0)
        {
            switch (i)
            {
            case 0:
                (this->*complaints[0])();
            case 1:
                (this->*complaints[1])();
            case 2:
                (this->*complaints[2])();
            case 3:
                (this->*complaints[3])();
                break;
            default:
            std::cout<<"I am not sure how tired I am today..."<<std::endl;
            }
        }
    }
}
