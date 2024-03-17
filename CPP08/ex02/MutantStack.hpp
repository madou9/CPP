/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:39:51 by ihama             #+#    #+#             */
/*   Updated: 2024/03/16 15:12:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
    /* data */
public:
    MutantStack(/* args */): std::stack<T>(){};
    typedef typename std::stack<T>::container_type::iterator iterator;
    //Parameters
    //c	-	a container or view with a begin and end member function
    iterator begin() { return this->c.begin(); } 
    iterator end() { return this->c.end(); }

};
