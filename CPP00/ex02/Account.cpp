#include <iostream>
#include <functional>
#include "Account.hpp"
#include <ctime>
#include <iomanip>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
    time_t now;
    time(&now);
    std::tm *local_time = std::localtime(&now);

    std::cout << "["
        << 1900 + local_time->tm_year 
        << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1 
        << std::setfill('0') << std::setw(2) << local_time->tm_mday
        << "_"
        << std::setfill('0') << std::setw(2) << local_time->tm_hour
        << std::setfill('0') << std::setw(2) << local_time->tm_min
        << std::setfill('0') << std::setw(2) << local_time->tm_sec
        << "]";
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout  << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    _nbDeposits++;
    _amount += deposit;
    std::cout   << "deposit:" << deposit << ";"
                << "amount:" << _amount << ";"
                << "nb_deposits:" << _nbDeposits
                << std::endl;
    _totalNbDeposits++;
    _totalAmount += deposit;

}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout  << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > checkAmount())
    {
        std::cout   << "withdrawal:" << "refused"
                << std::endl;
        return (0);
    }
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout   << "withdrawal:" << withdrawal << ";"
                << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals
                << std::endl;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    return (1);
}
void Account::	displayAccountsInfos( void )
{
    Account::_displayTimestamp();
        std::cout << " accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "Withdrawals:" << getNbWithdrawals()
              << std::endl;
}
Account::Account( void )
{
}
Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    
    Account::_displayTimestamp();
    std::cout  << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";" << "created\n";
}
Account::~Account( void )
{
    Account::_displayTimestamp();

    std::cout  << " index:" << _accountIndex << ";";

    std::cout << "amount:" << _amount << ";" << "closed\n";
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();

    std::cout  << " index:" << _accountIndex << ";";

    std::cout << "amount:" << _amount << ";"  
            << "deposits:" << _nbDeposits << ";" 
            << "withdrawals:" << _nbWithdrawals << "\n";
}
