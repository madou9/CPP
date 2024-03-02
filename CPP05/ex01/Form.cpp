/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:54 by ihama             #+#    #+#             */
/*   Updated: 2024/02/28 23:35:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(/* args */): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout<<"Default constructor for Form is created"<<std::endl;
}

Form::Form(const Form& copy)
:_name(copy.getName()), _signed(false), _gradeToSign(copy.gradeToSign()),_gradeToExecute(copy.gradeToExecute())
{ 
    std::cout<<"copy constructor for Form is created"<<std::endl;
    *this  = copy;
}

Form:: Form(const std::string& name, int gradeToSign, int gradeToExecute)
:_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

//nothing to assign in this class but at least we can give for signed
Form &Form::operator=(const Form &other)
{
	if (this == &other)
		Form::_signed = other._signed;
	return *this;
}

bool Form::isSigned() const{
    return _signed;
}

const std::string& Form::getName() const{
    return Form::_name;
}

int Form::gradeToSign() const{
    return Form::_gradeToSign;
}

int Form::gradeToExecute() const{
    return Form::_gradeToExecute;
}

void Form::beSigned(const Bureaucrat* b)
{
    if (!b)
        return;
    if (b->getGrade() <= Form::_gradeToSign)
        Form::_signed = true;
    else
        std::cout << this->getName() << "Mmh... Maybe the Form is already signed" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Mmh... As i aspect your Grade is Too High and you can not access to the form");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Mmh... As i aspect your Grade is Too Low and you can not access to the form");
}

Form::~Form()
{
    std::cout<<"destructor for Form is called" <<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form Name: " << form.getName() << ", Grade to Sign: " << form.gradeToSign()  << ", Grade to Execute: " << form.gradeToExecute() << "\n Result: ";
        if (form.isSigned())
            os <<"All gute because "<< "\033[1;31m"<< form.getName()<< "\033[0m"<< " are the grade that allow him to sign \n";
        else
            os <<"Ohh Noooo "<< "\033[1;31m"<< form.getName()<< "\033[0m"<<" has not the grade to sign \n";
    return os;
}
