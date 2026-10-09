/*

Pointers and Arrays

Assignment: Study how pointers behave with arrays

Using ptr + n, ptr++ and ++ptr

*/

#include <stdio.h>

int main()
{

    int list[] = {1,2,82,10,30};
    int *ptr = NULL;
    int *ptr1, *ptr2;

    ptr = ptr1 = ptr2 = &list[0];

    for(int i = 0; i < 5; i++)
    {
        printf("list[%d] = %d\n",i,list[i]);
        printf("ptr + %d = %d\n",i,*(ptr+i));
        printf("ptr++ (%d time) = %d\n",i+1,*ptr1++);
        printf("++ptr (%d time) = %d\n",i+1,*(++ptr2));
    }


    return 0;
}