#include "util_sequences.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int uniform_Samples (float x[], float min, float max, float step)
{
    int n;

    n = (max - min) / step + 1;

    for (int i=0;i<n;i++)
    {
        x[i]=min + i * step;
    }
    return(n);
}



int interpolate(int n, float x[], float y[])
{
    int m;

    m= 2 * n-2;

    for(int i=0; i < m; i++)
    {
        if (i % 2==0) y[i] = x[i/2];
        else y[i]=0.5 * (x[(i-1)/2] + 0.5 * x[(i+1)/2]);
    }

return(m);
}


float linespace(float x[], int n, float min, float max)
{
    float step;
    step = (max - min) / (n - 1);
    for (int i = 0; i<n; i++)
    {
        x[i]=min + i * step;

    }
    return step;
}


