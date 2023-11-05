/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:10 by ihama             #+#    #+#             */
/*   Updated: 2023/10/21 15:09:52 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int is_valid(std::string name)
{
    if (name == "ADD" || name == "SEARCH" || name == "EXIT")
        return 1;
    else 
        return 0;
}
void prompt_command(std::string &option)
{
    std:: cout << "Please enter the (ADD SEARCH OR EXIT)" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, option);
}

int main()
{
    PhoneBook Phone;
    std::string option;
    std::cout << "Welcome to your PhoneBook !" << std::endl;
    while(true)
    {
        prompt_command(option);
        if (option == "ADD")
            Phone.addContact();
        else if (option == "SEARCH")
            Phone.searchContact();
        else if (option == "EXIT")
        {
            std::cout <<"goodbye" << std::endl;
            break;
        }
    }
    return (0);
}