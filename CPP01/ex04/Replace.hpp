/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:35 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 21:09:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string.h>
#include <fstream>

class Replace
{
private:
    const std::string _fileName;
    const std::string _s1;
    const std::string _s2;

public:
    Replace(); //constructor
    Replace //overload conttructor
    (
        const std::string& fileName,
        const std::string& s1,
        const std::string& s2
    );
    ~Replace(); //destructor
    //Methode
    int replaceContent();
    // void close ();
};

