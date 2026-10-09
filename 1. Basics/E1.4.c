/*

Assignment: Discover integer overflow and float exceptions

Increase integer to discover overflow
Use unsigned and signed integers
Use float to discover NAN and INF

int                 → %d
unsigned int        → %u
long                → %ld
unsigned long       → %lu
long long           → %lld
unsigned long long  → %llu

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

void int_overflow();
void sig_int_overflow();
void float_inf();
void float_nan();

int main(){
    int_overflow();
    sig_int_overflow();
    float_inf();
    float_nan();
    return 0;
}

void int_overflow(){
    printf("Int max: n = %d\n",__INT_MAX__);
    int n = __INT_MAX__;
    printf("Overflow: n + 1 = %d\n",n+1);
    return;
}

void sig_int_overflow(){
    unsigned int n = UINT_MAX;
    printf("Unsigned int max: n = %u\n",n);
    n++;
    printf("Overflow: n + 1 = %u\n",n);
    return;
}

void float_inf(){
    float x = __FLT_MAX__;
    printf("Float max: x = %f\n",x);
    x *= 2;
    printf("Overflow: 2x = %f\n",x);
    printf("isinf(x): %d\n",isinf(x));
    float y = __FLT_MIN__;
    printf("Float min: y = %.20f (1.17e-38)\n",y);
    return;
}

void float_nan(){
    float x;
    x = 0.0/0.0;
    printf("0/0 = %f\n",x);
}