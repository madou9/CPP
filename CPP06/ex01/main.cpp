/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:35:09 by ihama             #+#    #+#             */
/*   Updated: 2024/03/06 12:24:52 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data data(586);
    std::cout<<"----------------------------------------------------------------"<<std::endl;
    std::cout<<"First let's show all the value of Data Serialize and Deserialize" <<std::endl;
    std::cout<<"----------------------------------------------------------------"<<std::endl;
    // Serialize the address of the Data object
    uintptr_t serializedPtr = Serializer::serialize(&data);
    std::cout<<"Serializer Pointer : " << &serializedPtr << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);
    std::cout<<" deserializer Pointer: "<<deserializedPtr<<std::endl;
    std::cout<<"Data Adress : " << &data << std::endl;

    std::cout<<"\n"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
    std::cout<<"Lest's check Condition for deserialize and data" <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
     // Check if the deserialized pointer is equal to the original pointer
    if (deserializedPtr == &data) {
        std::cout << "Serialization and deserialization \033[1;31m successful!\033[0m" << std::endl;
    } else {
        std::cout << "Serialization and deserialization \033[1;31m failed!\033[0m" << std::endl;
    }

    //     // Check if the deserialized value matches the original value
    // if (deserializedPtr->getValue() == data.getValue()) {
    //     std::cout << "Serialization and deserialization \033[1;31m successful!\033[0m" << std::endl;
    // } else {
    //     std::cout << "Serialization and deserialization \033[1;31m failed!\033[0m" << std::endl;
    // }
    // system("leaks Serializer");
    return 0;
}
