#include <stdio.h>
#include <omp.h>
int main()
{
    int i = 100;
    float a = 111.1;
    omp_set_num_threads(4);
    #pragma omp parallel private(i,a)
    {
        i = i+1;
        printf("thread_number %d %f",i,a);
    }
    printf("%d\n",i);
    return 0;
}