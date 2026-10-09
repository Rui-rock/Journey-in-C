/*

Example: Replicate cat using <stdio.h>
Subject: File Access
From K&R

*/

#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    void filecopy(FILE *, FILE *);

    if(argc==1)
        filecopy(stdin, stdout);
    else
        while(--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) { //Uses open()
                printf("cat: can't open %s\n", *argv); //Uses sprintf
                return 1;
            } else {
                filecopy(fp,stdout); // Uses write()
                fclose(fp); //Uses close()
            }

    return 0;        
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}