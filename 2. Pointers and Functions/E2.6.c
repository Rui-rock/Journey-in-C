/*

Pointers and Strings

Assignment: Study how pointers behave with strings

Trying to copy two strings of different sizes

*/

#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80] = "123456789012345678901234567890123456789012345678901234567890";

int main(void)
{

    char *pA;     /* a pointer to type character */
    char *pB;     /* another pointer to type character */
    printf("strA\t    : ");
    puts(strA);   /* show string A */
    pA = strA;    /* point pA at string A */
    printf("pA points to: ");
    puts(pA);     /* show what pA is pointing to */
    pB = strB;    /* point pB at string B */
    while(*pA != '\0')   /* While strA is not ended */
    {
        *pB++ = *pA++;   /* Copying values */
    }
    *pB = '\0';          /* Ends the strB copy, needed to complete the copy */
    printf("puts(strB): ");
    puts(strB);          /* show strB on screen */
    printf("Full strB : ");
    for(int i = 0; i<80; i++) //Prints full string strB
    {
        putchar(strB[i]);
        if(strB[i]=='\0')
        {
            putchar(' ');
        }
    }

    return 0;
}