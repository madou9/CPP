/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:26:38 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 09:11:51 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    Harl(/* args */);
    ~Harl();
    //methode
    void complain(std::string level);
};

typedef void (Harl::*ComplaintFunction)();