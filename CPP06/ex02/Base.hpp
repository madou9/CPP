/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:29:51 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 11:52:25 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base
{
private:
    /* data */
public:
    virtual ~Base(){};
};

Base * generate(void);

void identify(Base* p);

void identify(Base& p);

