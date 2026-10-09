/*

Example: Replicate GNU Cat using syscalls

You can NOT use <stdio.h> functions
except sprintf() and perror()

*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int char_counter(char *, int);
void line_break();
void if_error(int);

int main (int argc, char* argv[]) {

    int sys_val;

    if(argc == 1) 
    {
        return 0;
    }
    else 
    {
        for(int i = 1; i < argc; i++)
        {
            //Opening file and read/write buffer
            char buf[BUFFER_SIZE];
            char *bufp = buf;
            int fd = open(argv[i], 0);
            if(fd == -1){
                sprintf(buf,"./gcat: %s",argv[i]);
                perror(bufp);
                continue;
            }
            
            //Read/Write loop
            int n;
            while((n = read(fd,buf,BUFFER_SIZE)) > 0)
                {
                    if_error(n);
                    sys_val = write(1,buf,n);
                    if_error(sys_val);
                }
            if_error(n);

            //Jumping line after last read
            line_break();
            sys_val = close(fd);
            if_error(sys_val);
        }  
    } 

    exit(EXIT_SUCCESS);
}

void line_break(){
    char buf[2];
    char line = '\n';
    sprintf(buf,"%c",line);
    write(1,buf,1);
}

void if_error(int sys_val){
    if(sys_val == -1) 
    { 
        line_break();
        perror("");
    }
}

int char_counter(char *c, int size)
{
    int i = 0;
    while(i<size) 
    {
        if(*c == '\0'){
            return i;
        } else {c++;}
        i++;
    }
    return 0;
}
