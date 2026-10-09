/*

Cobra coral (cobra.c)
OBI 2015 - N2 F1

BVBPBVBPBVBP - True
BVPBVPBVPBVP - False
*/

#include <stdio.h>

int main() {

    int N[4];
    scanf("%d %d %d %d",&N[0],&N[1],&N[2],&N[3]);

    if((N[0]==N[2])||(N[1]==N[3])){
        printf("V");
    } else {
        printf("F");
    }

    return 0;
}