/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:24:08 by ihama             #+#    #+#             */
/*   Updated: 2023/10/24 17:04:35 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor for PhoneBook
PhoneBook::PhoneBook() : _contactCount(0), _oldContact(0)
{
}
// destructor for PhoneBook
PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
        std::string firstName, lastName, nickName, phoneNumber, darkSecret;
        std::cout <<"Enter first Name: " ;
        std::getline(std::cin, firstName);
        std::cout <<"Enter last Name: " ;
        std::getline(std::cin, lastName);
        std::cout <<"Enter Nick Name: " ;
        std::getline(std::cin, nickName);
        while (1)
        {
            std::cout <<"Enter Phone Number: " ;
            std::getline(std::cin, phoneNumber);
            bool validPhoneNumber = true;
            for (int i = 0; i < phoneNumber.length(); i++)
            {
                char c = phoneNumber[i];
                if (!isdigit(c))
                {
                    validPhoneNumber = false;
                    break;
                }
            }
            if (validPhoneNumber)
                break;
            else
                std::cout << "please enter a valid Number" << std::endl;
        }
        std::cout <<"Enter dark Secret: " ;
        std::cin >> darkSecret;
        std::cout << "contact Saved successfully" << std::endl;
        if (_contactCount < 8)
        {
            _contacts[_contactCount] = Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
            PhoneBook::_contactCount++;
        }
        else
        {
            // Replace the old contact
            _contacts[_oldContact] =  Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
            _oldContact = (_oldContact + 1) % 8;
        }
        std::cin.ignore(1, '\n');
        std::cin.clear();
}

bool PhoneBook::ft_check(std::string input)
{
    if (input[0] >= '0' && input[0] < '8' && !input[1])
        return true;
    return false;
}

void PhoneBook::searchContact()
{
    if (_contactCount == 0)
        std::cout << "PhoneBook is empty" << std::endl;
    
    std::cout << "  ------------------------------------------"<< std::endl;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nick name" << "|" << std::endl;
    std::cout << "  ------------------------------------------"<< std::endl;
    for (int i = 0; i < _contactCount; i++)
    {
        std::cout << std::right << std::setw(10) << i << "|";
        this->_contacts[i].displayContact();
    }
    std::string input;
    int index;
    std::cout << "please enter the index of the contact you want to view / Or tap 'NO' to ignore it :  ";
    std::cin >> input;
    if (ft_check(input))
        index = std::stoi(input);
    else
    {
        if (input == "no" || input == "NO" || input == "No")
        {
            std::cin.ignore(1, '\n');
            return ;
        }
        else
        {
            std::cerr<<"ERROR: Please put no/No/NO" <<std::endl;
            std::cin.ignore(1, '\n');
            return ;
        }
    }
    if ((std::cin.fail() || index > 7 || index < 0) ||  index >= _contactCount)
    {
        std::cerr << "Invalid index, please retry." << std::endl;
        std::cin.ignore(1, '\n');
        std::cin.clear();
        return ;
    }
    else if (_contactCount == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        std::cin.ignore(1, '\n');
        std::cin.clear();
        return ;
    }
    else
    {
        std::cout << "contact Information: " << std::endl;
        this->_contacts[index].displayContactIndex();
        std::cin.ignore(1, '\n');
        std::cin.clear();
    }
}
