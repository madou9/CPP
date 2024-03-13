/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:37:11 by ihama             #+#    #+#             */
/*   Updated: 2024/03/11 12:35:18 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

template <typename T>
T swap(T &a, T &b){
   T temp;
   
   temp = a;
   a = b;
   return b = temp; 
}

template <typename T>
T min(T a, T b){
    if (a < b)
        return (a);
    else
        return (b);
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return (a);
    else
        return (b);
}