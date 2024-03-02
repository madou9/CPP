/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:25:36 by ihama             #+#    #+#             */
/*   Updated: 2024/03/01 17:51:07 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
private:
    /* data */
public:
    Intern(/* args */);
    Intern(const Intern& copy);
    Intern& operator=(const Intern& other);
	// Public Methods
    AForm *makeForm(const std::string formName, const std::string target);
    ~Intern();
};


