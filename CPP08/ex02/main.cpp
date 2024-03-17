/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:40:19 by ihama             #+#    #+#             */
/*   Updated: 2024/03/16 15:11:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5); 
    mstack.push(17);
    std::cout << mstack.top() << std::endl; 
    mstack.pop();
    std::cout <<"size actual : " << mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mstack);
    // system("leaks MutantStack");
    return 0;
}
