/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:14:15 by ihama             #+#    #+#             */
/*   Updated: 2024/03/22 01:31:55 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
    /* data */
    std::string express; //Will store the input expression for later parsing.
    // /objects, likely for storing numbers and intermediate results.
    std::stack<int> numbers;
    std::stack<int> stack;
public:
    RPN(std::string input);
    RPN(const RPN& copy);
    RPN& operator=(const RPN& other);
    bool isOperator(char act);
    int doOperator(int a, int b, int op);
    int evaluate(); // Evaluate the RPN expression and return the result
    std::string getExpress()const;
    ~RPN();

    class rpnThrowException: public std::exception{
        public:
        const char* what() const throw();
    };
};
