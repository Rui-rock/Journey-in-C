FUNCTIONS
------

### Scopes

<span style='color: orange;'> __A1.__ </span> The _scope_ of a name is the part of the program within which the name can be used. For _automatic_ variables declared in the beginning of the function, the scope is within the function. Local variables of the same name in different functions are unrelated.

<span style='color: orange;'> __A2.__ </span> The scope of an external variable or function lasts from the point at which it is declared to the end of the file being compiled. In the code below, `m` can be used in `function()`, but neither is visible to `main()`.

```
int main() {...}

int m = 0;
int function() {...}
```

<span style='color: orange;'> __A3.__ </span> If an _external_ variable is to be used before it is defined or comes from another file, the _external_ declaration is mandatory.

```
//Declaration in FILE1
extern int sp;
extern double val[];
...
//Definition in FILE 2 - there must be only one among all files 
int sp;
double val[MAX];
```

### Preprocessing: Header Files and Macros

<span style='color: orange;'> __H1.__ </span> In almost every C code, we see in the top the line

```
#include <stdio.h>
```

This includes the standart I/O functions, like `printf()`. The compiler will not compile a call to a function unless it knows the function, and it's told by the include line.

<span style='color: orange;'> __H2.__ </span> Before compilation, a C file is preprocessed. The preprocessor involves directives that use `#`, those replace the line with the contents of the refered file. <br> That allows you to share declarations of functions so that they can be called in other files. The `.h` files are called __header files__.

<span style='color: orange;'> __H3.__ </span> The `#include <filename>` or `#include "filename"` replaces the lines with the contents of such file. Using other files makes it easier to handle collections of `#defines` and declarations.

<span style='color: orange;'> __H4.__ </span> __Macros__ can be included to make the preprocessor substitute lines defined previously. It is possible to substitute text for numbers, arguments, etc.

```
#define name replacement text
#define max(A,B) ((A)>(B) ? (A) : (B))

```

Some care has to be taken with parenthesis so that evaluation order is preserved in calls.<br>
The __##__ preprocessor operator provides a way to concatenate actual arguments during macro expansion. If a parameter in the replacement text is adjacent to a ##, the parameter is replaced by the actual argument, and the ## and surround blank space are removed.

```
#define paste(front,back) front ## back
//So paste(name,1) creates the token name1.
```

<span style='color: orange;'> __H5.__ </span> It is possible to include conditionals in preprocessing. The `#if` evaluates a constant integer expression (may not include sizeof, casts or enum constantes), subsequent lines are included until `#endif`, `#elif` (else if) or `#else`.

<span style='color: orange;'> __H6.__ </span> Pragma is a preprocessor directive that tells the compiler to handle a specific instruction or option. Can be declared as `_Pragma` or `#Pragma`.<br> An interesting use is to make complex number evaluation not assume the intermediate calculations will overflow or underflow. It turns the `CX_LIMITED_RANGE` on.

```
#include <complex.h>
#include <stdio.h>

#pragma STDC CX_LIMITED_RANGE ON

int main(void) {
    double complex z1 = 1.0 + 2.0 * I;
    double complex z2 = 3.0 + 4.0 * I;

    double complex result = z1 / z2;

    printf("%f + %fi\n", creal(result), cimag(result));
    return 0;
}

```

<span style='color: orange;'> __H7.__ </span> Standard C provides some predefined symbolic constants:

```
_LINE_ The line number of the current source code line (An integer constant)
_FILE_ The presumed name of the source file(a string)
_DATE_ The date source file was compiled (The string of the form ‘MM dd YYYY’ such as Jan 20 2013)  
_TIME_ The time source file was compiled (A string literal of the form   
‘hh:mm:ss’).  
_STDC_ Value 1 if the compiler supports Standard C. 
```

<span style='color: orange;'> __H8.__ </span> The `void assert(int expression)` is a function that verifies erros and writes those to STDERR. If the expression is `FALSE`, assert displays an error message on stderr and aborts program execution.

