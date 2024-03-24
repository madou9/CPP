/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:14:18 by ihama             #+#    #+#             */
/*   Updated: 2024/03/22 15:38:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input): express(input){}

RPN::RPN(const RPN& copy){
    *this = copy;
    return ;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        RPN::express = other.getExpress();
    return *this;
}

RPN::~RPN()
{
}

std::string RPN::getExpress(void) const{
    return (RPN::express);
}

bool RPN::isOperator(char act)
{
    return (act == '+' || act == '-' || act == '*' || act == '/');
}
int RPN::doOperator(int a, int b, int op)
{
    // if ( a >= 10 || a < 0 || b < 0 || b >= 10) {
    //   std::cerr << "Error: Numbers must be less than 10." << std::endl;
    //   return 0; //
    // }
    std::string arrayOp = "+-*/";
    int i = arrayOp.find(op);
    switch(i)
    {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: 
            if (b == 0)
            {
                std::cerr << "Error: Division by zero." << std::endl;
                return 0; // Or throw an exception
            }
            return a / b;
        default:
              // Handle invalid operator (replace with more robust error handling)
            std::cerr << "Error: Invalid operator." << std::endl;
            return 0;
    }
}
int RPN::evaluate() {
  std::stringstream ss(express); // stringstream for parsing
  std::string token;

  while (std::getline(ss, token, ' ')) {
     int b;
     int a;
    if (isOperator(token[0])) {
      b = numbers.top();
      numbers.pop();
      a = numbers.top();
      numbers.pop();
      numbers.push(doOperator(a, b, token[0]));
    } else {
      // Check if token represents a number less than 10
      int value = std::stoi(token);
      if (value < 0 || value >= 10) {
        std::cerr << "Error: Number must be less than 10." << std::endl;
        exit(1); // Or throw an exception (C++11)
      }
      numbers.push(value);
    }
  }

  // Check for one element (result) and handle errors
  if (numbers.size() == 1) {
    return numbers.top();
  } else {
    std::cerr << "Error: Invalid expression." << std::endl;
    return 0;
  }
}


const char* RPN::rpnThrowException::what() const throw(){
    return "Error: "; 
}
