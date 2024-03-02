/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:02:10 by ihama             #+#    #+#             */
/*   Updated: 2024/02/28 22:09:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
    /* data */
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

    /*Exception class*/
    class GradeTooHighException: public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };

public:
    Form(/* args */);
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& copy);
    Form& operator=(const Form& other);

    const std::string& getName() const;
    bool isSigned() const;
    int gradeToSign() const;
    int gradeToExecute() const;

    void beSigned(const Bureaucrat* b);
    ~Form();
};
//
std::ostream& operator<<(std::ostream& os, const Form& Form);