/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:46:32 by ihama             #+#    #+#             */
/*   Updated: 2024/02/28 21:15:17 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

/*
In C++, exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution. The process of handling these exceptions is called exception handling. 
Using the exception handling mechanism, the control from one part of the program where the exception occurred can be transferred to another part of the code.

So basically using exception handling in C++, we can handle the exceptions so that our program keeps running.
*/

class Form;// forward declaration of form class to be able to get function of Form

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
    
    void signForm(Form& f);
    /*Destruction function*/
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);


