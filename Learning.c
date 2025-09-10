#include <stdio.h>
// LEARNING POINTERS, STRUCTURES AND STRUCTURES WITH POINTERS

typedef char string[20];

typedef struct{
 string name;
 char currency;
 int price;
 string model;
} Car;

Car car1 = {"CarNameWasTaken",'$',6000,"Honda Civic 2012"};
Car car2 = {"idkthename",'$',7000,"Ford Whatever 2013"};
Car car3 = {"Iknowthename",'$',55000,"Ford Mustang 2011"};

Car *allCars[3] = {&car1,&car2,&car3};
int main(){
    for(int i=0;i<3;i++){
        printf("%d) ",i);
        printf("CAR NAME: %s \nPRICE: %c%d \nMODEL: %s",allCars[i]->name,allCars[i]->currency,allCars[i]->price,allCars[i]->model);
        printf("\n\n");
    }
}