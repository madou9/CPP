/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:38:44 by ihama             #+#    #+#             */
/*   Updated: 2023/11/03 09:10:13 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    // std::string level;

    // std::cin>> level;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");

    return 0;
}