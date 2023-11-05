/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:34:29 by ihama             #+#    #+#             */
/*   Updated: 2023/10/22 22:10:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

// Init all the start-values
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor with init deposit
// after the creation a note about the created account is printed
Account::Account(int initial_deposit)
{
    _displayTimestamp();
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_totalAmount += _amount;
    std::cout<<"index:" << _accountIndex <<";" <<"amount:" <<_amount << ";" << "created" << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout<<"index:" << _accountIndex <<";" <<"amount:" <<this->checkAmount() << ";" << "closed" << std::endl;
    // Account::_nbAccounts--;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";"
    << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() <<std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    Account::_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout<<"index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "deposit:"
    << deposit << ";" << "amount:" << _amount + deposit << ";" << "nb_deposits:" << _nbDeposits <<std::endl;
    this->_amount += deposit;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout<<"index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawals"; 
    if (_amount < withdrawal)
    {
        std:: cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    Account::_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std ::cout << withdrawal << ";"  << "amount:" << _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout<<"index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" <<_nbDeposits
        << ";" << "withdrawals" << _nbWithdrawals <<std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t actuTime;
    struct tm *infoTime;
    char buf[19];
    time(&actuTime);
    infoTime = localtime(&actuTime);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", infoTime);
    std::cout<< buf;
}