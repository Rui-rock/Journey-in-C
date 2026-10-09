/*

Quebra cabeca (quebra.c)
OBI 2015 - N2 F1

*/

#include <stdio.h>

int* search(int *,int[],int); 

int main() {

    int size;
    scanf("%d",&size);

    int piece[size][2];
    char letter[size]; 
    for(int i=0;i<size;i++) {
        scanf("%d %c %d",&piece[i][0],&letter[i],&piece[i][1]);
    }

    int bind[size];
    search(piece[0],bind,size);

    int k = 0;
    while(k<size)
    {
        printf("%c",letter[bind[k]]);
        k++;
    }

    return 0;
}

int* search(int *array,int bind[],int size) 
{
    int *p = array;

    int k = 0;
    int s = 1;

    //Search for zero
    while(*p!=0)
    {
        k++;
        p += 2;
    }
    bind[0] = k;
    int right_number = *(p+1);

    while(right_number!=1)
    {
        k = 0;
        p = array;
        while(*p != right_number) 
        {
            p += 2;
            k++;
        }
        right_number = *(p+1);
        bind[s] = k;
        s++;
    }

    return bind;
}