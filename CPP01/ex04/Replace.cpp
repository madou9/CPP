/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:29 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 21:17:47 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string& fileName, const std::string& s1, const std::string& s2) : _fileName(fileName), _s1(s1), _s2(s2){}

Replace::Replace(){}

Replace::~Replace(){}

int Replace::replaceContent()
{
    // Open the input file for reading
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string readLine;
    std::string outputFileName = _fileName + ".replace";
    inputFile.open(_fileName.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: failed to open input file." << std::endl;
        return 1;
    }
    // Open the output file for reading
    outputFile.open(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Failed to create output file." << std::endl;
        return 1;
    }
    //read line
    while (std::getline(inputFile, readLine))
    {
        //  function to replace s1 with s2
        size_t found = 0;
        static const size_t pos = -1;
        while ((found = readLine.find(_s1, found)) != pos)
        {
            readLine.replace(found, _s1.length(), _s2);
            found += _s2.length();
        }
        outputFile << readLine << std::endl;
    }
    inputFile.close();
    outputFile.close();
    std::cout <<"file content replaced and saved to " << _fileName + ".replace" << std::endl;
}