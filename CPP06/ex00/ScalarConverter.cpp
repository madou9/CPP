/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:49:16 by ihama             #+#    #+#             */
/*   Updated: 2024/03/04 14:24:26 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib> // general utilities 
#include <iomanip> //is used to manipulate the output of C++ program
#include <iostream>
#include <cctype> // Include for isalpha function

ScalarConverter::ScalarConverter(/* args */)
{
    std::cout<<"Default contructor for ScalarConverter"<< std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& copy){
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    if (this != &other)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout<<"Destructor for ScalarConvert is called"<<std::endl;
}
/* checks if the input string 
    has a size of 1 and if the character is printable using std::isprint
*/

// chech for Char -------------------------------------------------
bool isCharInput(const std::string& str)
{
    return (str.size() == 1 && std::isalpha(str[0]));
}

void executeChar(const std::string& str)
{
    if (str.empty()) {
        std::cout << "char: Input is empty" << std::endl;
        return;
    }

    int intValue = static_cast<int>(str[0]);
    float floatValue = static_cast<float>(str[0]);
    double doubleValue = static_cast<double>(str[0]);

    if (str.size() == 1 && !isprint(str[0])) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << str[0] << std::endl;
        std::cout << "Int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    }
}
// End for for Char -----------------------------------------------

// chech for Integer -------------------------------------------------
int check_number_sign(char c)
{
    return (c == '+' || c == '-');
}

bool checkIfNumber(const std::string& value)
{
    if (value.empty()){
         std::cout << "int: Input is empty" << std::endl;
        return false;
    }
    size_t i = 0;
    if (check_number_sign(value[i]) && value[i + 1] != '\0')
        i++;
    
    while (value[i] != '\0')
    {
        if (!isdigit(value[i]))
            return false;
        i++;
    }
    
    return true;
}
void chechCharForInt(const std::string str)
{
     // Convert string to integer
 try
    {
        int intValue = std::stoi(str);
        char ch = static_cast<char>(intValue);
        if (intValue >= 0 && intValue < 32)
            std::cout << "char: Non displayable" << std::endl;
        else if (intValue < 0 || intValue > 127)
            std::cout << "char: Impossible" << std::endl;
        else
            std::cout << "char: '" << ch << "'" << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "char: Conversion error: " << e.what() << std::endl;
    }
}
void executeInt(const std::string& str)
{
    if (str.empty())
    {
        std::cout << "int: Input is empty" << std::endl;
        return;
    }
    try
    {
        chechCharForInt(str);
        float f = static_cast<float>(std::stoi(str.c_str()));
        double d = static_cast<double>(std::stoi(str.c_str()));
        std::cout << "int: " << std::stoi(str) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl; // setprecision It is used to set decimal precision.
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    }
    // catch (const std::invalid_argument& e)
    // {
    //     std::cerr << "int: Conversion error: " << e.what() << std::endl;
    // }
    catch (const std::out_of_range& e)
    {
        std::cerr << "int: Out of range error: " << e.what() << std::endl;
    }
}
// End for Integer -------------------------------------------------

// Start for float--------------------------------------------------

bool isFloat(const std::string& str)
{
    bool checkIfDot = false;
    int foundDot = 0;
    // Check for special float literals
    if(str == "nan" || str == "nanf" || str == "+inf"  || str == "-inff")
        return true;
        // Check if the string starts with a sign (+/-)
    if (str[0] == '+' || str[0] == '-')
        return std::isdigit(str[1]); // Check if the character after the sign is a digit

        // Check if the string is empty or contains only a single dot
    if (str.empty() || (str.size() == 1 && str[0] == '.' && str[1] == 'f') )
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        // Check if the string ends with 'f'
        if (str[str.length() - 1] == 'f')
            return true;
        else if (str[i] == '-' || str[i] == '+')
           return true;
        char c = str[i];
        if (c == '.')
        {
            // Check if a dot has already been found
            if (checkIfDot)
                return false; // Multiple dots found
            checkIfDot = true;
            ++foundDot;
        }
        else if (!std::isdigit(c)) // Check if the character is not a digit
        {
            // Check if it's the first character and it's not a sign (+/-)
            if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-')))
                return false;
            return false; // Non-digit and non-dot character
        }
    }
    // Check if there's more than one decimal point
    if (foundDot > 1)
    {
        return false;
    }
    // If none of the conditions are met, the string is a valid float
    return true;
}

