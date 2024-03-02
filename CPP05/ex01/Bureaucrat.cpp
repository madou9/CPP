/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:47:06 by ihama             #+#    #+#             */
/*   Updated: 2024/03/02 11:55:12 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Constructor for Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy){
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

int Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw GradeTooHighException();
    else
        return --_grade;
}

int Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    else
        return ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Mmh... As i aspect Grade is Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Mmh... As i aspect Grade is Too Low");
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor for Bureaucrat is called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << " As a Grade: " << bureaucrat.getGrade() << "\n";
    return os;
}


void Bureaucrat::signForm(Form& f){
    if (this->_grade <= f.gradeToSign()){
        std::cout<< this->_name << "cannot sign " << f.getName() << "because grade is too low" << std::endl;
    }else {
        f.beSigned(this); // Sign the form
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
}