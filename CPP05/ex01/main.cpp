/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:51 by ihama             #+#    #+#             */
/*   Updated: 2024/03/02 11:56:08 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    std::cout<<"\n" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    std::cout<<"Begin for AForm Grade" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    try{
        Bureaucrat a("Tanko", 149);
        Form b("Tanko", 149, 120);
        b.beSigned(&a);
        std::cout << a;
        std::cout << b;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    std::cout<<"Begin for AForm Grade" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    
    try{
        Bureaucrat a1("Ali", 149);
        Form b1("Ali", 148, 11);
        b1.beSigned(&a1);
        std::cout << a1;
        std::cout << b1;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
