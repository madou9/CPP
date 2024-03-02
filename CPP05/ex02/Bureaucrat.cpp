/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:47:06 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 01:17:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default Constructor for Bureaucrat
Bureaucrat::Bureaucrat() {
    std::cout << "Default Constructor for Bureaucrat is called" << std::endl;
}

// Constructor for Bureaucrat with parameters
// Check if the provided grade is within valid range
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

// Copy constructor for Bureaucrat
Bureaucrat::Bureaucrat(const Bureaucrat& copy){
    *this = copy;
}

// Assignment operator for Bureaucrat
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// Get the name of the bureaucrat
const std::string& Bureaucrat::getName() const {
    return _name;
}

// Get the grade of the bureaucrat
int Bureaucrat::getGrade() const {
    return _grade;
}

// Increment the grade of the bureaucrat
int Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw GradeTooHighException();
    else
        return --_grade;
}

// Decrement the grade of the bureaucrat
int Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    else
        return ++_grade;
}

// Attempt to execute a form
void Bureaucrat::executeForm(AForm* toExecute) {
    if (!toExecute)
        return;
    try {
        toExecute->execute(*this);
    } catch(const std::exception& e) {
        std::cout << _name << " failed to execute " << toExecute->getName() << " " << e.what() << std::endl;
        return;
    }
    std::cout << _name << " successfully executed Form " << toExecute->getName() << std::endl;
}

// Exception message for grade too high
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Mmh... As i aspect Grade is Too High";
}

// Exception message for grade too low
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Mmh... As i aspect Grade is Too Low";
}

// Destructor for Bureaucrat
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor for Bureaucrat is called" << std::endl;
}

// Overloaded insertion operator for Bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << " As a Grade: " << bureaucrat.getGrade() << "\n";
    return os;
}

// Attempt to sign a form
void Bureaucrat::signForm(AForm* toSign) {
    if (!toSign)
        return;
    try {
        toSign->beSigned(this);
    } catch(const std::exception& e) {
        std::cout << "Bureaucrat " << _name << " failed to sign Form: " << toSign->getName() << std::endl;
        return;
    }
    std::cout << "Bureaucrat " << _name << " successfully signed Form: " << toSign->getName() << std::endl;
}


// void Bureaucrat::executeForm(AForm& toExecute)
// {
// 	try
// 	{
// 		toExecute.execute(*this);
// 		std::cout << Bureaucrat::_name << " executed " << toExecute.getName() << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}	
// }
