/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:51 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 18:51:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
        // Create forms
        AForm* shrubberyForm = new ShrubberyCreationForm("createTrees");
        AForm* pardonForm = new PresidentialPardonForm("\033[1;31m being late \033[0m");
        AForm* robotomyForm = new RobotomyRequestForm("\033[1;31m trees \033[0m");

        std::cout<<"-----------------------------" << std::endl;
        std::cout<<"test for Ex03 Grade" << std::endl;
        std::cout<<"-----------------------------" << std::endl;
    try {
        // Create Intern
        Intern wellPaidIntern;

        // Create bureaucrats
        Bureaucrat* smallBureaucrat = new Bureaucrat("\033[1;31m Tankooo \033[0m", 130);
        Bureaucrat* mediumBureaucrat = new Bureaucrat("\033[1;31m Mousssa \033[0m", 40);
        Bureaucrat* bigBureaucrat = new Bureaucrat("\033[1;31m Ali \033[0m", 1);
    
        std::cout<<"\n" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        std::cout<<"test for signForm in Ex03" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        
        // Sign forms
        smallBureaucrat->signForm(shrubberyForm);
        mediumBureaucrat->signForm(robotomyForm);
        bigBureaucrat->signForm(pardonForm);

        std::cout<<"\n" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        std::cout<<"test for makeForm in Ex03" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        // Intern forms
        AForm* shrubberyForm = wellPaidIntern.makeForm("\033[1;31m shrubbery creation \033[0m", "createTrees");
        AForm* pardonForm = wellPaidIntern.makeForm("PresidentialPardonForm", "Speeding ticket");
        AForm* robotomyForm = wellPaidIntern.makeForm("\033[1;31m presidential pardon \033[0m", "Terminator");

        std::cout<<"\n" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        std::cout<<"test for executeForm in Ex03" << std::endl;
        std::cout<<"-------------------------------------------" << std::endl;
        // Execute forms
        smallBureaucrat->executeForm(shrubberyForm);
        mediumBureaucrat->executeForm(robotomyForm);
        bigBureaucrat->executeForm(pardonForm);

        std::cout<<"\n" << std::endl;
        std::cout<<"-----------------------------" << std::endl;
        std::cout<<"End test for Ex03 Grade" << std::endl;
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
    // Clean up allocated memory
    delete shrubberyForm;
    delete pardonForm;
    delete robotomyForm;
    // system("leaks Itern");
    return 0;
}
