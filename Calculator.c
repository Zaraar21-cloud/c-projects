/*
LAST UPDATED: 13th September 2025
*/

#include <stdio.h>
#include <stdlib.h>

int currentOperator;

void getNumbers(float *a, float *b){
    printf("Enter the first number: ");
    scanf(" %f", a);
    printf("Enter the second number: ");
    scanf(" %f", b);
}

void startCalculator(){
    do{
        printf("*** CALCULATOR***\n=================\n");
        printf("1) Add \n");
        printf("2) Subtract \n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("5) Power\n");
        printf("0) EXIT\n");
        printf("Choose:");

        int choice;
        scanf("%d",&choice);
        if (choice > 5 || choice < 0){
            printf("Please choose a valid option!\n");
            continue;
        }else if(choice == 0){
            printf("Exiting the calculator...\n");
            break;
        }else{
            float a, b;
            getNumbers(&a, &b);
            switch(choice){
                case 1:
                {
                    printf("\nThe sum is: %.3f \n", (a + b));
                }
                break;

                case 2:
                {
                    printf("\nThe difference is: %.3f \n", (a - b));
                }
                break;

                case 3:
                {
                    printf("\nThe product is: %.3f \n", (a * b));
                }
                break;
                case 4:
                {
                    printf("\nThe quotient is: %.3f \n", (a / b));
                }
                break;

                case 5:
                {
                    float result = 1.00;
                    for(int i = 0; i < b; i++){
                        result *= a;
                    }
                    printf("\nThe result is: %.3f \n", result);
                }
                break;
            }
        }

    }while(1);
    
}

void main(){
    
    startCalculator();
}
