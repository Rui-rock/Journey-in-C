/*

Pointers to Strings

Assignment: Use E2.6 to simulate strcpy

*/

#include <stdio.h>

char *my_strcpy(char *destination, char *source) //String copy version 0
{
    char *p = destination;
    while (*source != '\0')
    {
        *p++ = *source++;
    }
    *p = '\0';
    return destination;
}   

char *my_strcpy1(char dest[], char source[]) //String copy version 1
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int main(void)
{
    char strA[10] = "Hello";
    char strB[10];
    char strC[10];
    
    my_strcpy(strB, strA);
    puts(strB);

    my_strcpy(strC, strA);
    puts(strC);
}  