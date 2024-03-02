/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:46:32 by ihama             #+#    #+#             */
/*   Updated: 2024/02/28 16:42:38 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/*
    C++ Exceptions
    When executing C++ code, different errors can occur: coding errors made by the programmer, errors due to wrong input, or other unforeseeable things.
    When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an exception (throw an error).
*/

/*
    Exception handling in C++ consist of three keywords: try, throw and catch:

    The try statement allows you to define a block of code to be tested for errors while it is being executed.

    The throw keyword throws an exception when a problem is detected, which lets us create a custom error.

    The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.
*/

class Bureaucrat
{
private:
    /* data */
    const std::string _name;
    int _grade;
public:
    Bureaucrat(/* args */); // contruction function
    Bureaucrat(const std::string& name, int grade); // 
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat& other);

    // provide two Attributes :getName() and getGrade()
    const std::string& getName() const;
    int getGrade() const;

    //Im- plement also two member functions to increment or decrement the bureaucrat grade
    int incrementGrade();
    int decrementGrade();

        /*Exception class*/
    class GradeTooHighException: public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };
    
    /*Destruction function*/
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);


