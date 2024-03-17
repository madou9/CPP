/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:24:29 by ihama             #+#    #+#             */
/*   Updated: 2024/03/16 15:15:16 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <iostream>
#include <vector>

class valueNotFound: public std::exception{
    public:
    const char* what() const throw(){
        return ("No value found in container");
    }
};

template <typename T>
typename T::iterator easyfind(T& cont, int value){

    typename T::iterator it = cont.begin();
    typename T::iterator end = cont.end();
    while (it != end)
    {
        if (*it == value) // Check if current element matches the value
            return it; // Return iterator if found
        ++it;
    }
    throw valueNotFound();
    
}
