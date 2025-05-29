# include <stdio.h>
#include <omp.h>
int main()
{
    int a = 0;
    int i = 0;
    omp_set_num_threads(4);
    #pragma omp parallel for reduction(+:a)//a变量在reduction中，默认为私有变量
    for(i = 0;i<4;i++)
    {
        a+=i;
        printf("%d %d\n",omp_get_thread_num(),a);
    }
    printf("a=%d",a);
    return 0;
}