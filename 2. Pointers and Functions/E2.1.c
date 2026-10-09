/*

Assignment: Increment values using functions and pointers

Use a function to increment an value. As its variables are in stock
pointers are needed

*/

#include <stdio.h>

void increment(int *value) 
{
    *value += 1;
}

int main(int argc, char *argv[]){

    int x = 0;
    printf("Initial value of x: %d\n", x);
    increment(&x);
    printf("Value of x after increment: %d\n", x);

    return 0;
};