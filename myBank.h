#ifndef _MYBANK_H
#define _MYBANK_H
#define BANKS 50
#define CASES 2
extern double Accounts[BANKS][CASES];
extern int numOfAccounts;

double save2Dec(double amount);
void firstDeposit(double amount,double Accounts[BANKS][CASES],int numOfAccounts);
void printBalance(int accountNumber,double Accounts[BANKS][CASES]);
void deposit(int accountNumber,double Accounts[BANKS][CASES],double depositAmount);
void withdraw(int accountNumber,double Accounts[BANKS][CASES],double depositAmount);
void close(int accountNumber,double Accounts[BANKS][CASES]);
void interest(double interestRate,double Accounts[BANKS][CASES],int numOfAccounts);
void printAccounts(double Accounts[BANKS][CASES]);
void closeAccounts(int numOfAccounts,double Accounts[BANKS][CASES]);



#endif
