/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:20:25 by ihama             #+#    #+#             */
/*   Updated: 2023/12/26 19:59:41 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
    Initializing brain(new Brain()) in the constructor of Dog and Cat is
    necessary because it allocates memory for the Brain object and sets the brain
    pointer to point to that newly allocated memory. This dynamic allocation ensures
    that each Dog and Cat object has its own distinct Brain instance.
*/

Brain::Brain(/* args */)
{
    std::cout << "Default Constructor for Brain is called!!" << std::endl;
}

Brain::Brain(const Brain &reff)
{
    int count = 100;
    // Perform deep copy of the ideas array
    for (size_t i = 0; i < count; i++)
        ideas[i] = reff.ideas[i];
    std::cout << "copy constructor for Brain called!!" << std::endl;
}
Brain &Brain::operator=(const Brain &other)
{
    int count = 100;
    if (this != &other)
    {
        for (size_t i = 0; i < count; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor for ~Brain called!!" << std::endl;
}