void executeFloat(const std::string& str)
{
    // Convert string to float
    float f = std::strtof(str.c_str(), nullptr);
    // std::cout<<"float f = " << f <<std::endl;
    // // convert string to double;
    double	db = static_cast<double>(f);
    // Check if the conversion was successful
    if (f == 0 && str != "0") {
        std::cout << "Invalid float value" << std::endl;
    }
    // Convert float to int
    int nb = static_cast<int>(f);
    // Check if the float value is within the range of printable characters
    if (nb < 0 || nb > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else {
        // Check if the float value represents a printable character
        if (std::isprint(static_cast<char>(f))) {
            std::cout <<"char " << "'" << static_cast<char>(f) << "'" << std::endl;
        } else {
            std::cout << "Char: Non displayable" << std::endl;
        }
    }
   // Check for special floating-point values
    if (std::isinf(f) || std::isnan(f)) {
        std::cout << "int: impossible" << std::endl;
    }
	else
		std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl; // Print with one digit after the decimal point
    std::cout << "double: " << std::fixed << std::setprecision(1) << db << std::endl; // Print with one digit after the decimal point
}
//End for float-----------------------------------

// Start Double ---------------------------------
bool isDouble(const std::string& str)
{
    bool checkIfDot = false;
    int foundDot = 0;

    if(str == "nan" || str == "nanf" || str == "+inf"  || str == "-inff")
        return true;
    // Check if the string starts with a sign (+/-)
    if (str[0] == '+' || str[0] == '-')
        return isdigit(str[1]); // Check if the character after the sign is a digit
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (c == '.')
        {
            // Check if a dot has already been found
            if (checkIfDot)
                return false; // Multiple dots found
            else if (str[i] == '-' || str[i] == '+')
                   return true;
            checkIfDot = true;
            ++foundDot;
        } else if (!isdigit(c)) // Check if the character is not a digit
        {
            // Check if it's the first character and it's not a sign (+/-)
            if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-')))
                return false;
            return false; // Non-digit and non-dot character
        }
    }
    // Check if there's more than one decimal point
    if (foundDot > 1)
    {
        std::cout << "Invalid input: More than one decimal point." << std::endl;
        return false;
    }
    // Check if the string is empty or contains only a single dot
    if (str.empty() || (str.size() == 1 && str[0] == '.')){
        // std::cout << "Invalid input." << std::endl;
        return false;
    }
    // Check if the string is a single dot (not a valid float)
    if (str == ".")
        return false;
    return true;
}

void executeDouble(const std::string& str) {
    // Convert string to double using std::stod for safety
    double db = std::stod(str.c_str());

    // Check if conversion was successful
    if (db == 0 && str != "0") {
        std::cout << "Invalid double value" << std::endl;
        return;
    }
    //round is used to round off the given digit which can be in float or double. It returns the nearest integral value to provided parameter in round function,
    int nb = std::round(db); 
    // Informative message for non-printable characters
    if (nb < 0 || nb > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    }
    // Check for special floating-point values
    if (std::isinf(db) || std::isnan(db)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int : " << nb << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(db) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << db << std::endl; //noshowpos do don't show the sign like + or -
    }
}

void ScalarConverter::convert(const std::string& str)
{
    if (str.empty()) {
        std::cout << "Input is empty" << std::endl;
        return;
    }
    if (isCharInput(str)) {
        executeChar(str);
    }
    if (checkIfNumber(str)) {
        executeInt(str);
        return ;
    }
    if (isFloat(str)){
        executeFloat(str);
        return ;
    }
    if (isDouble(str)){
        executeDouble(str);
    }
    else {
        std::cout << "Unsupported literal type" << std::endl;
    }
}

