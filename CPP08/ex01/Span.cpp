/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:33:59 by ihama             #+#    #+#             */
/*   Updated: 2024/03/16 15:13:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(/* args */): N(5){}

Span::Span(unsigned int n): N(n), _numbers(0) {}

Span::Span(const Span& copy): N(copy.N), _numbers(copy._numbers){}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        N = other.N;
    }
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int numb){
    if (this->_numbers.size() == Span::N)
        throw SpanThrowExcep();
    else
        this->_numbers.push_back(numb);
}

int max(const std::vector<int>& V) {
    int maxVal = V[0];
    for (std::vector<int>::const_iterator i = V.begin(); i != V.end(); ++i) {
        if (maxVal < *i) maxVal = *i;
    }
    return maxVal;
}

int min(const std::vector<int>& V) {
    int minVal = V[0];
    for (std::vector<int>::const_iterator i = V.begin(); i != V.end(); ++i) {
        if (minVal > *i) minVal = *i;
    }
    return minVal;
}

unsigned int Span::shortestSpan() const {
    
    if (_numbers.size() <= 1)
        throw FullThrowExcep();
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = max(_numbers); // Initialize with maximum possible value of _numbers
    size_t i = 0;
    // std::cout << "sortedNumbers[i]: " << sortedNumbers[i] << std::endl;
    while (++i < sortedNumbers.size()) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        // std::cout << "span: " << span << std::endl;
        // std::cout << "avant minspan: " << minSpan << std::endl;
        if (span < minSpan)
            minSpan = span;
        // std::cout << "Apres minSpan: " << minSpan << std::endl;
    }

    return (minSpan);
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw FullThrowExcep(); // Assuming FullThrowExcep is an exception class defined elsewhere
    // std::cout << "max: " << max(_numbers) << std::endl;
    // std::cout << "min: " << min(_numbers) << std::endl;
    return max(_numbers) - min(_numbers) ;
}

const char* Span::SpanThrowExcep::what() const throw(){
    return "\033[1;34mCannot add more numbers, Span is full\033[0m";
}
const char* Span::FullThrowExcep::what() const throw(){
    return "\033[1;34mError: no numbers stored.\033[0m";
}
