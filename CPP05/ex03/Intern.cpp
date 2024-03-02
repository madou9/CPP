/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:25:25 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 18:05:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(/* args */)
{
     std::cout<<"Default for Intern called"<<std::endl;
}
Intern::Intern(const Intern& copy){
    *this = copy;
}
Intern& Intern::operator=(const Intern& other){
    if (this != &other)
    {  
       return *this; 
    }
    return *this;
}

// Member function
AForm *Intern::makeForm(const std::string formName, const std::string targetFrom)
{
    int i;

    std::string checkFormAvailable[] = {"\033[1;31m shrubbery creation \033[0m", "\033[1;31m robotomy request \033[0m", "\033[1;31m presidential pardon \033[0m"};
    i = 0;
    do {
        if (formName == checkFormAvailable[i]) {
            switch (i) {
                case 0:
                    std::cout << "\033[1;31mGreat \033[0m Intern create " << formName << " with Target... " << std::endl;
                    return new ShrubberyCreationForm(targetFrom);
                case 1:
                    std::cout << "\033[1;31mGreat \033[0m Intern create " << formName << "with Target... " << std::endl;
                    return new RobotomyRequestForm(targetFrom);
                case 2:
                    std::cout << "\033[1;31mGreat \033[0m Intern create " << formName << " with Target... " << std::endl;
                    return new PresidentialPardonForm(targetFrom);
            }
        }
        i++;
    } while (i < 3);
    
    std::cout << "Form is not existing" << std::endl;
    return NULL;
}


Intern::~Intern()
{
    std::cout<<"Destructor for Intern called"<<std::endl;
}