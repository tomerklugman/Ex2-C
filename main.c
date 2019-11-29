#include <stdio.h>
#include "myBank.h"

int main()
{
    
    char tranType=0;
    double amount=0;   
    int accountNum=0;
    double interestRate=0;

    printf("options in myBank:\n O-Open account and deposit initial amount \n B-check Balance \n D-Deposit \n W-Withdraw \n C-Close account \n I-add Interest to all accounts \n P-Prints all accounts \n E-close and zero all accounts then Exit program \n");

   while(tranType!='E')
    {
    
    printf("Transaction type?:");
    if(scanf(" %c",&tranType)==1) {
                    
     switch(tranType)
     {
       
    case 'O': // OPEN BANK ACCOUNT
             if(numOfAccounts<50) {
               firstDeposit(amount,Accounts,numOfAccounts);
               numOfAccounts++;
                 } else {
                  printf("too many accounts \n");
             }
             break;
    
    case 'B': // CHECK BALANCE
             if(numOfAccounts<=0) {
               printf("no accounts to print balance \n");
                } else {
                 printBalance(accountNum,Accounts);
                 }
             break;
             
    case 'D': // DEPOSIT
             if(numOfAccounts<=0) {
              printf("no accounts to deposit \n");
               } else {
                deposit(accountNum,Accounts,amount);
                }
             break;
             
    case 'W': // WITHDRAW
             if(numOfAccounts<=0) {
              printf("no accounts to withdraw \n");
               } else {
                withdraw(accountNum,Accounts,amount);
                }
             break;
             
    case 'C': // CLOSE ACCOUNT
             if(numOfAccounts<=0) {
              printf("no accounts to close \n");
               } else {
                close(accountNum,Accounts);
                numOfAccounts--;
               }
             break;
             
    case 'I': // INTEREST 
             if(numOfAccounts<=0) {
              printf("no accounts to add interest \n");
               } else {
                interest(interestRate,Accounts,numOfAccounts);
                }
             break;
             
    case 'P': // PRINT ALL ACCOUNTS AND BALANCE
             if(numOfAccounts<=0) {
                 printf("no accounts to print \n");
                  } else {
                   printAccounts(Accounts);
                   }
             break;
             
    case 'E': // CLOSE ACCOUNTS AND END PROGRAM
             closeAccounts(numOfAccounts,Accounts);
             numOfAccounts=0;
             tranType='E';
             break;
           
    default: 
             printf("enter a valid case \n");
             break;
        
       
     }
   }
}



    return 0;
}
