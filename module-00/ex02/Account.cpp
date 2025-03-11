#include <iostream>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _totalAmount += initial_deposit;

  _displayTimestamp();

  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created"
            << std::endl;
}

Account::~Account( void ) {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed"
            << std::endl;
}

void	Account::_displayTimestamp( void ) {
  std::time_t now = std::time(nullptr);
  char buf[64];

  if (strftime(buf, sizeof buf, "[%Y%m%d_%H%M%S]", std::localtime(&now))) {
    std::cout << buf << " ";
  }
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos( void ) {
  _displayTimestamp();

  std::cout << "accounts:" << getNbAccounts()
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
            << std::endl;
}

void	Account::displayStatus( void ) const {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void	Account::makeDeposit( int deposit ) {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";deposit:" << deposit;
  
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;

  std::cout << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

int		Account::checkAmount( void ) const { return _amount; }

bool	Account::makeWithdrawal( int withdrawal ) {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;

  if (withdrawal > checkAmount()) {
    std::cout << ";withdrawal:refused"
              << std::endl;
    return (false);
  }

  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;

  std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;

  return (true);
}
