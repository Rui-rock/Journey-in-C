/*

Assignment: Calculate the limit of float and double

Calculate the factorial and power of numbers
Discover which index overflows it

*/

#include <stdio.h>
#include <math.h>

int int_factorial();
float float_factorial();
double double_factorial();
float lgdouble_factorial();
int int_power(int);
int float_power(int);

int main(){
    printf("Integer \tn! limit: %d\n",int_factorial());
    printf("Float \t\tn! limit: %.0f\n",float_factorial());
    printf("Double \t\tn! limit: %.0f\n",double_factorial());
    printf("Long Double \tn! limit: %.0f\n",lgdouble_factorial());
    printf("\n");
    int A = 5;
    printf("Integer n! power %d^n: %d\n",A,int_power(A));
    printf("Float \tn! power %d^n: %d\n",A,float_power(A));


    return 0;
}

int int_factorial(){
    int n = 2;
    int P1 = 2;
    int P2 = 1;
    //(P1*P2>0) gives n = 9, but (fabs(P1)>fabs(P2)) n = 13, why?
    //R: The product overflows faster
    while((fabs(P1)>fabs(P2))) 
    {
        P2 *= n;
        n++;
        P1 *= n;
    }
    return n-1;
}

float float_factorial(){
    float f = 2.0;
    float P = 1.0;
    while(isinf(P)!=1) 
    {
        P *= f;
        f++;
    }
    return f-1;
}

double double_factorial(){
    double f = 2.0;
    double P = 1.0;
    while(isinf(P)!=1) 
    {
        P *= f;
        f++;
    }
    return f-1;
}

float lgdouble_factorial(){
    float f = 2.0;
    long double P = 1.0;
    while(isinf(P)!=1) 
    {
        P *= f;
        f++;
    }
    return f-1;
}

int int_power(int x){
    int n = 1;
    int P1 = x;
    int P2 = 1;
    //(P1*P2>0) gives n = 9, but (fabs(P1)>fabs(P2)) n = 13, why?
    //R: The product overflows faster
    while((fabs(P1)>fabs(P2))) 
    {
        n++;
        P2 *= x;
        P1 *= x;
    }
    return n;
}

int float_power(int x){
    int n = 1;
    float P = (float) x;
    while(isinf(P)!=1) 
    {
        P *= x;
        n++;
    }
    return n-1;
}