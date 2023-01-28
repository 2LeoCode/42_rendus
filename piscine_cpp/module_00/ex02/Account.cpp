/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 04:50:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/18 19:49:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <ctime>
#include <cstdlib>

int	Account::_nbAccounts(0);
int	Account::_totalAmount(0);
int	Account::_totalNbDeposits(0);
int	Account::_totalNbWithdrawals(0);

static std::string	timestamp;

static std::ofstream	&log(void);


static std::ofstream	&log(void) {
	static std::ofstream log(
		(timestamp + ".log").c_str(),
		std::ios::out | std::ios::app
	);
	return log;
}

static void	updateTimestamp(void) {
	std::ostringstream	timeStampStream;
	time_t				rawTime(time(NULL));
	struct tm			*timeinfo;

	timeinfo = localtime(&rawTime);
	timeStampStream << timeinfo->tm_year + 1900;
	if (timeinfo->tm_mon < 9) timeStampStream << '0';
	timeStampStream << timeinfo->tm_mon + 1;
	if (timeinfo->tm_mday < 10) timeStampStream << '0';
	timeStampStream << timeinfo->tm_mday;
	timeStampStream << '_';
	timeStampStream << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec;
	timestamp = timeStampStream.str();
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}
int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	log() << "accounts:" << _nbAccounts << ';';
	log() << "total:" << _totalAmount << ';';
	log() << "deposits:" << _totalNbDeposits << ';';
	log() << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++),
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += _amount;
	
	_displayTimestamp();
	log() << "index:" << _accountIndex << ';';
	log() << "amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	log() << "index:" << _accountIndex << ';';
	log() << "amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	++_totalNbDeposits;
	_totalAmount += deposit;
	_displayTimestamp();
	log() << "index:" << _accountIndex <<
		";p_amount:" << _amount <<
		";deposit:" << deposit <<
		";amount:" << _amount + deposit <<
		";nb_deposits:" << ++_nbDeposits <<
	std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	log() <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount <<
		";withdrawal:";
	_amount -= withdrawal;
	if (!checkAmount()) {
		log() << "refused" << std::endl;
		_amount += withdrawal;
		return (false);
	}
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	log() << withdrawal <<
		";amount:" << _amount <<
		";nb_withdrawals:" << ++_nbWithdrawals <<
	std::endl;
	return (true);
}

int		Account::checkAmount(void) const {
	return (_amount >= 0);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	log() <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";deposits:" << _nbDeposits <<
		";withdrawals:" << _nbWithdrawals <<
	std::endl;
}

void	Account::_displayTimestamp(void) {
	updateTimestamp();
	log() << '[' << timestamp << "] ";
}
