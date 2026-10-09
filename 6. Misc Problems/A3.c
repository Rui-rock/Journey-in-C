/*

Familia real (real.c)
OBI 2015 - N2 F1

*/

#include <stdio.h>
#include <string.h>

#define max(A,B) ((A)>(B) ? (A) : (B))

void fill(int[],int,int);

void print_all(int[],int);

int main() {

    //Generations form a tree
    int N, M;
    scanf("%d %d",&N,&M); //MALDITO SCANF
    N++; 
    //Includes the king (idx = 0)
    //All indexes are normal (not idx-1)

    //descendent[idx] = parent of idx
    //attend[idx] = 1 if present; 0 otherwise
    //generation[idx] = generation number
    int descendent[N], attend[N], generation[N];
    fill(attend,N,0);
    descendent[0] = 0; 
    attend[0] = 1;
    generation[0] = 0;

    //Scan descents numbers
    int idx;
    for(idx = 1; idx < N; idx++)
    {
        scanf("%d",&descendent[idx]);
    }

    //Scan who attended the party
    int who;
    for(idx = 0; idx < M; idx++)
    {
        scanf("%d",&who);
        attend[who] = 1;
    }

    int parent, gen, max_gen;
    max_gen = 0;
    for(idx = 1; idx < N; idx++)
    {
        parent = idx;
        gen = 0;
        while(parent != 0)
        {
            parent = descendent[parent];
            gen++;
        }
        generation[idx] = gen;
        max_gen = max(max_gen,gen);
    }

    int gen_size[max_gen], present[max_gen];
    fill(gen_size,max_gen,0);
    fill(present,max_gen,0);

    for(idx=1;idx<N;idx++)
    {
        gen_size[(generation[idx]-1)]++;
        if(attend[idx])
        {
            present[(generation[idx]-1)]++;
        }
    }

    float ratio;
    for(idx=0;idx<max_gen;idx++)
    {
        ratio = ((float) present[idx])/gen_size[idx];
        printf("%.2f ",100*ratio);
    }

    return 0;
}

void fill(int array[],int size,int element)
{
    int i = 0;
    while(i<size)
    {
        array[i] = element;
        i++;
    }
}

/*
void print_all(int array[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",array[i]);
    printf("\n");
    return;
} */