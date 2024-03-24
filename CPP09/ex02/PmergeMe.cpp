/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:19:14 by ihama             #+#    #+#             */
/*   Updated: 2024/03/24 15:06:58 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** toSorted): _toSorted(toSorted), timeV(0), timeD(0){

    sort();
   int x = 1;
    while (toSorted[x]) {
        int num = atoi(toSorted[x]);
        vc.push_back(num);
        dq.push_back(num);
        x++;
    }
}

char** PmergeMe::getTosorted(void) const{
    return (this->_toSorted);
}

PmergeMe::PmergeMe(const PmergeMe& copy): _toSorted(copy._toSorted), timeV(copy.timeV), timeD(copy.timeD){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    PmergeMe::_toSorted = other.getTosorted();
    return *this;
}

PmergeMe::~PmergeMe()
{
}

/*
    1
        vc[i] is selected as the key element for comparison and insertion. 
        This element will be compared with the elements before it to find its correct position in the sorted sequence.
    2
        After selecting the key element, a while loop is used to iterate backwards through the already sorted portion of the subarray (from i - 1 to left).
        Within this loop, each element vc[j] that is greater than the key element key is shifted one position to the right (vc[j + 1]) to make room for the key element.
        The loop continues until either the beginning of the subarray is reached or an element smaller than or equal to the key is encountered.
*/

//This function implements the insertion sort algorithm to sort a subarray of the vector vc between indices left and right.
void PmergeMe::insertionVector(int left, int right)
{
    // Iteration through the Subarray:
    for (int i = left; i <= right; i++)
    {
        //1
        int key = PmergeMe::vc[i]; 
        int j = i - 1;
        //2
        while (j >= left && vc[j] > key)
        {
            PmergeMe::vc[j + 1] = PmergeMe::vc[j];
            --j;
        }
        PmergeMe::vc[j + 1] = key;
    } 
}
void PmergeMe::insertionDeque(int left, int right)
{
    // Iteration through the Subarray:
    for (int i = left; i <= right; i++)
    {
        //1
        int key = PmergeMe::vc[i]; 
        int j = i - 1;
        //2
        while (j >= left && vc[j] > key)
        {
            PmergeMe::vc[j + 1] = PmergeMe::vc[j];
            --j;
        }
        PmergeMe::vc[j + 1] = key;
    } 
}
// function for getting Time for Vector and list
double PmergeMe::getTimeV()
{
    return (PmergeMe::timeV);
}
double PmergeMe::getTimeL()
{
    return (PmergeMe::timeD);
}

// function for loading element to Vector and List
void PmergeMe::parsElemVec(std::string str)
{
    int num = atoi(str.c_str());
    PmergeMe::vc.push_back(num);
}
void PmergeMe::parsELemList(std::string str)
{
    int num = atoi(str.c_str());
    PmergeMe::vc.push_back(num);
}
//After completing these steps, the vc vector will be sorted.
void PmergeMe::mergeVector(int left, int mid, int right)
{
    std::vector<int> leftRange(PmergeMe::vc.begin() + left, PmergeMe::vc.begin() + mid + 1);
    std::vector<int> rightRange(PmergeMe::vc.begin() + mid + 1, PmergeMe::vc.begin() + right + 1);

    std::vector<int>::iterator leftIterat = leftRange.begin();
    std::vector<int>::iterator rightIterat = rightRange.begin();
    std::vector<int>::iterator vecIterat = vc.begin() + left;

    while (leftIterat != leftRange.end() && rightIterat != rightRange.end())
    {
        if (*leftIterat <= *rightIterat)
            *vecIterat++ = *leftIterat++;
        else
            *vecIterat++ = *rightIterat++;
    }

    while (leftIterat != leftRange.end())
    {
        *vecIterat++ = *leftIterat++;
    }
    while (rightIterat != rightRange.end())
    {
        *vecIterat++ = *rightIterat++;
    }
}
//After completing these steps, the deque vector will be sorted.
void PmergeMe::mergeDeque(int left, int mid, int right)
{
    std::deque<int> leftRange(PmergeMe::dq.begin() + left, PmergeMe::dq.begin() + mid + 1);
    std::deque<int> rightRange(PmergeMe::dq.begin() + mid + 1, PmergeMe::dq.begin() + right + 1);

    std::deque<int>::iterator leftIterat = leftRange.begin();
    std::deque<int>::iterator rightIterat = rightRange.begin();
    std::deque<int>::iterator vecIterat = dq.begin() + left;

    while (leftIterat != leftRange.end() && rightIterat != rightRange.end())
    {
        if (*leftIterat <= *rightIterat)
            *vecIterat++ = *leftIterat++;
        else
            *vecIterat++ = *rightIterat++;
    }

    while (leftIterat != leftRange.end())
    {
        *vecIterat++ = *leftIterat++;
    }
    while (rightIterat != rightRange.end())
    {
        *vecIterat++ = *rightIterat++;
    }
}


