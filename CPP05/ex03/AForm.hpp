/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:42:22 by ihama             #+#    #+#             */
/*   Updated: 2024/02/29 23:52:13 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    /* data */
    virtual void executeFormAction() const = 0;
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
    AForm(/* args */);
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool isSigned() const;
    int gradeToSign() const;
    int gradeToExecute() const;

    void beSigned(const Bureaucrat* b);
    void			execute(const Bureaucrat &executor) const;
    virtual ~AForm();
};

