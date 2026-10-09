/*

Assignment: Construct a program that shows a histogram of algarisms
in an integer

Problem: Integer size - the total size is too small
Can have at most 9 digits, and some with 10
*/

#include <stdio.h>

void histogram(unsigned int);

int main()
{
    unsigned int number;
    printf("Type the number: ");
    scanf("%u",&number);

    histogram(number);
    return 0;
}

void histogram(unsigned int number)
{
    int frequency[10] = {0}; //Initializes all values equal zero
    int i = 0;
    int rest;
    do { //While structure that executes at least once
        rest = number%10;
        frequency[rest]++;
        number /= 10;
    } while (number != 0);

    for(int k = 0; k < 10; k++){
        printf("%d: ",k);
        for(int s = 0; s < frequency[k]; s++) 
            putchar('o');
        printf("\n");
    }

    return; 
}