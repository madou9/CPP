/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:14:21 by ihama             #+#    #+#             */
/*   Updated: 2024/03/24 15:13:04 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
     if (argc == 2 && argv[1] != NULL)
    {
        try
        {
             RPN calculator(argv[1]);
            int result = calculator.evaluate();
            if (result >= 0) { // Handle non-error cases
                std::cout << "Result: " << result << std::endl;
      }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error "  << std::endl;
            return (1);
        }
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    return 0;
}
// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" 
// 42
// $> ./RPN "7 7 * 7 -" 
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +" 
// 0
// $> ./RPN "(1 + 1)"
//  Error
// $>