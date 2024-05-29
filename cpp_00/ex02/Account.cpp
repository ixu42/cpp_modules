/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:28:16 by ixu               #+#    #+#             */
/*   Updated: 2024/05/29 17:09:31 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previous_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << previous_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused\n";
		return (false);
	}
	int	previous_amount = _amount;
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << previous_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t	currentTime = std::time(nullptr);
	std::tm		*localTime = std::localtime(&currentTime);

	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]";
}
