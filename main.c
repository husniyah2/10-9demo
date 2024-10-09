#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_utils.h"
#include "util_matrices.h"
#include "util_sequences.h"

float * sample (int *n, float xmin, float xmax, float step);

float * sample (int *n, float xmin, float xmax, float step)
{

}
char * get_rand_dna()





int * alloc_rand_array(int n, int min, int max)
{
    int *x;
    x = (int *) malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
    {
        x[i]= min + rand () % (max - min + 1);
    }
    return(x);
}

void inc(int a) // * indicates a is coming in as an address LINE A
{
    a = a + 1; // Need to use * to lookup contents LINE B
} //LINE C

void inc_byRef(int *a) // * indicates a is coming in as an address  LINE AA
{
    *a = *a + 1; // Need to use * to lookup contents LINE BB
} //LINE CC


int main()
{
    /*in class 10/2
    int x[10];

    int n;

    //Address          COntents        Variable
    //A000 000            -232312(g)       n

    int *ptr;

    //Address          COntents        Variable
    //A000 0000        -232312(g)       n
    //B000 0000        FF00 0000(g)     ptr   (itunes)

    //*ptr = 4444 program crashes
    n=50;
    ptr = &n

    n =50;
    //ptr = &n;
    ptr = (int *) malloc(sizeof(int));

    //Address          COntents        Variable
    //A000 0000        50                 n, *ptr
    //B000 0000        A000 0000          ptr


    //Address          COntents        Variable
    //A000 0000        50                 n
    //B000 0000        A000 0000          ptr
    //C000 0000         35335(g)          *ptr




    printf("Hello World!\n");
    return 0;
    */

    int n;
    int *ptr;
    //2 ways to initialize ptr
    //1. set to existing address
    //ptr = &n;

    //2. malloc
    ptr = (int *) malloc(sizeof(int));
    //Address               Contents                      Variable
    //A000 0000               -3343(g)                       n
    //B000 0000               C000 0000                     ptr
    //C000 0000                 35335(g)                    *ptr
    //Next available :C000 0000


    int *nptr = (int *) malloc(3 * sizeof(int));
    //Address          COntents        Variable
    //A000 0000        -444(g)            n
    //B000 0000        C000 0000          ptr
    //B000 0004        C000 0004          nptr
    //C000 0000         -444(g)           *ptr
    //C000 0004         35333(g)          *(nptr + 0) or  nptr[0]
    //C000 0008         35334(g)          *(nptr+1) or  nptr[1]
    //C000 000C         35335(g)          *(nptr+1) or  nptr[2]

    //pointer arithmetic: nptr + 1 advances in memory to the next integer
    //nptr + 1 = C000 0004 + 1 =C000 0008


    int x[4] = {10, 20, 30, 40};
    //Address          COntents        Variable
    //A000 0000        -444(g)            n
    //B000 0000        C000 0000          ptr
    //B000 0004        C000 0004          nptr
    //C000 0000         -444(g)           *ptr
    //C000 0004         35333(g)          *(nptr + 0) or  nptr[0]
    //C000 0008         35334(g)          *(nptr+1) or  nptr[1]
    //C000 000C         35335(g)          *(nptr+1) or  nptr[2]
    //D000 0000        10                 x[0]
    //D000 0004        20                 x[1]
    //D000 0008        30                 x[2]
    //d000 000C        40                 x[3]

    //x[3] is shorthand for *(x +3)
    // *
    //

    int *sptr = NULL;
    //Address          COntents        Variable
    //A000 0000        -444(g)            n
    //B000 0000        C000 0000          ptr
    //B000 0004        C000 0004          nptr
    //B000 0008        0000 0000           p // bad bc we dont own 0000 0000 address
    //C000 0000         -444(g)           *ptr
    //C000 0004         35333(g)          *(nptr + 0) or  nptr[0]
    //C000 0008         35334(g)          *(nptr+1) or  nptr[1]
    //C000 000C         35335(g)          *(nptr+1) or  nptr[2]
    //D000 0000        10                 x[0]
    //D000 0004        20                 x[1]
    //D000 0008        30                 x[2]
    //d000 000C        40                 x[3]


    //not pointing to itunes but cant use * on NULL
    //*p currently crashes


    int q = 50;
    inc(q); //pass by value

    //AFTER LINE A

    //Address          COntents        Variable
    //A000 0000           50                q

     //AFTER LINE B

    //Address          COntents        Variable
    //A000 0000           50                q
    //E000 0000           51                a

    //AFTER LINE C

    //Address          COntents        Variable
    //A000 0000           50                q

    //pass by ref


    inc_byRef(&q); //address of q

    //AFTER LINE AA

    //Address          COntents        Variable
    //A000 0000           50                q, *a
    //E000 0000           A000 0000         a

    //AFTER LINE BB

    //Address          COntents        Variable
    //A000 0000           51               q, *a
    //E000 0000           A000 0000         a

    //AFTER LINE CC

    //Address          COntents        Variable
    //A000 0000           51               q

    int *r; //itunes, have to properly intialize first
    //Address          COntents              Variable
    //B000 000C          FF00 2323               r

    //inc_byRef(r) will crash

    r = (int *) malloc(sizeof(int));

    inc_byRef(r); //work

    int grades[20];
    rand_array(20, grades, 70, 100);


    int *scores;
    scores = alloc_rand_array(20, 70, 100);
    //exercise do a memory table


    //10-9 class

    int *a;
    a = (int *) malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
    {
        a[i]= 10 * (i + 1);
    }

    // Address                  COntents                    Variables
    //B000 0000               C000 0000                          a
    //C000 0000                     10                          a[0], *(a+0)
    //C000 0004                     20                          a[1], *(a+1)
    //C000 0008                     30                          a[2], *(a+2)



    a = (int *) malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
    {
        a[i]= 10 * (i + 4);
    }

    // Address                  COntents                    Variables
    //B000 0000               C000 000C                         a
    //C000 0000                     10                          // a has been updated MEMORY LEAK!!
    //C000 0004                     20
    //C000 0008                     30
    //C000 000C                     100                         a[0], *(a+0)
    //C000 0010                     200                         a[1], *(a+0)
    //C000 0014                     400                         a[2], *(a+0)
    //C000 0018                     400                         a[3], *(a+0)

    //solution use free(a);

    free(a);
    // Address                  COntents                    Variables
    //B000 0000               C000 000C                         a




    // Address                  COntents                    Variables
    //B000 0000               C000 000C                         a
    //C000 0000                     100                          a[0], *(a+0)
    //C000 0004                     200                          a[1], *(a+0)
    //C000 0008                     300                          a[2], *(a+0)
    //C000 000C                     100                         a[3], *(a+0)

    print_array(4,a,"A");
    printf("\n\n Address         COntents           Variable");

    for (int i=0;i<4;i++)
    {
        printf("\n%p           %-4d    a[%-2d]", &a[i], a[i],i);
    }


    unsigned char *cptr;
    cptr = (unsigned char *) a;

    printf("\n unabbreviated");
    printf("\n\n Address         COntents           Variable");
    for (int i=0;i<4*4;i++)
    {
        printf("\n%p           %-4d     ", cptr + 1, (int) * (cptr +i));
        if (i % 4 ==0) printf("a[%-2d]", i/4);
    }















}








