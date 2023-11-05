/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:23:28 by ihama             #+#    #+#             */
/*   Updated: 2023/10/24 14:15:18 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact ::Contact()
{
}

Contact ::Contact(std::string first_Name, std::string lastName, std::string nickName, 
    std::string phoneNumber, std::string dark_Secret)
    :_first_Name(first_Name), _lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber), _dark_Secret(dark_Secret)
{
}
Contact ::~Contact()
{
}

void Contact::displayContact(void) const
{
    std::string first_name = this->_first_Name;
    std::string last_name = this->_lastName;
    std::string Nick_name = this->_nickName;
    if (first_name.length() > 10)
        first_name = first_name.substr(0,9) + ".";
    if (last_name.length() > 10)
        last_name = last_name.substr(0,9) + ".";
    if (Nick_name.length() > 10)
        Nick_name = Nick_name.substr(0,9) + ".";
    std::cout << std::setw(10) << first_name << "|";
    std::cout << std::setw(10) << last_name << "|";
    std::cout << std::setw(10) << Nick_name << "|" << std::endl;
}

void Contact::displayContactIndex(void) const
{
    std::cout << "first Name: " << std::setw(10) << _first_Name << std::endl;
    std::cout << "last Name: " << std::setw(10) << _lastName << std::endl;
    std::cout << "nick Name: " << std::setw(10) << _nickName << std::endl;
    std::cout << "Phone Number: " << std::setw(10) << _phoneNumber << std::endl;
    std::cout << "dark secret: " << std::setw(10) << _dark_Secret << std::endl;
}

