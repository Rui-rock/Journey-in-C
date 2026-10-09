/*

Assignment: Replicate BASH 

*/

#define _POSIX_C_SOURCE 1
#include <linux/limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define CMD_MAX 1024
#define ERR_BUFFER 128

int parse(char *_argv[], char *command_line);
void shell(char *_argv[], int INIT, int FIN);

int main (int argc, char *argv[]) {

    char command_line[CMD_MAX];
    char *_argv[ARG_MAX];

    while (1) {
        int count;

        //Command-line capture and separation
        fprintf(stderr, "$ ");
        fgets(command_line, CMD_MAX, stdin);
        count = parse(_argv, command_line);
        
        //Separating inputs of shell by &'s
        //Iterates by arguments, waits till the next
        int INIT = 0;
        int FIN = 0;
        char *AND = "&";
        for (int i = 0; i < count; i++) {
            if(strcmp(AND,_argv[i]) == 0)
            {
                FIN = i;
                shell(_argv,INIT,FIN); //Executes fork/execve+wait
                INIT = i+1;
            }
        }
        shell(_argv,INIT,count);   

        //break;
    }
    
    //fprintf(stderr, "Finished\n");
    _exit(EXIT_SUCCESS);
}

void shell(char *_argv[], int INIT, int FIN) {

    //Buffers for error handling
    char buf[ERR_BUFFER];
    char *bufp = buf;

    //Creating the argument char pointer
    int size = FIN-INIT+1;
    char *list[size]; 
    for(int i=0;i<size-1;i++)
    {
        list[i] = _argv[INIT + i];
    }
    list[size-1] = NULL;

    //Process fork+exec+wait
    int PID;
    PID = fork();

    //Fork error Handling
    if(PID==-1)
    {
        sprintf(buf,"%s",_argv[0]);
        perror(bufp);
        _exit(EXIT_FAILURE);
    }

    if(PID == 0) //Child Process 
    {
        execve(_argv[INIT],list,NULL); //Transforms process
        
        sprintf(buf,"%s",_argv[0]); //Execve error handling
        perror(bufp); 
        _exit(EXIT_FAILURE);
    } 
    else //Parent process
        {
            int waiting, wstatus;
            waiting = wait(&wstatus);
            if(waiting == -1) //Waiting error handling
            {
                sprintf(buf,"%s",_argv[0]);
                perror(bufp);
                _exit(EXIT_FAILURE);
            }
        }
    return;
}

int parse(char *_argv[], char *command_line) {
    int i;
    char *saveptr = NULL;

    size_t len = strlen(command_line);
    if (len > 0 && len < CMD_MAX) {
        command_line[len - 1] = '\0';
    }

    /* strtok_r is thread-safe; strtok is not. */
    _argv[0] = strtok_r(command_line, " ", &saveptr);

    /* Careful with those buffer sizes! */
    for (i = 0; i + 1 < ARG_MAX && _argv[i]; i++) {
        _argv[i + 1] = strtok_r(NULL, " ", &saveptr);
    }

    return i;
}