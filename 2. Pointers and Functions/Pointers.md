POINTERS
------

<span style='color: orange;'> __1.__ </span> In the code below, the value of `k` is called *rvalue*, while its address is the *lvalue*. <br> An *object* is a named region of storage, an *lvalue* is an expression referring to an object (K&R).
```    
int k;
k = 2;
```

<span style='color: orange;'> __2.__ </span> The right hand side of a `=` equation makes the left-side a local *lvalue* and the right-side an *rvalue*.
```    
int k, j;
k = 2;
j = k; 
```
<span style='color: orange;'> __3.__ </span> The __pointer__ variable holds the lvalue of an value. Its type indicates the amount of memory it needs to store. If its not initialized, it could be problematic<br> So initialize it, or use NULL. 
```
int *ptr = NULL;
```
<span style='color: orange;'> __4.__ </span> Assigning an address and accessing value: 
```
ptr = &k; //ptr points to address of k

*ptr //dereferences it, giving its value
```
<span style='color: orange;'> __5.__ </span> Having an integer memory array, like `list[]`, can be inspected by a pointer. Suppose we have a code like:
```
int list[10];
int *ptr;
ptr = &list[0];
```
So it is pointing to the first element of `list`. If we add an unit to `ptr`, its memory shifts four bytes, cause its an `int` type. So:
```
ptr++; // *ptr is equal to list[1]
```
We can also write
```
ptr = list; //Equal to &list[0]
```
<span style='color: orange;'> __6.__ </span> The cast `(void *)` makes a pointer a generic pointer. It avoids problems of assigning different types, for exemple, a long integer pointer to a short integer variable.

### Pointers and Strings

<span style='color: orange;'> __S1.__ </span> In C, a string is an character array that ends in <span style='color: yellow;'>'\0'</span> (nul character, that is __not__ NULL). This is the example of how a string structure is:

```
    char my_string[40];

    my_string[0] = 'T';
    my_string[1] = 'e';
    my_string[2] = 'd':
    my_string[3] = '\0';
```
Or you could write like this:
```
char my_string[40] = {'T', 'e', 'd', '\0'};
char my_string[40] = "Ted";
```
In all cases, the compiler sets a block of 40 bytes of memory to hold characters and initialized such that the first 4 are __Ted\0__.

<span style='color: orange;'> __S2.__ </span> In E2.7, there are two forms of a prototype of str_cpy. One uses pointer arguments and the other uses the strings themselves. In both, what is passed is the adress of the first element. Then, it's like __source[i]__ is the same as __*(p+i)__.
```
char *my_strcpy1(char *destination, char *source);
char *my_strcpy2(char dest[], char source[]);
```
When it's written (1) is the same as (2):
```
dest[i] = source[i];         (1)
*(dest + i) = *(source + i); (2)
```
A way to speed up (3) would be to do as (4) would go FALSE:
```
while (*source != '\0') (3)
while (*source)         (4)
```

<span style='color: orange;'> __S3.__ </span> (_When declaring strings in global env_)
Other way to initialize a string could be how it is below. The compiler would count the characters and leave room for nul.

```
char name[] = "Ted";
```
It could also be done by:
```
char *name = "Ted";
```
In the first case, 4B of memory are allocated in stack for the string. But in second, 4B for the string, plus _N_ bytes to store the pointer variable, where _N_ depends on the system.<br>
The array declaration makes __&name[0]__ fixed, in opposite to the pointer __name__, that is variable.

<span style='color: orange;'> __S4.__ </span> In a function, declaring as:

```
void my_function_A(char *ptr)
{
    char a[] = "Msg 1"
} 


void my_function_B(char *ptr)
{
    char *cp = "Msg 2"
}
```
In the _my_function_A_, the content of __a[]__ is the data. But in _my_function_B_, the value of __cp__ is considered data. Both datas are stored in stack, but _"Msg 2"_ can be stored anywhere. 

### Complex declarations

<span style='color: orange;'> __C1.__ </span> Consider the following declarations

```
char foo;
char* foo;
char foo[5];
char* foo[5];
char(* foo)[5];
char* (* foo)[5];
char* foo(char *);
char* (*foo)(char*);
char* (*foo[5])(char*);
char* (*(*foo[5])(char *))[];
```

<span style='color: orange;'> __C2.__ </span> Use the following rules to read them: <br>
1. Parentheses grouping together parts of a declaration.
2. The postfix operators: parentheses () indicating a function, and square brackets [] indicating an array.
3. The prefix operator: the asterisk denoting “pointer to”.

Parentheses that are grouping together multiple parts of a declaration have the highest precedence. Next are the postfix operators () and []. Last is the prefix operator *

<span style='color: orange;'> Ex. </span> 
Take `char* foo[5];`, square brackets are higher than asterisk, so _foo_ is an array of (five) pointers to a char, not a pointer to an array of chars.

<span style='color: orange;'> Ex. </span> 
Or even `char (* foo)[5];`. In the parenthesis, _foo_ is a pointer, going outside, there's an array, so _foo_ is a pointer to an array of five chars.

<span style='color: orange;'> Ex. </span> 
Now take `char* (*foo)(char*);`. 

char\* (\*__foo__)(char\*); // __foo is a__ <br>
char\* (\*foo)(char\*); // foo is a __pointer__ <br>
char\* (\*foo)__(char\*)__; // foo is a pointer __to a function that accepts a pointer to a char__ <br>
char\* (\*foo)(char\*); // foo is a pointer to a function that accepts a pointer to a char __and returns a pointer__ <br>
__char__\* (\*foo)(char\*); // foo is a pointer to a function that accepts a pointer to a char and returns a pointer __to a char__ <br>

<span style='color: orange;'> P.S. </span> See E2.9 for more examples

### Pointers on Structs

### Multi-dimensional Arrays

<span style='color: orange;'> __X1.__ </span> Consider the example
```
char multi[5][10];
```
The hell is this? Read from the right to left, it is an array of 10 chars. But the name _multi[5]_ is itself an array indicating there are 5 elements. Each element is a 10-element array. 
```
    multi[0] = {'0','1','2','3','4','5','6','7','8','9'}
    multi[1] = {'a','b','c','d','e','f','g','h','i','j'}
    multi[2] = {'A','B','C','D','E','F','G','H','I','J'}
    multi[3] = {'9','8','7','6','5','4','3','2','1','0'}
    multi[4] = {'J','I','H','G','F','E','D','C','B','A'}
```
In memory, it looks like 5 arrays were initialized like above. Each element is normally adressable using multi[i][j]. <br> By memory continuity, the block should look like this:
```
0123456789abcdefghijABCDEFGHIJ9876543210JIHGFEDCBA
^
|_____ starting at the address &multi[0][0]
```
This is __NOT__ an array of strings, but an array of characters.

<span style='color: orange;'> __X2.__ </span> In the same example above, the compiler interprets __multi+1__ as the address of 'a' in the 2nd row.<br>
To get to the content of the 2nd element in the 4th row, we add 1 to this address and dereference the result, as in:
```
*(*(multi + 3) + 1)
```
In general:
```
*(*(multi + row) + col)    and
multi[row][col]            yield the same results.
```
### Dynamic Allocation of Memory