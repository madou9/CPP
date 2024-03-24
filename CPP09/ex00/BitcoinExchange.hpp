/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:48:50 by ihama             #+#    #+#             */
/*   Updated: 2024/03/21 13:49:23 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> bitcoinPrices; // Map to store bitcoin prices for each date
public:
    BitcoinExchange(); // Constructor
    BitcoinExchange(const BitcoinExchange& copy); // copy Constructor
    BitcoinExchange& operator=(const BitcoinExchange& copy); // assignement operator
    ~BitcoinExchange(); // Destructor
    void CheckInput(std::string file); // Function to check input
    // void PrintValue(float value); // Function to print value
    void printValue(const std::string& date, float value);
    void checkDataCvs(const std::string& data); // Function to read the CSV database and populate bitcoinPrices
};

