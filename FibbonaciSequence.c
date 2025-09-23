/*
@Zaraar
Last updated: 23rd September 2025
A C program to print the first N numbers in the Fibonacci sequence.
*/

#include <stdio.h>

int getNext(int index){
    if (index == 0 || index == 1){
        return 1;
    }else{
        return (getNext(index-1) + getNext(index-2));
    }
}

int main() {
    int N;
    scanf("%d",&N);
    if(N>0){
        printf("0 ");
        for(int i=0;i<N-1;i++){
            printf("%d ",getNext(i));
        }
    }else{
        printf("NUMBER MUST BE A NATURAL NUMBER!");
    }
}