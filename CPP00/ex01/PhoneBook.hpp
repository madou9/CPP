/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:23:56 by ihama             #+#    #+#             */
/*   Updated: 2023/10/24 15:03:49 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
    public:

    PhoneBook();
    ~PhoneBook();
    void addContact(void);
    void searchContact(void);
    bool ft_check(std::string input);

    private:

    Contact _contacts[8];
    int     _contactCount;
    int     _oldContact;
};

#endif