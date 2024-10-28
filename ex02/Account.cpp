
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <ctime>
#include <iomanip>


int counter = 0;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::vector<int> accountAmounts; 
std::vector<int> deposits;
std::vector<int> deposits_nb;
std::vector<int> withdrawals_nb;
std::vector<int> withdrawals;

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
            << now << "_"
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
    if (!_nbDeposits)
        deposits_nb.push_back(0);
    _totalNbDeposits++;
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    deposits.push_back(deposit);
    deposits_nb[_accountIndex]++;

}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (!_nbWithdrawals)
        withdrawals_nb.push_back(0);
    if (withdrawal > checkAmount())
    {
        withdrawals.push_back(-1);
        return (0);
    }
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    withdrawals.push_back(withdrawal); 
    withdrawals_nb[_accountIndex]++;
    return (1);
}
void Account::	displayAccountsInfos( void )
{
    for (int i = 0; i < getNbAccounts() &&( getNbDeposits() || getNbWithdrawals()); i++)
    {
        Account::_displayTimestamp();

        std::cout  << " index:" << i << ";";

        if (getNbDeposits() && !getNbWithdrawals())
        {
            std::cout << "p_amount:" << accountAmounts[i] << ";"
                    << "deposit:" << deposits[i] << ";"
                    << "amount:" << accountAmounts[i] + deposits[i] << ";"
                    << "nb_deposits:" << deposits_nb[i];
            
            accountAmounts[i] += deposits[i];
        }
        else if (getNbWithdrawals())
        {
            std::cout << "p_amount:" << accountAmounts[i] << ";";
            if (withdrawals[i] == -1)
                std::cout << "withdrawal:" << "refused";

            else
            {
                std::cout << "withdrawal:" << withdrawals[i] << ";"
                        << "amount:" << accountAmounts[i] - withdrawals[i] << ";"
                        << "nb_withdrawals:" << withdrawals_nb[i];

                accountAmounts[i] -= withdrawals[i];
            }
        }
            std::cout << std::endl;
    }

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
    _totalAmount+=_amount;
    _nbAccounts++;
    accountAmounts.push_back(_amount); 
    _accountIndex = counter;
    counter++;
    
    Account::_displayTimestamp();
    std::cout  << " index:" << _accountIndex << ";";
    std::cout << "amount:" << accountAmounts[_accountIndex] << ";" << "created\n";
}
Account::~Account( void )
{
    Account::_displayTimestamp();

    std::cout  << " index:" << _accountIndex << ";";

    std::cout << "amount:" << accountAmounts[_accountIndex] << ";" << "closed\n";
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();

    std::cout  << " index:" << _accountIndex << ";";

    std::cout << "amount:" << accountAmounts[_accountIndex] << ";"  
            << "deposits:" << _nbDeposits << ";" 
            << "withdrawals:" << _nbWithdrawals << "\n";
}

// int main()
// {
    
//     Account a1(100);
//     Account a2(200);
//     Account::displayAccountsInfos();
//     a1.makeDeposit(12);
//     a1.makeDeposit(23);
//     Account::displayAccountsInfos();
// }