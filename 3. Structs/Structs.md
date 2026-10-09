STRUCTURES
------

<span style='color: blue;'> __S1.__ </span> A __struct__ is a collection of data of different types. <br> Data members in a structure are called fields or members. They can be declared in two ways, but none allocate memory for the struct:
```    
struct flightType 
{
    char flightNum[7];  /* max 6 characters */
    int altitude;       /* in meters */
    int longitude;      /* in tenths of degrees */
    int latitude;       /* in tenths of degrees */
    int heading;        /* in tenths of degrees */
    double airSpeed;    /* in km/hr */
};

typedef struct 
{
    char flightNum[7];  /* max 6 characters */
    int altitude;       /* in meters */
    int longitude;      /* in tenths of degrees */
    int latitude;       /* in tenths of degrees */
    int heading;        /* in tenths of degrees */
    double airSpeed;    /* in km/hr */
} flightType;
```

<span style='color: blue;'> __S2.__ </span> __Typedef__ provides a different way to define a datatype by giving it a new name. It makes code more readable, it generally goes into the header file.
```    
Syntax: typedef <type> <name>

typedef int Color;
typedef struct flightType Flight;

Color pixels[500];
Flight plane1, plane2;
```  

<span style='color: blue;'> __S3.__ </span> It is possible to declare an array of structs
```    
Flight planes[100];
```  
To access a member of one the structs in the array:
```    
planes[34].altitude = 10000;
```  

<span style='color: blue;'> __S4.__ </span> Two structs can be copied
```    
struct car a, b;
b = a; // Copy the struct
```  

### Pointers and Structs

<span style='color: blue;'> __P1.__ </span> We can declare a pointer to a struct:
```    
Flight *planePtr;
planePtr = &planes[34];
```  
To access a member of the struct addressed by Ptr. Because the `.` has higher precedence than `*`, the second expression is not the same as the first:
```
(*planePtr).altitude = 10000;
*planePtr.altitude;
```

<span style='color: blue;'> __P2.__ </span> The expression first dereferences the pointer to the struct, then it accesses the value.
```
(*Ptr).value
Ptr->value
```
This second accesses the value, then dereferences it, which makes sense if the value is an address.
```
*(Struct.pointer)
*Struct.pointer
```

### Initializing Nested structures and Arrays

<span style='color: blue;'> __N1.__ </span> The elements of a structure can be initialized like this:
```    
struct foo x = {.a=12, .b=3.14};
```  

<span style='color: blue;'> __N2.__ </span> Nested elements of structs inside structs can be initialized by many dots:
```    
struct cabin_information {
int window_count;
int o2level;
};

struct spaceship {
char *manufacturer;
struct cabin_information ci;
};

int main(){

    struct spaceship s = {
    .manufacturer="General Products",
    .ci.window_count = 8, // <-- NESTED INITIALIZER!
    .ci.o2level = 21
    };

return 0; 
}
```  
What if this was an array?
```
struct passenger {
    char *name;
    int covid_vaccinated; // Boolean
};

#define MAX_PASSENGERS 8

struct spaceship {
    char *manufacturer;
    struct passenger passenger[MAX_PASSENGERS];
};

int main(void)
{

struct spaceship s = 
{
    .manufacturer="General Products",
    .passenger = 
    {
        // Initialize a field at a time
        [0].name = "Gridley, Lewis",
        [0].covid_vaccinated = 0,

        // Or all at once
        [7] = {.name="Brown, Teela", .covid_vaccinated=1}
    }
}

return 0; 
}
```

### Self-referencing structs

It is possible to create a struct with a self-reference to its type. But it needs to use a pointer (all the pointers have the same size, so it doesn't create memory problems of the compiler not knowing the future).

```
struct node {
    int data;
    struct node *next;
};
```

This is good for data structures like graphs.

### Padding

C is allowed to put padding bytes within or after a struct as it sees fit. You can't trust they will be adjacent in memory.

```
#include <stdio.h>
struct foo {
    int a;
    char b;
    int c;
    char d;
};

int main(void)
{
    printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
    printf("%zu\n", sizeof(struct foo));
}
```

They should have the same size, right? Well... the output is:
```
10
16
```

### Fake Object-Oriented Programming!

Since the pointer to the struct also points to its first element, its possible to freely cast a pointer to the struct to a pointer to the first element.

```
struct parent {
    int a, b;
};

struct child {
    struct parent super; // MUST be first
    int c, d;
};
```
So a pointer to the child also points to the parent, as it is the first child's element.

### Union

<span style='color: blue;'> __U1.__ </span> Just like a structure, but the fields overlap in memory, so you can only use one field at time. You re-use the same memory space for different types of data.

```
union foo {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
};
```

<span style='color: blue;'> __U2.__ </span> If you have a union of struct s, and all those
union start at the same place in struct sbegin with a common initial sequence, it’s valid to access members of that sequence from any of the union members.

```
struct a {
    int x;
    float y; // Common initial sequence

    char *p;
};

struct b {
    int x;
    float y; // Common initial sequence

    double *p;
    short z;
};

union foo {
    struct a sa;
    struct b sb;
};
```
Therefore, in this code, `f.sa.x` is the same as `f.sb.x`. The same with `y`. 

<span style='color: blue;'> __U3.__ </span> Its possible to use anonymous unnamed structures in union:

```
union foo {
    struct { //unnamed
        int x, y;
    } a;

    struct { //unnamed
        int z, w;
    } b;
};

union foo f;
f.a.x = 1;
f.a.y = 2;
f.b.z = 3;
f.b.w = 4;
```