/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:54 by ihama             #+#    #+#             */
/*   Updated: 2024/02/29 16:31:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor for AForm
AForm::AForm(/* args */): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor for AForm is created" << std::endl;
}

// Copy constructor for AForm
AForm::AForm(const AForm& copy)
:_name(copy.getName()), _signed(copy._signed), _gradeToSign(copy.gradeToSign()),_gradeToExecute(copy.gradeToExecute())
{ 
    std::cout << "Copy constructor for AForm is created" << std::endl;
    *this = copy;
}

    // Constructor with parameters for AForm
    // Check if the provided grades are within valid range
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
:_name(name),_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

    // Assignment operator for AForm
AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
			return *this;
	return *this;
}

    // Check if the AForm is signed
bool AForm::isSigned() const{
    return _signed;
}

    // Get the name of the AForm
const std::string& AForm::getName() const{
    return AForm::_name;
}

// Get the grade required to sign the AForm
int AForm::gradeToSign() const{
    return (AForm::_gradeToSign);
}

// Get the grade required to execute the AForm
int AForm::gradeToExecute() const{
    return AForm::_gradeToExecute;
}

// Try to sign the AForm with the provided bureaucrat
void AForm::beSigned(const Bureaucrat* b)
{
    if (!b)
        return;
    if (b->getGrade() <= AForm::_gradeToSign)
    {
        AForm::_signed = true;
        return ;
    }
    else
        std::cout << this->getName() << " Mmh... Maybe the AForm is already signed " << std::endl;
}

// Exception message for grade too high
const char* AForm::GradeTooHighException::what() const throw(){
    return (" Mmh... As i aspect your Grade is Too High and you can not access to the Aform ");
}

// Exception message for grade too low
const char* AForm::GradeTooLowException::what() const throw(){
    return (" Mmh... As i aspect your Grade is Too Low and you can not access to the Aform ");
}

// Execute the AForm action with the provided bureaucrat
// Check if the executor has a sufficient grade to execute the AForm
void AForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > AForm::_gradeToSign)
        throw GradeTooHighException();
    else
        executeFormAction();
}

// Destructor for AForm
AForm::~AForm()
{
    std::cout << "Destructor for AForm is called" << std::endl;
}

// Overloaded insertion operator for AForm
std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
    os << "AForm Name: " << Aform.getName() << ", Grade to Sign: " << Aform.gradeToSign()  << ", Grade to Execute: " << Aform.gradeToExecute() << "\n Result: ";
        if (Aform.isSigned())
            os <<"All gute because "<< "\033[1;31m"<< Aform.getName()<< "\033[0m"<< " are the grade that allow him to sign \n";
        else
            os <<"Ohh Noooo "<< "\033[1;31m"<< Aform.getName()<< "\033[0m"<<" has not the grade to sign \n";
    return os;
}
