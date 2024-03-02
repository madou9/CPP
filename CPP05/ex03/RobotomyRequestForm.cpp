/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:33:25 by ihama             #+#    #+#             */
/*   Updated: 2024/02/29 23:40:31 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */):AForm("RobotomyRequestForm", 72, 45), _target("default target")
{
    std::cout<<"Default constructor for RobotomyRequestForm is called"<<std::endl;
}
 RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("RobotomyRequestForm", 145, 137), _target(target){

 }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy){
    *this = copy;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other)
    {
        AForm::operator=(other); // Call base class assignment operator
        //  RobotomyRequestForm::_target = other._target;
    }
    return *this;
}

// Perform action to perform robotomy (with 50% success rate)
void RobotomyRequestForm::executeFormAction()const{
    int checkSuccess;
    checkSuccess = rand() % 2;
    if (checkSuccess)
        std::cout<<RobotomyRequestForm::_target << "has been robotomized successfully!"<<std::endl;
    else
        std::cout<<" Unfortunaly " <<RobotomyRequestForm::_target<< "can't be robotomyzed"<<std::endl;
}

const char* RobotomyRequestForm::RobotiquFaild::what() const throw(){
    return ("Mmh.. Robotomy unfortunaly can't be Robotomyzé. failed.");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<<"Destructor for RobotomyRequestForm is called"<<std::endl;
}