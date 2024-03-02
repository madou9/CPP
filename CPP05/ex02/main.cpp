/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:51 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 18:52:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        // Create forms
        AForm* shrubberyForm = new ShrubberyCreationForm("createTrees");
        AForm* pardonForm = new PresidentialPardonForm("\033[1;31m being late \033[0m");
        AForm* robotomyForm = new RobotomyRequestForm("\033[1;31m trees \033[0m");

        // Create bureaucrats
        Bureaucrat* smallBureaucrat = 0;
        Bureaucrat* mediumBureaucrat = 0;
        Bureaucrat* bigBureaucrat = 0;

        std::cout<<"-----------------------------" << std::endl;
        std::cout<<"test for Ex02 Grade" << std::endl;
        std::cout<<"-----------------------------" << std::endl;
        try {
            smallBureaucrat = new Bureaucrat("\033[1;31m Tankooo \033[0m", 130);
            mediumBureaucrat = new Bureaucrat("\033[1;31m Mousssa \033[0m", 40);
            bigBureaucrat = new Bureaucrat("\033[1;31m Ali \033[0m", 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            delete shrubberyForm;
            delete pardonForm;
            delete robotomyForm;
            delete smallBureaucrat;
            delete mediumBureaucrat;
            delete bigBureaucrat;
        }

        // Sign forms
                std::cout<<"\n" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        std::cout<<"test for signForm in Ex02" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        try {
            smallBureaucrat->signForm(shrubberyForm);
            mediumBureaucrat->signForm(robotomyForm);
            bigBureaucrat->signForm(pardonForm);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            delete shrubberyForm;
            delete pardonForm;
            delete robotomyForm;
            delete smallBureaucrat;
            delete mediumBureaucrat;
            delete bigBureaucrat;
        }

        // Execute forms
                std::cout<<"\n" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        std::cout<<"test for makeForm in Ex02" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        try {
            smallBureaucrat->executeForm(shrubberyForm);
            mediumBureaucrat->executeForm(robotomyForm);
            bigBureaucrat->executeForm(pardonForm);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            delete shrubberyForm;
            delete pardonForm;
            delete robotomyForm;
            delete smallBureaucrat;
            delete mediumBureaucrat;
            delete bigBureaucrat;
        }

        std::cout<<"\n" << std::endl;
        std::cout<<"-----------------------------" << std::endl;
        std::cout<<"End test for Ex02 Grade" << std::endl;
        std::cout<<"-----------------------------" << std::endl;

        // Clean up allocated memory
        delete shrubberyForm;
        delete pardonForm;
        delete robotomyForm;
        delete smallBureaucrat;
        delete mediumBureaucrat;
        delete bigBureaucrat;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // system("leaks AForm");
    return 0;
}
