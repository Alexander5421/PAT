#include <stdio.h>

struct test
{
    int a;
};

int main()
{
    int K = 7;
    int p,q;

     for (p = 0; p < K; p++){ // loop over KxK filter
            for (q = 0; q < K; q++){

                printf("+ x4d(n, c, h + %d, w + %d) * k4d(m, c, %d, %d)\n", p, q, p, q);
            }
        }
    
    return 0;
}