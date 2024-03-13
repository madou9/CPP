/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:20:21 by ihama             #+#    #+#             */
/*   Updated: 2023/12/24 20:30:35 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
    /* data */
    std::string ideas[100];
public:
    Brain(/* args */);
    Brain(const Brain& reff);
    Brain& operator=(const Brain& other);
    ~Brain();
};
