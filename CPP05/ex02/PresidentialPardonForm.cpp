/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:33:47 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 01:21:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


// Default constructor for PresidentialPardonForm
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default target") {
    std::cout << "Default constructor for PresidentialPardonForm is called" << std::endl;
}

// Constructor with target parameter
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

// Copy constructor for PresidentialPardonForm
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target) {
}

// Assignment operator for PresidentialPardonForm
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other); // Call base class assignment operator
        // _target = other._target; // Copy target
    }
    return *this;
}

// Execute form action
void PresidentialPardonForm::executeFormAction() const {
    std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// Destructor for PresidentialPardonForm
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor for PresidentialPardonForm is called" << std::endl;
}

