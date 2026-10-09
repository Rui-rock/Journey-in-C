/*

Assignment: Replicate echo bash command using command-line arguments

Executable: echo.exe
Use in WSL: Bash$ echo hello, world
hello, world

*/

#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    for(i = 1;i<argc;i++){
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf("\n");
    return 0;
}

/*

Note that argv[0] is the program name

*/