/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:21:26 by ihama             #+#    #+#             */
/*   Updated: 2023/10/24 13:54:19 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        std ::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std ::endl;
        return 1;
    }
    for (int i = 1; argv[i]; ++i)
    {
        for (int j = 0; argv[i][j]; j++)
            std ::cout << (char) toupper(argv[i][j]);
        std :: cout << ' ';
    }
    std:: cout << std::endl;
}