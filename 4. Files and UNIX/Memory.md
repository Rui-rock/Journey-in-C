MEMORY
------

<span style='color: blue;'> __M1.__ </span> The variables declared in __stack__ are automatic variables. They're allocated and deallocated when they come into scope and leave scope, without user interaction. But with memory that can vary size and be persistent, it is located in __heap__ and has user management of memory. <br>

_If you manually allocated it, you have to manually free it when you’re done with it._

<span style='color: blue;'> __Interlude.__ </span> Who manages the memory is the Operating System. It creates the virtual memory layer to abstract its physical memory management. Every time a memory is allocated (stack or heap), a group of pages are populated with the data. <br>
After the program ends, all its memory is reclaimed by the OS, so even when you do not free the memory, it still gets the memory back. But when its a long-execution program, memory leak can diminish the memory available and cause performance problems till crash.

<span style='color: blue;'> __M2.__ </span> The __malloc()__ accepts a number of bytes to allocate and returns a void pointer to that block of allocated memory. <br>
To know the number of bytes, you can use __sizeof()__. After done, we can call __free()__ to return that memory to OS.

```
int *p = malloc(sizeof(int));
*p = 12;

printf("%d\n",*p);

free(p);
```

Remarks:

1. You can only use memory allocated by malloc. Never use a random memory value that wasn't handled by you - it could alter important data or crash the program.

2. The OS handles the memory allocation, so you do not choose the memory location for the malloc return.

3. You can not use the memory after its freed, or it causes Undefined Behavior (alter data, crash, etc.)

<span style='color: blue;'> __M3.__ </span> Sometimes, for any particular reason, the OS can't allocate the memory, and returns a `NULL`. Linux never does that, but it's important to consider protection in mind.

```
int *x;

x = malloc(sizeof(int) * 10);

assert(x!=NULL);
```

<span style='color: blue;'> __M4.__ </span> Every memory not initialized is full of garbage. Remember to clear it with __memset__ or __calloc__.

<span style='color: blue;'> __M5.__ </span> An array is a collection of variables of the same data type. When a malloc is called with more than one size of its data type, it creates space for an array.

```
int *x = malloc(sizeof(int) * 10);
assert(x!=NULL);

for(int i=0; i < 10; i++)
{
    x[i] = i * 5;
}

free(x);
```

<span style='color: blue;'> __M6.__ </span> With __calloc()__, you pass the size of one element, and then the number of those elements. It sets all of them to zero.

```
//Array of int with 10 elements with calloc
int *p = calloc(10, sizeof(int));

//Array of int with 10 elements with malloc
int *q = malloc(10 * sizeof(int));
memset(q, 0, 10*sizeof(int)); //set to 0
```
Can be freed with __free()__.

<span style='color: blue;'> __M7.__ </span> With __realloc()__, you can resize the original memory to a new size, shrinking or expanding it.
You need to specify the size in the same way as malloc.
```
float *f = malloc(10*sizeof(float));

float *new_f = realloc(f,20*sizeof *f);
//Could be done with sizeof(float)

assert(new_f != NULL);
f = new_f;
```
Also, it is equivalent to NULL when
```
char *p = malloc(3490); //Allocates 3490 chars, as 1 char = 1B of memory
char *p = realloc(NULL,3490);
```

<span style='color: yellow;'> __Warning.__ </span> The following memory mishandles may be supervised to not happen:

- Forget to allocate memory: When a pointer does not point anywhere, you get a segmentation fault
- Not allocating enough memory: Gives buffer overflow, which is a security vulnerability (buffer overflow attack)
- Forget to initialize allocated memory: Memory uninitialized that can have anything
- Forget to free memory: Gives memory leak, which can make the machine run out of memory and crash
P.S. OS takes back ALL the memory after a process exit/die, so free() is not mandatory, despite being a REALLY good practice, for short-lived programs
- Free memory before you are done with it: OR using it again after freeing is a mistake called dangling pointer. Its use can crash the program, overwrite valid memory
- Double freeing: The result is undefined, making a weird decision or crashing
- Calling free() incorrectly: Passing some value other than malloc() pointer calls is dangerous, such bad things can happen. 

### Aditional Information

<span style='color: cyan;'> __A1.__ </span> The allocation of memory can be done with the __sbrk(2)__ system call. It expands or contracts the heap of the process. Despite it doing that, most versions of malloc and free never decrease their size. The freed memory can go back to malloc pool.

<span style='color: cyan;'> __A2.__ </span> The tools Purify and Valgrind can be used to inspect and locate memory abuse. 

<span style='color: cyan;'> __A3.__ </span> Different types of allocating implementations are:

- libmalloc: a library of different  interfaces.
- vmalloc: uses different tecniques for different regions of memory.
- jemalloc: scales well with multithreaded in multiprocessor systems. 
- TCMalloc: designed to provide high performance, scalability and memory efficiency. 
- alloca: allocates memory in stack and don't need the free call. The problem is that some systems do not support it.