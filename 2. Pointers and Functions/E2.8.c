/*

Pointers to Strings

Assignment: Simulate the standart functions

strlen();
strcat(); //strcat is dangerous, it can overwrite memory if
it uses more than the string allocated.
strchr();

*/

#include <stdio.h>
#include <string.h>

int my_strlen(char *);
char *my_strcat(char *, char*);
char *my_strchr(char *s, int c);

int main()
{
    //strlen test
    char test[5] = {'a','c','d','\0'}; 
    printf("%d\n",strlen(test));
    printf("%d\n",my_strlen(test));
    
    //strcat test
    char msg1[5] = "ab";
    char msg2[] = "cd";
    //strcat(msg1,msg2);
    my_strcat(msg1,msg2);
    printf("%s %s\n",msg1,msg2);    

    //strchr test.
    char msg3[] = "abcdefghijklmnopqrstuv";
    char *p = my_strchr(msg3,'8');
    printf("%c",*p);
    return 0;
}

int my_strlen(char *string)
{
    int size = 0;
    char *p = string;
    while(*p)
    {
        size++;
        p++;
    }
    return size;
}

char *my_strcat(char *string1, char *string2)
{
    int size1 = my_strlen(string1);
    int size2 = my_strlen(string2);

    char *p = string1;

    p += size1;

    for(int i=0;i<size2;i++)
    {
        *(p++) = string2[i];
    }
    *p = '\0';

    return string1;
}

char *my_strchr(char *s, int c)
{
    char *p = s;
    while(*p)
    {
        if(*p == c){
            return p;
        }
        p++;
    }
    return NULL;
}