/*

Complex Declarations

Assignment 1: Untangle the following complex declarations using pointers

    int i;                  // i is an integer 
    int *i;                 // i is a pointer to an integer
    int **i;                // i is a pointer to a pointer to an integer*
    int *(*i)();            // i is a pointer to a function that returns a pointer 
                            to an integer
    int *(*i[5])();         // i is a (five-element) array of pointers to a function 
                            that returns a pointer to an integer
    char *y[5];             // y is a (five-element) array of pointers to char
    int (*i)[5];            // i is a pointer to a (five-element) array of integers
    int *i();               // i is a function that returns a pointer to an integer
    int (*i)();             // i is a pointer to a function that returns an integer
    int *(*(*i)())[5] 
        (*i)                // i is a pointer
        *(*i)()             // i is a pointer to a function that returns a pointer
        (*(*i)())[5]        // i is a pointer to a function that returns a pointer 
                            to a (five-element) array
        int *(*(*i)())[5]   // i is a pointer to a function that returns a pointer 
                            to a (five-element) array of pointers to integers
    void (*pf) (int);       // pf is a pointer to a function (that accepts an integer)
                            and returns void
    int *(*a[5])(void);     // a is a (five-element) array of pointers to a function
                            (that accepts nothing) that returns a pointer to an integer

Assignment 2: Use some of these structures in a code



*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*Compare)(const void *, const void *);

static int intcmp(const void *left, const void *right)
{
    const int *a = left;
    const int *b = right;

    if (*a < *b)
        return -1;
    if (*a > *b)
        return 1;
    return 0;
}

int main(void)
{
    int v[] = { 30, 4, 11, 4, 19 };
    size_t n = sizeof v / sizeof v[0];
    Compare cmp = intcmp;

    qsort(v, n, sizeof v[0], cmp);

    for (size_t i = 0; i < n; ++i)
        printf("%d%c", v[i], i + 1 == n ? '\n' : ' ');

    return 0;
}