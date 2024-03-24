/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:19:09 by ihama             #+#    #+#             */
/*   Updated: 2024/03/24 15:02:58 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <deque>
#include <time.h>
#include <cstring> // Include for the use of std::isdigit function

class PmergeMe
{
private:
    /* data */
    char** _toSorted;
    std::vector<int> vc;
    std::deque<int> dq;

    double timeV;
    double timeD;
public:
    PmergeMe(char** toSorted);
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& other);
    char** getTosorted(void) const;
    ~PmergeMe();

    //sort for vector
    void sortVector(int left, int right);
    void insertionVector(int left, int right);
    void mergeVector(int left, int mid, int right);

    // //Sort for deque
    void sortDeque(int left, int right);
    void insertionDeque(int left, int right);
    void mergeDeque(int left, int mid, int right);

    //sort
    void sort();
    // void parsing();
    void PrintArray();
    void printVector();
    void printVector1(std::vector<int> &v);
    void printDeque(std::deque<int> &dq);

    // parse elem vector and list

    void parsElemVec(std::string str);
    void parsELemList(std::string str);
    
    // get Time for vec and list

    double getTimeV();
    double getTimeL();

    size_t getVectorSize() const;
    size_t getDequeSize() const;
};
