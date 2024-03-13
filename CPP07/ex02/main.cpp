/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:20:56 by ihama             #+#    #+#             */
/*   Updated: 2024/03/12 15:29:52 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"Test Default contructor "<<std::endl;
        std::cout<<"------------------------"<<std::endl;

        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        std::cout<<"-------------------------------"<<std::endl;
        std::cout<<"End of Test Default contructor "<<std::endl;
        std::cout<<"-------------------------------"<<std::endl;

        std::cout<<"\n"<<std::endl;

        // Test constructor with size parameter
        std::cout<<"-------------------------------------"<<std::endl;
        std::cout<<"Test constructor with size parameter "<<std::endl;
        std::cout<<"-------------------------------------"<<std::endl;
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;
        unsigned int i = 0;
        std::cout << "Elements of arr2: ";
        while (i < arr2.size())
        {
            /* code */
            arr2[i] = i + 3;
            std::cout << arr2[i] << " ";
            i++;
        }
        std::cout << std::endl;
        // Test constructor with size parameter
        std::cout<<"-----------------------------------------"<<std::endl;
        std::cout<<"End Test constructor with size parameter "<<std::endl;
        std::cout<<"-----------------------------------------"<<std::endl;
        std::cout<<"\n"<<std::endl;
        // Test copy constructor
        std::cout<<"-----------------------"<<std::endl;
        std::cout<<" Test copy constructor "<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        Array<int> arrA(arr2);
        std::cout << "Size of arrA: " << arrA.size() << std::endl;
        std::cout<<"-----------------------"<<std::endl;
        std::cout<<" End Test copy constructor "<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        std::cout<<"\n"<<std::endl;
        // Test assignment operator
        std::cout<<"--------------------------"<<std::endl;
        std::cout<<" Test assignment operator "<<std::endl;
        std::cout<<"--------------------------"<<std::endl;
        Array<int> arr3;
        arr3 = arr2;
        std::cout << "Size of arr3: " << arr3.size() << std::endl;

        // Test subscript operator
        std::cout << "Elements of arr3: ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;
        std::cout<<"------------------------------"<<std::endl;
        std::cout<<" End Test assignment operator "<<std::endl;
        std::cout<<"------------------------------"<<std::endl;
        std::cout<<"\n"<<std::endl;
        // Test out of bounds access
        std::cout<<"-------------------------------------------"<<std::endl;
        std::cout<<" Trying to access out of bounds element... "<<std::endl;
        std::cout<<"-------------------------------------------"<<std::endl;
        /*
            should indeed throw an exception because array 
            indexing in C++ is zero-based, meaning the valid indices 
            range from 0 to size() -1 .
        */
        std::cout << arr3[arr3.size()] << std::endl; // This should throw an exception
    } catch (const Array<int>::OutOfBounds& e) {
        std::cerr << e.what() << std::endl;
    }
    // system("leaks Array");
    return 0;
}
