/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:05:34 by ihama             #+#    #+#             */
/*   Updated: 2023/11/02 21:10:22 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
    const std::string fileName = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    if (argc != 4)
    {
        std::cout<<"Usage: " << argv[0] << "infile <s1> <s2>" << std::endl;
        return 1;
    }
    Replace remplacer(fileName, s1, s2);
    remplacer.replaceContent();
    return 0;
}