#include <stdio.h>
/*
@Zaraar
Last Modified: 26th September 2025
This program converts an integer to its binary representation.
College assignment.
*/
int number_of_elements(int num){
    int elements = 0;
    do {
        num /=2;
        elements++;
    }while(num!=0);
    
    return elements;
}

int main() {
    int n;
    printf("Enter a number to convert to binary: ");
    scanf("%d",&n);
    int isNegative = 0 ;

    if(n < 0){
        n = -n;
        isNegative = 1;
    }
    int elements = number_of_elements(n);
    int binaryArray[elements];
    int num = 0;
    do{
        binaryArray[num] = n %2;
        num++;
        n/=2;
    }while(n != 0);
    if (isNegative){
        printf("-");
    }
    for(int i=0;i<elements;i++){
        printf("%d",binaryArray[elements-i-1]);
    }
}
