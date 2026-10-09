/*

Assignment: Visualize address x value stored

Visualize the difference of adress, value pointed and operators

*/

#include <stdio.h>

int main(int argc, char *argv[]){

    int x = 10;
    int *ptr = &x;

    printf("Address of x: %p\n", (void*)&x);
    printf("Value of x: %d\n", x);
    printf("Address stored in ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
    printf("Address of ptr: %p\n", (void*)&ptr);

    return 0;
};

/*

The integer x is stored in a certain memory slot, indexed by &x
The pointer ptr stores the address of x, which is &x
The pointer ptr is also stored in a memory slot, indexed by &ptr

Example:
x       = 42
&x      = address of x
ptr     = address of x
*ptr    = 42

void * is a generic pointer that can hold the address of any type
In printf, %p expects void *, so (void *)&p transforms the address type

Remark: The (type) converts one type into another.

*/