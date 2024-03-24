/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:49:57 by ihama             #+#    #+#             */
/*   Updated: 2024/03/21 14:11:30 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// std::map<std::string, float> bitcoinPrices;
/*
    This ensures that every time an instance of BitcoinExchange is created, 
    the CSV database file is read and its contents are parsed into the bitcoinPrices map.
*/
BitcoinExchange::BitcoinExchange(/* args */){
    checkDataCvs("data.csv");
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{   
    BitcoinExchange::bitcoinPrices = copy.bitcoinPrices;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) BitcoinExchange::bitcoinPrices = other.bitcoinPrices;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){}


void BitcoinExchange::printValue(const std::string& date, float value) {
    // Find the closest date in the database
    std::map<std::string, float>::iterator iterat = bitcoinPrices.lower_bound(date);
    if (iterat == bitcoinPrices.begin() && iterat->first != date) {
        std::cerr << "Error: Date not found in database" << std::endl;
        return;
    }
     // Adjust to the closest date
    while (iterat != bitcoinPrices.begin() && iterat->first > date)
            --iterat;
    // Calculate the exchange rate for the closest date
    float exchangeRate = iterat->second;
    // Calculate the result
    // float result = value * exchangeRate;
    // Check if the result is too large
   // Check if the value is too large
    if (sizeof(value) > 4 || value > 1000) {
        std::cout << "Error: Too large a number." << std::endl;
        return;
    }
   // Check if the value is negative
    if (value < 0) {
        std::cout << "Error: Not a positive number." << std::endl;
        return;
    }
    // Output the result
    std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      return year % 400 == 0;
    } else {
      return true;
    }
  }
  return false;
}
// Function to validate date format (YYYY-MM-DD)
bool isValidData(const std::string& dateStr)
{
     // Breaking input into word 
    // using string stream
    // Used for breaking words
    std::stringstream s(dateStr);
    // Extract year, month, day
    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string  dayStr = dateStr.substr(8, 2);
    // turns a string into an integer for year, month, day
    int year = stoi(yearStr);
    int month = stoi(monthStr);
    int day = stoi(dayStr);
    int i = 0;
    if (dateStr.length() != 10) {
        std::cout << "Error: Format of Data not correct" << std::endl;
        return false; // Return false immediately if length is incorrect
    }
    while (i < 10)
    {
        if (i == 4 || i == 7) { // Check if current index is where dashes should be
            if (dateStr[i] != '-') {
                std::cout << "Error: Invalid date format" << std::endl;
                return false; // Return false if dash is missing
            }
        } else {
            if (!isdigit(dateStr[i])) { // Check if the character is not a digit
                std::cout << "Error: Invalid character found in date" << std::endl;
                return false; // Return false if non-digit character found
            }
        }
        i++; // Increment index for next iteration
    }
    // Validate year, month, and day ranges
    if (year > 2022 || year < 2009)
    {
        std::cout<<"Error: Year out of range (2009-2022)" <<std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cout<<"Error: Month out of range (1-12)" <<std::endl;
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cout<<"Error: Day out of range (1-31)" <<std::endl;
        return false;
    }
    // check for month April, April (4th month), June (6th month), September (9th month), and November (11th month), there are only 30 days.
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "Error: Day out of range for the given month" << std::endl;
        return false;
    }
    // check for February that have 29 day
    if (month == 2) {
        bool isLeap = isLeapYear(year);
        if ((isLeap && day > 29) || (!isLeap && day > 28)) {
            std::cout << "Error: Day out of range for February" << std::endl;
            return false;
        }
    }
    return true;
}

// Utility function to trim whitespace from a string
std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}
void BitcoinExchange::CheckInput(std::string file) {

    try 
    {
        std::ifstream openFile(file);
        std::string line;
        std::getline(openFile, line);
        if (!openFile.is_open())
            throw std::runtime_error("Error opening file: " + file);
        if (line.compare("date | value") != 0)
            std::cerr << "Error: Invalid data format" << std::endl;
        // Read and process each line from the input file
        while (std::getline(openFile, line))
        {
            std::stringstream ss(line);
            std::string dateStr, valueStr;
            if (std::getline(ss, dateStr, '|') && std::getline(ss, valueStr))
            {
                // Trim leading and trailing whitespaces
                dateStr = trim(dateStr);
                valueStr = trim(valueStr);
                // Parse the value
                try {
                    float value = std::stof(valueStr);
                    // Call printValue function to calculate and output the result
                    printValue(dateStr, value);
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Function to read the CSV database and populate bitcoinPrices
void BitcoinExchange::checkDataCvs(const std::string& data) {
    
    std::ifstream databaseFile(data);
    std::string line;
    std::getline(databaseFile, line); // Skip header line
    if (!databaseFile.is_open()) {
        std::cerr << "Error: Could not open database file" << std::endl;
        return;
    }
    while (std::getline(databaseFile, line))
    {
        std::stringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr))
        {
            // Trim leading and trailing whitespaces
            dateStr = trim(dateStr);
            exchangeRateStr = trim(exchangeRateStr);
            // Parse date and exchange rate
            try {
                float exchangeRate = std::stof(exchangeRateStr);
                // Check if the date is valid before adding to bitcoinPrices map
                if (isValidData(dateStr)) {
                    bitcoinPrices[dateStr] = exchangeRate;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error parsing exchange rate: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

// void BitcoinExchange::CheckInput(std::string file)
// {
//     try
//     { 
//         std::ifstream openFIle(file);
//         if (!openFIle.is_open())
//             throw std::runtime_error("Error opening file: " + file);
//         std::string line;
//         std::getline(openFIle, line);
//         if (line.compare("date | value") != 0)
//             std::cout<<"no data format" <<std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// // Parse the value
//         try {
//             float value = std::stof(valueStr);
//             // Call printValue function to calculate and output the result
//             exchange.printValue(dateStr, value);
//         } catch (const std::exception& e) {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
// }
