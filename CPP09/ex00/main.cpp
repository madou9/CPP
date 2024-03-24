/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:48:54 by ihama             #+#    #+#             */
/*   Updated: 2024/03/21 02:16:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
    
    BitcoinExchange exchange;
    if (argc == 2 && argv[1] != NULL)
    {
        try
        {
            exchange.CheckInput(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    return 0;
}


// 2011-01-03 => 3 = 0.9 
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3 
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42 
// 2012-01-11 => 1 = 7.1
// Error: too large a number.