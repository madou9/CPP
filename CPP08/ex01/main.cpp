/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:46:46 by ihama             #+#    #+#             */
/*   Updated: 2024/03/15 17:31:05 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void case1()
{
    try
    {
        Span sp = Span();
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout<<"short " << sp.shortestSpan() << std::endl;
        std::cout<<"longest " << sp.longestSpan() << std::endl;
    }
    catch (const Span::SpanThrowExcep &ex)
    {
        std::cerr << "Exception caught: Span is empty or has only one element." << std::endl;
    }
}

void case2()
{
    try
    {
        Span span;

        // Add some elements to the span
        span.addNumber(1);
        span.addNumber(10);
        span.addNumber(100);
        span.addNumber(-1);
        span.addNumber(1000);

        // Calculate and print the Longest span
        std::cout << "shortes Span: " << span.shortestSpan() << std::endl;
        std::cout << "shortes Span: " << span.longestSpan() << std::endl;
    }
    catch (const Span::SpanThrowExcep &ex)
    {
        std::cerr << "Exception caught: Span is empty or has only one element." << std::endl;
    }
}

int main()
{
    std::cout << "-------------------"<< std::endl;
    std::cout << "Test of Case one: " << std::endl;
    std::cout << "-------------------"<< std::endl;
    case1();
    std::cout << "------------------------"<< std::endl;
    std::cout << "End of Test of Case one " << std::endl;
    std::cout << "-------------------------"<< std::endl;
    std::cout << "\n"<< std::endl;

    std::cout << "--------------------"<< std::endl;
    std::cout << "Test of Case 2 one: " << std::endl;
    std::cout << "--------------------"<< std::endl;
    case2();
    std::cout << "---------------------------"<< std::endl;
    std::cout << "End of Test of Case 2 one " << std::endl;
    std::cout << "----------------------------"<< std::endl;
    return 0;
}
