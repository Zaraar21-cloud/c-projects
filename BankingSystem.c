#include <stdio.h>
#include <stdlib.h>
/*
@Zaraar
Last Updated: 16-09-2025
*/

typedef char string[20];
int currentAccount = 0;
int userAccount = 0;

typedef struct {
    string name;
    int accountNumber;
    float balance;
} account;

void startBankingSystem(){
    printf("Welcome to the Banking System\n");
    int choice;
    do {
        
        printf("Controls:\n 1) Create Account\n 2) Deposit\n 3) Withdraw\n 4) Check Balance\n 0) Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        if (choice > 0 && choice < 4) {
           switch(choice){
            case 1:
            {
                account newAccount;
                printf("Enter your name: ");
                scanf("%s", newAccount.name);
                printf("Enter initial deposit: ");
                scanf("%f", &newAccount.balance);
                newAccount.accountNumber = currentAccount + 1;
                currentAccount++;
                printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
            }
           }
        }else{
            if (choice == 0) {
                printf("Exiting the Banking System...\n");
                break;
            } else {
                printf("Please choose a valid option!\n");
            }
        }
    }while(choice != 0);
    
    
}


int main(){
    startBankingSystem();
    return 0;
}