/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:33:13 by ihama             #+#    #+#             */
/*   Updated: 2024/02/29 23:53:03 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

    class CheckOpenFile: public std::exception
    {
        public:
            const char* what() const throw();
    };

public:
    ShrubberyCreationForm(); // Default constructor
    ShrubberyCreationForm(const std::string& target); // Parameterized constructor
    ShrubberyCreationForm(const ShrubberyCreationForm& other); // Copy constructor
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Assignment operator

    const std::string& getTarget() const; // Getter for _target

    void executeFormAction() const; // Override base class function to execute form action
    ~ShrubberyCreationForm(); // Destructor
};