void PmergeMe::sortVector(int left, int right)
{
    if (left < right)
    {
        // Find the middle index of the array
        int mid = left + (right - left) / 2;

        // Check if the size of the current array segment is small enough for insertion sort
        if (right - left <= 20)
            insertionVector(left, right); // Use insertion sort for small arrays
        else {
            // Recursively sort the left half of the array
            sortVector(left, mid);
            // Recursively sort the right half of the array
            sortVector(mid + 1, right);
            // Merge the sorted halves
            mergeVector(left, mid, right);
        }
    }
}
void PmergeMe::sortDeque(int left, int right)
{
    if (left < right)
    {
        // Find the middle index of the array
        int mid = left + (right - left) / 2;

        // Check if the size of the current array segment is small enough for insertion sort
        if (right - left <= 20)
            insertionVector(left, right); // Use insertion sort for small arrays
        else {
            // Recursively sort the left half of the array
            sortVector(left, mid);
            // Recursively sort the right half of the array
            sortVector(mid + 1, right);
            // Merge the sorted halves
            mergeVector(left, mid, right);
        }
    }
}

void PmergeMe::sort()
{
    clock_t beginTime = clock();
    sortVector(0, PmergeMe::vc.size() - 1); // Start sorting from index 0 to size - 1
    clock_t endTime = clock();
    PmergeMe::timeV = static_cast<double>(endTime - beginTime) / CLOCKS_PER_SEC;

    clock_t beginTime1 = clock();
    sortDeque(0, PmergeMe::dq.size() - 1); // Start sorting from index 0 to size - 1
    clock_t endTime1 = clock();
    PmergeMe::timeD = static_cast<double>(endTime1 - beginTime1) / CLOCKS_PER_SEC;
}

void PmergeMe::PrintArray() {
    for (size_t i = 0; i < vc.size(); ++i) {
        std::cout << vc[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVector1(std::vector<int>& v) {
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int>& dq) {
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}
void PmergeMe::printVector() {
    std::vector<int>::iterator it;
    for (it = vc.begin(); it != vc.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

size_t PmergeMe::getVectorSize() const {
    return vc.size();
}

size_t PmergeMe::getDequeSize() const {
    return dq.size();
}

// void PmergeMe::printVector1(std::vector<int> &v)
// {
// 	std::vector<int>::iterator	it;
// 	for (it = v.begin(); it != v.end(); ++it)
// 		std::cout << " " << *it;
// 	std::cout << std::endl;
// }
// void PmergeMe::printDeque(std::deque<int> &dq)
// {
// 	std::deque<int>::iterator	it;
// 	for (it = dq.begin(); it != dq.end(); ++it)
// 		std::cout << " " << *it;
// 	std::cout << std::endl;
// }

// void PmergeMe::sortVector(int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         sortVector(left, mid);
//         sortVector(mid + 1, right);
//         mergeVector(left, mid, right);
//     }
// }