### Compilation, Assembling, Linking and Program Execution

<span style='color: orange;'> __C1.__ </span> The steps taken for a program to turn into an executable are the following:

```
    1. Preprocessing
    The header files are expanded (#include)
    Macros and inline functions are substituted (#define)

    2. Compilation
    Generation of Assembly Language (.S files)
    Verification of functions using prototypes
    Header files: prototypes declarations

    3. Assembling
    Generates re-locatable object files
    Machine-code instructions (.o files)

    4. Linking
    Generates executable file
    Binds appropriate libraries
        - Static/Dynamic Linking

    5. Loading and Execution
    Evaluates size of code and data segment
    Allocates address space in the User Mode and transfers them into memory
    Load dependent libraries needed by program and links them
    Invokes process manager and register program
```

<span style='color: orange;'> __C2.__ </span> Terms 
1. Object file: Is the file for binary format of machine instructions, not linked with others, nor positioned in memory for execution.
2. Executable: Is binary format of object files that are linked and positioned ready for execution.
3. Library: Archive or package of multiple object files.

<span style='color: orange;'> __C3.__ </span> __Linking__ searches a collection of object files and program libraries to find non local routines used in a program, combines them into a single executable file, and resolves references between routines in different files.

```
//Combining two files

//First, compile 
//The flag -c means compile and assembly, but not link.
gcc -c prog1.c
gcc -c prog2.c

//Output is prog1.o and prog2.o
//Link those using the instruction
gcc -o prog prog1.o prog2.o

//Having the executable file, it can be run
./prog
```

It is also possible to make links with libraries.

```
//Linking with pthreads and reatime (rt) libraries
//Option is "-l<library>"
gcc <options> program_name.c -lpthreads -lrt


//-L<dir> makes the compiler search the directory
//for the library file
```

<span style='color: orange;'> __C4.__ </span> If multiple programs want to use a function, the __static linking__ makes each of them have a full definition of it. If the function changes, each of the files must change. <br> With __dynamic linking__, a dynamic (shared) library is created to provide implementation of the function, in which linking is made at the runtime.

### Pointers and Functions

<span style='color: purple;'> __P1.__ </span> To change a value in stack through a function, it's needed to pass its address to the function. In general, when using __structs__, it's better to use its address, because it's less expensive to copy it than the whole struct.

```
#include <stdio.h>

void change_value(int *p)
{
    *p = 100;
}

int main(void)
{
    int x = 10;

    change_value(&x);

    /*
    int *ptr = &x;
    change_value(p); Is also possible!
    */

    printf("%d\n", x);  // Prints 100
    return 0;
}
```

<span style='color: purple;'> __P2.__ </span> After functions have been declared, its possible to use them as inputs of other functions as pointers to evaluate on time, without checking cases. This is good to customize function behavior by receiving other functions.

```
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}

int calculate(int a, int b, int (*operation)(int, int)){
    return operation(a, b);
}

int result1 = calculate(3, 4, add);
int result2 = calculate(3, 4, multiply);
```
In each of the results, the argument call the functions named, and it is possible by using its address.
```
return_type (*parameter_name)(parameter_types);
```

<span style='color: purple;'> __P3.__ </span> A double asterisk is needed to modify a pointer to something:

```
void redirect(int **pp, int *new_address){
    *pp = new_address;
}

 int x = 10;
 int y = 20;

 int *p = &x;

 redirect(&p, &y); //Redirects the pointer to y
```

<span style='color: purple;'> __P4.__ </span> It is also possible to declare a pointer to a group of functions

```
int (*operations[3])(int, int) = {
    add,
    subtract,
    multiply
};

int result1 = operations[0](10, 5); // add
int result2 = operations[1](10, 5); // subtract
int result3 = operations[2](10, 5); // multiply
```
In this case, operation is an array of pointers to functions. It is also possible to define this operation pointer-to-function as a new type:
```
typedef int (*Operation)(int,int)

Operation operation[3] = {
    add,
    subtract,
    multiply
}
```