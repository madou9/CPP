/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:19:16 by ihama             #+#    #+#             */
/*   Updated: 2024/03/24 15:09:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Function to check if a string contains only numeric characters
bool isNumeric(const char* str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc < 3 || argc > 3001) {
        std::cerr << "Please provide a positive integer sequence as argument." << std::endl;
        return -1;
    }

    // Check if all arguments are numeric
    for (int i = 1; i < argc; ++i) {
        if (!isNumeric(argv[i])) {
            std::cerr << "Error: non-numeric value detected." << std::endl;
            return -1;
        }
    }

    PmergeMe sorting(argv);
//    for (int i = 1; i < argc; i++) {
//     sorting.parsElemVec(argv[i]); // Parse elements and store them in the vector
//     sorting.parsELemList(argv[i]); // Parse elements and store them in the vector
// }
    std::cout << "Before: ";
    sorting.PrintArray();
    
    sorting.sort();

    std::cout << "After: ";
    sorting.PrintArray();
    // sorting.PrintArray(); // Print the sorted array

    // Display time taken for sorting
    std::cout << "Time to process a range of " << sorting.getVectorSize() << " elements with std::vector: " << sorting.getTimeV() << " us" << std::endl;
    std::cout << "Time to process a range of " << sorting.getDequeSize() << " elements with std::deque: " << sorting.getTimeL() << " us" << std::endl;

    return 0;
}

