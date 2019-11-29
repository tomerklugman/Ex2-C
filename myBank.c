#include <stdio.h>
#include "myBank.h"



double Accounts[BANKS][CASES]={0}; // Accounts[Account num][0,1] [][0]- (1)open/(0)closed account [][1]-balance 
int numOfAccounts=0;

double save2Dec(double amount){
    
    amount=amount*100;
    int x=amount;
    amount=0;
    amount=(double)x/100;
    return amount;
}

void firstDeposit(double amount,double Accounts[BANKS][CASES],int numOfAccounts) {
    
    printf("Initial deposit? ");
             if(scanf("%lf",&amount)==1) {
                 if(amount<0) {
                    printf("can only deposit positive number \n");
                    return;
                    }
                 for(int j=0;j<=numOfAccounts;j++) {
                   if(Accounts[j][0]==0) {
                    Accounts[j][0]=1;
                    Accounts[j][1]=save2Dec(amount);
                    break;
            
                    }
                  }
    printf("your account number is: %d \n",901+numOfAccounts);
            } else {
              printf("enter normal amount");
               }
             }

void printBalance(int accountNumber,double Accounts[BANKS][CASES]) {
         printf("Account number?");
          if(scanf("%d",&accountNumber)==1) {
            if(accountNumber<901||accountNumber>950||Accounts[accountNumber-901][0]==0) {
               printf("no existing account \n");
               } else {
                 if(Accounts[accountNumber-901][0]==1) {
                   printf("your account balance is: %0.2lf \n",Accounts[accountNumber-901][1]);
                   }
               }
           }
       }

void deposit(int accountNumber,double Accounts[BANKS][CASES],double depositAmount) {
      printf("Account number?");
      if(scanf("%d",&accountNumber)==1) {
       if(accountNumber<901||accountNumber>950||Accounts[accountNumber-901][0]==0) {
          printf("account doesnt exist");
          return;
         }
          printf("Amount?");
          if(scanf("%lf",&depositAmount)==1) {
             if(depositAmount>0) {
               if(Accounts[accountNumber-901][0]==1){
                  Accounts[accountNumber-901][1]=Accounts[accountNumber-901][1]+save2Dec(depositAmount);
                  printf("new account balance is: %0.2lf \n", Accounts[accountNumber-901][1]);
                  }
        
                } else { printf("can only deposit positive number\n ");
                    
                }
            }
      }
}

void withdraw(int accountNumber,double Accounts[BANKS][CASES],double withdrawAmount){
            printf("Account number?");
            if(scanf("%d",&accountNumber)==1) {
              printf("Amount?");
              if(scanf("%lf",&withdrawAmount)==1) {
                 if(withdrawAmount<0) {
                    printf("please enter a positive number to withdraw \n");
                    return;
                   }
                 if(accountNumber<901||accountNumber>950||Accounts[accountNumber-901][0]==0) {
                    printf("account doesnt exist");
                    }
                     if(Accounts[accountNumber-901][0]==1) {
                       if(Accounts[accountNumber-901][1]>=withdrawAmount) {
                         Accounts[accountNumber-901][1]=Accounts[accountNumber-901][1]-save2Dec(withdrawAmount);
                         printf("new account balance is: %0.2lf \n", Accounts[accountNumber-901][1]);
                         } else { printf("withdraw higher then balance \n");
                  }
             }
         }
     }
}

void close(int accountNumber,double Accounts[BANKS][CASES]){
             printf("Account number?");
             if(scanf("%d",&accountNumber)==1) {
              if(accountNumber<901||accountNumber>950||Accounts[accountNumber-901][0]==0) {
                printf("account doesnt exist \n");
                return;
                } else {
                 Accounts[accountNumber-901][0]=0;
                 Accounts[accountNumber-901][1]=0;
                 }
             } 
        printf("account closed \n"); 
      }

void interest(double interestRate,double Accounts[BANKS][CASES],int numOfAccounts){
         printf("Interest rate?");
         if(scanf("%lf",&interestRate)==1) {
            if(interestRate>0) {
             for(int j=0;j<numOfAccounts;j++) {
               Accounts[j][1]=Accounts[j][1]*(1+interestRate/100);
               printf("interest of: %g%% added \n",interestRate);
               }
             } else { printf("please enter a positive interest rate \n");
         }
     }
}

void printAccounts(double Accounts[BANKS][CASES]){
    for(int j=0;j<50;j++){
        if(Accounts[j][0]==1){
        printf("account number: %d balance: %0.2lf \n",901+j,Accounts[j][1]);
       
        }
    }
}

void closeAccounts(int numOfAccounts,double Accounts[BANKS][CASES]){
    for(int j=0;j<numOfAccounts;j++){
        Accounts[j][0]=0;
          Accounts[j][1]=0;
    }
    
}



