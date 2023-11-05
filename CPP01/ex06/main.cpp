/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:27:24 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 09:43:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
    if (argc != 2)
    {
        std::cerr << "Error" <<std::endl;
        return (1);
    }
    harl.filterComplain(argv[1]);
    return 0;
}
