BASICS
------

### Operations

<span style='color: orange;'> __O1.__ </span> __Bitwise__: Can only be applied to integral operands, such as _char, short, int_ and _long_.

```
&   bitwise AND
|   bitwise OR
^   bitwsie XOR
<<  left shift
>>  right shift
~   unary (one's complement)
```

<span style='color: orange;'> __O2.__ </span> __Logical__: Returns 0 or 1.

```
&&  logicalAND
||  logical OR
!   logical NOT
<<  left shift
>>  right shift
~   unary (one's complement)
```

<span style='color: orange;'> __O3.__ </span> __Relational__: Comparison.

```
<,>,>=,<=,==,!=
```

<span style='color: orange;'> __O4.__ </span> __Conditional__: Used with the ternary operator '?', expr1 is evalued first, if TRUE, expr2 is evalued and is used as output. Otherwise, the output is expr3.

```
expr1 ? expr2 : expr3
```
So, the following codes are equivalent:
```
if (a > b)
    z = a;
else
    z = b;

//Is the same as:

z = (a > b) ? a : b;
```

<span style='color: orange;'> __O5.__ </span> __Comma__: Is evalued from left to write, it is possible to write in a for statement multiple expressions in various parts, for example, two indices in parallel. It enhances multi-step computation in for().

```
for(i=0, j=strlen(s)-1; i<j ; i++,j--)
{
    ...
}
```

### Jumps (Break, Continue and Goto)

<span style='color: orange;'> __J1.__ </span> The keyword __break__ gets a PC out of a loop or conditional, such as _while, for, do_ or _switch_. And __continue__ starts the next iteration immediately.

<span style='color: orange;'> __J2.__ </span> __goto__ and __labels__: Are used to make absolute jumps. May be used to abandon deep ingrained loop/conditional processing. <br> It is, in general, seen as bad practice to complicate code reading and organization.

```
for(...)
    for(...){
        ...
        if(disaster)
            goto error;
    }
...
error:
    clean up mess
```

<span style='color: orange;'> __J3.__ </span> __goto__ is useful to substitute repeated cascates of code at the end of certain statements (FILO free/close/error handling statements). For exemple, in this code:
```
void *filebuf = malloc(...);
if (filebuf == NULL)
{
    close(fd);
    perror("malloc");
    return -1
}

int sfd = socket(...)
if (sfd == -1)
{
    free(filebuf);
    close(fd);
    perror("socket");
    return -1;
}

close(sfd);
free(filebuf);
close(fd);

return 0;
```
Look at how many repeated statements there are, many _free()_ statements are needed, regardless of the conditions. __goto__ is useful to make cascades of conditions depending of the outputs of the functions. Such as:

```
int return_value = 0; //Change if error happens

void *filebuf = malloc(...);
if (filebuf == NULL) 
{
    perror("malloc");
    return_value = -1;
    goto fd_label; 
    
    //In this case, filebuf is not created
    //Therefore, it is needed only to close fd
}

int sfd = socket(...)
if (sfd == -1)
{
    perror("socket");
    return_value = -1;
    goto filebuf_label;

    //In this case, sfd is not created
    //Therefore, it is needed to close fd and free filebuf
}

    //Whenever sfd is created, it needs to be closed afterwards
    //In this flux, sfd and fd are closed and filebuf is freed

    close(sfd);

filebuf_label:
    free(filebuf);

fd_label:
    close(fd);

return return_value;
```

<span style='color: orange;'> __J4.__ </span> Prioritize good intuitive labels for it. Always jump in or out of a scope, not in the middle, because it's confusing and variables will not be properly initialized. Also use it to go out of infinite nested loops and avoid breaks/continues.

<span style='color: orange;'> __J5.__ </span> Avoid using it in extensively large code programs.

### Scope X Global

<span style='color: orange;'> __Q1.__ </span> Variables declared in main or inside a function are accessible inside that function, they're limited to that _scope_. They also disappear when the function ends. Variables behave as _automatic_. <br>
A variable can persist between function calls if they're __static__.

<span style='color: orange;'> __Q2.__ </span> The alternative is to define a __global__ variable, external to all functions. They retain their values even after functions exits. <br> This variable must also be _declared_ in each function when used, with an __extern__ statement.

### Type Qualifies/Storage-Class Specifiers

<span style='color: orange;'> __A1.__ </span> The type <span style='color: #3F80F2;'> __const__ </span> prevents modification through a variable.

```
const int = 10; //Cannot be modified
```

<span style='color: orange;'> __A2.__ </span> The type <span style='color: #3F80F2;'> __volatile__ </span> tells the compiler a variable may change unexpectedly.

```
volatile int = 10; 
```

<span style='color: orange;'> __A3.__ </span> The type <span style='color: #3F80F2;'> __static__ </span> does two things: <br> 1. Keeps values between calls of a function, keeping alive throught program; <br> 2. At global level, it is only acessible within that .c file.

<span style='color: orange;'> __A4.__ </span> The type <span style='color: #3F80F2;'> __extern__ </span> declare the variable exists somewhere else. It allows different source files to share global variables/functions.

<span style='color: orange;'> __A5.__ </span> The type <span style='color: #3F80F2;'> __restrict__ </span> refers to pointers. It tells the compiler that, for some operation, the objects accessed by some pointer are not being used through another.
 ```
void copy(int *restrict a, int *restrict b); 
```
