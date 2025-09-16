#include <stdio.h>
#include <stdlib.h>
/*
@Zaraar
Last Updated: 16-09-2025
*/

typedef char string[20];
int currentAccount = 0;

typedef struct {
    string name;
    int accountNumber;
    float balance;
} account;

account *userAccount;

void startBankingSystem(){
    printf("Welcome to the Banking System\n");
    int choice;
    do {
        printf("Controls: \n");
        if (userAccount == 0){
            printf("1) Create Account\n");
        }else{
            printf("Logged in as: %s | Account Number: %d | Balance: %.2f\n", userAccount->name, userAccount->accountNumber, userAccount->balance);
        }
        printf("2) Deposit\n3) Withdraw\n4) Check Balance\n0) Exit\n");
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
                userAccount = &newAccount;
                printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
            }
            break;
            case 2:
            {
                if (userAccount == 0) {
                    printf("No account found. Please create an account first.\n");
                    break;
                }
                float depositAmount;
                printf("Enter amount to deposit: ");
                scanf("%f", &depositAmount);
                userAccount->balance += depositAmount;
                printf("Deposited %.2f to account %d (%s)\n", depositAmount, userAccount->accountNumber, userAccount->name);
            }
            break;
            case 3:
            {
                if (userAccount == 0) {
                    printf("No account found. Please create an account first.\n");
                    break;
                }
                float withdrawAmount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdrawAmount);
                if (withdrawAmount > userAccount->balance) {
                    printf("Insufficient balance!\n");
                } else {
                    userAccount->balance -= withdrawAmount;
                    printf("Withdrew %.2f from account %d\n", withdrawAmount, userAccount);
                }
            }
            break;
            case 4:
            {
                if (userAccount == 0) {
                    printf("No account found. Please create an account first.\n");
                    break;
                }
                printf("Current balance: %.2f\n", userAccount->balance);
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