/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:51 by ihama             #+#    #+#             */
/*   Updated: 2024/02/28 16:48:22 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
    What is a C++ Exception?
    An exception is an unexpected problem that arises during the execution of a program our program terminates suddenly with some errors/issues. Exception occurs during the running of the program (runtime).
*/

int main() {

    std::cout<<"-----------------------------" << std::endl;
    std::cout<<"test for Bureaucrat Grade" << std::endl;
    std::cout<<"-----------------------------" << std::endl;

    try {
        // Attempt to create Bureaucrat with invalid grades
        Bureaucrat tryZeroBureaucrat("Tanko", 0);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat try1Bureaucrat("Tanko", 1);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat try150Bureaucrat("Tanko", 150);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat try151Bureaucrat("Tanko", 151);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-----------------------------------------" << std::endl;
    std::cout<<"test valid for Bureaucrat Grade increment" << std::endl;
    std::cout<<"-----------------------------------------" << std::endl;

    try {
        // Create a Bureaucrat object with a valid grade for increment
        Bureaucrat testBureaucrat("Test", 2);

        // Increment and print grade
        testBureaucrat.incrementGrade();
        std::cout << "After increment: " << testBureaucrat << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-----------------------------------------" << std::endl;
    std::cout<<"test valid for Bureaucrat Grade decrement" << std::endl;
    std::cout<<"-----------------------------------------" << std::endl;

    try {
        // Create a Bureaucrat object with a valid grade for decrement
        Bureaucrat test1Bureaucrat("Test", 149);

        // Increment and print grade
        test1Bureaucrat.decrementGrade();
        std::cout << "After decrement: " << test1Bureaucrat << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-------------------------------------------" << std::endl;
    std::cout<<"test unvalid for Bureaucrat Grade increment" << std::endl;
    std::cout<<"-------------------------------------------" << std::endl;
    try {
        // Create a Bureaucrat object with a Unvalid grade for increment
        Bureaucrat testBureaucrat("Test", 1);

        // Increment and print grade
        testBureaucrat.incrementGrade();
        std::cout << "After increment: " << testBureaucrat << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-------------------------------------------" << std::endl;
    std::cout<<"test unvalid for Bureaucrat Grade decrement" << std::endl;
    std::cout<<"-------------------------------------------" << std::endl;
    try {
        // Create a Bureaucrat object with a Unvalid grade for decrement
        Bureaucrat test1Bureaucrat("Test", 150);

        // Increment and print grade
        test1Bureaucrat.decrementGrade();
        std::cout << "After decrement: " << test1Bureaucrat << std::endl;

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\n" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    std::cout<<"End test for Bureaucrat Grade" << std::endl;
    std::cout<<"-----------------------------" << std::endl;
    // system("leaks Bureaucrat");
    return 0;
}

