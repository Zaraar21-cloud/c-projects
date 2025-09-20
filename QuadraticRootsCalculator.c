/*
@Zaraar 
Last Modified: 20th September 2025
A C program to find the roots of a quadratic equation.
*/

#include <stdio.h>
#include <math.h>

/*
ROOT TYPES:
REAL AND DISTINCT = 1 
REAL AND EQUAL = 2 
COMPLEX = 3 
*/
float a,b,c;
int RootType;
void setRootType(){
    int rootCheck = b*b - (4 * a*c);
    if (rootCheck > 0 ){
        RootType = 1;
    }else if(rootCheck == 0 ){
        RootType = 2;
    }else{
        RootType = 3;
    }
}

int main() {
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f",&a,&b,&c);
    setRootType();
    switch(RootType){
        case 1:
        {
            float firstRoot,secondRoot;
            firstRoot = (-b+sqrt(b*b-4*a*c))/(2*a);
            secondRoot = (-b-sqrt(b*b-4*a*c))/(2*a);
            printf("Root1 = %.2f\nRoot2 = %.2f",firstRoot,secondRoot);
            break;
        }
        case 2:
        {
            float commonRoot;
            commonRoot = (-b+sqrt(b*b-4*a*c))/(2*a);
            printf("Root1 = Root2 = %.2f",commonRoot);
            break;
        }
        case 3:
        {
            float firstRoot,secondRoot,delta;
            delta = (b*b-4*a*c);
            delta *= -1;
            delta = sqrt(delta);
            printf("Root1 = %.2f + i%.2f\n",(-b/(2*a)),(delta)/(2*a));
            printf("Root2 = %.2f - i%.2f\n",(-b/(2*a)),(delta)/(2*a));
        }
    }
}