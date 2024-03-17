/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:34:02 by ihama             #+#    #+#             */
/*   Updated: 2024/03/15 17:32:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
    Benefits of std::vector:
    Dynamic Memory Allocation: std::vector automatically allocates and manages 
    memory for the stored numbers. This is crucial since the Span class needs to 
    store a variable number of elements based on the constructor input N. Using 
    raw arrays would require manual memory management, which is error-prone.
*/
class Span
{
private:
    /* data */
    unsigned int N;
    std::vector<int> _numbers;
public:
    Span(/* args */);
    Span(unsigned int n);
    Span(const Span& copy);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int numb);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SpanThrowExcep:public std::exception{
        public:
            const char* what() const throw();
    };

    class FullThrowExcep:public std::exception{
        public:
            const char* what() const throw();
    };
};
