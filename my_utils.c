#include "my_utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//function definition
void rand_array(int n, int x[], int min, int max)
{
    for(int i = 0;i<n;i++)
    {
        x[i]=min+rand()% (max-min+1);
    }
}

void rand_array_float(int n, float x[], float min, float max)
{
    for(int i = 0;i<n;i++)
    {
        float p = (float) rand() / RAND_MAX;
        x[i]=min + (max - min) * p;
    }
}
void print_array(int n, int x[], char label[])
{
    printf("\n %s", label);

    for(int i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }
}

void print_array_float(int n, float x[], char label[])
{
    printf("\n\n%s", label);

    for(int i = 0; i < n; i++)
    {
        printf(" %.2f", x[i]);
    }
    printf("\n");
}
