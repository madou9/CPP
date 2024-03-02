/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:46:32 by ihama             #+#    #+#             */
/*   Updated: 2024/02/29 23:59:16 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp" // Include the header file for AForm

class AForm; // Forward declaration of AForm class

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(); // Default constructor
    Bureaucrat(const std::string& name, int grade); // Parameterized constructor
    Bureaucrat(const Bureaucrat& copy); // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); // Assignment operator

    const std::string& getName() const; // Getter for name
    int getGrade() const; // Getter for grade

    int incrementGrade(); // Increment grade
    int decrementGrade(); // Decrement grade

    // Exception classes
    class GradeTooHighException: public std::exception {
    public:
        const char* what() const throw() ;
    };

    class GradeTooLowException: public std::exception {
    public:
        const char* what() const throw() ;
    };

    // Member functions for signing and executing forms
    void signForm(AForm* toSign);
    void executeForm(AForm* toExecute);

    ~Bureaucrat(); // Destructor
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat); // Stream output operator



