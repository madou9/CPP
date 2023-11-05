/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:23:08 by ihama             #+#    #+#             */
/*   Updated: 2023/10/20 10:00:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    public:

    Contact(); //constructor;
    Contact(
    std::string first_Name, //overload contructor
    std::string lastName,
    std::string nickName,
    std::string phoneNumber,
    std::string dark_Secret
    );
    ~Contact();     //Destructeur
    //Methode
    void displayContact(void) const;
    void displayContactIndex(void) const;

    private:
    //Attribut
    std::string _first_Name;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _dark_Secret;
};

#endif