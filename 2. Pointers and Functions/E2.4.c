/*

EXAMPLE

Assignment: Parse function - separates a string into parts
Dealing w/ pointers and strings

Using strtok_r and pointers to strings
It gives pointers to strings tokenized

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 1024
#define ARG_MAX 1024

int parse(char *_argv[], char *command_line) {
    int i;
    char *saveptr = NULL;

    size_t len = strlen(command_line);
    if (len > 0 && len < CMD_MAX) {
        command_line[len - 1] = '\0';
    }

    _argv[0] = strtok_r(command_line, " ", &saveptr); 
    //Returns token pointers to the words

    for (i = 0; i + 1 < ARG_MAX && _argv[i]; i++) {
        _argv[i + 1] = strtok_r(NULL, " ", &saveptr);
    }

    return i;
}

int main (int argc, char *argv[]) {
    char command_line[CMD_MAX];
    char *_argv[ARG_MAX];
    while (1) {
        int count;

        fprintf(stderr, "$ ");

        strncpy(command_line, "touch Text.txt & ls -a\n", CMD_MAX);

        count = parse(_argv, command_line);

        char *AND = "&";

        for (int i = 0; i < count; i++) {
            printf("%s\n", _argv[i]);
            if(strcmp(AND,_argv[i]) == 0)
            {
                printf("EBA!\n");
            }
        }

        break;
    }
    return 0;
}
