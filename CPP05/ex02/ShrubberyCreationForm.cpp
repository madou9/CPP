/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:33:04 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 18:24:56 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor for ShrubberyCreationForm
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default target") {
    std::cout << "Default constructor for ShrubberyCreationForm created" << std::endl;
}

// Constructor with target parameter
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Parameterized constructor for ShrubberyCreationForm created" << std::endl;
}

// Copy constructor for ShrubberyCreationForm
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), _target(copy._target) {
    std::cout << "Copy constructor for ShrubberyCreationForm created" << std::endl;
}

// Assignment operator for ShrubberyCreationForm
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Execute form action (create shrubbery)
void ShrubberyCreationForm::executeFormAction() const {
    std::ofstream createFile((_target + "_shrubbery"));
    if (createFile.is_open()) {
        // Write ASCII art to the file
        createFile <<
			"         /X/ \n" 
			"         -A-  \n"
			"        -ALI-  \n"
			"       -MOUSSA- \n" 
			"      -TANKOSSS- \n" 
			"    -WABERGERRR- \n"
			"  -ZOOOOOOOOOOOO- \n"
			"     -QTTTTTTT- \n"
			"       -TTTT- \n" 
			"     -4242424242- \n" 
			"  -424242424242442- \n" 
			"-244242424242424242- \n" 
			"        -###- \n" 
			"        -###- \n" 
			"        -###- \n" ;
        createFile.close();
        std::cout << "Shrubbery created successfully!" << std::endl;
    } else {
        // Throw exception if createFile cannot be opened
        throw CheckOpenFile();
    }
}

// Getter for target
const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

// Exception message for failed createFile opening
const char* ShrubberyCreationForm::CheckOpenFile::what() const throw() {
    return "Failed to open createFile for writing shrubbery.";
}

// Destructor for ShrubberyCreationForm
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor for ShrubberyCreationForm is called" << std::endl;
}
