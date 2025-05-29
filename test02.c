# include <stdio.h>
#include <omp.h>

int main()
{
    int a = 0;
    int i = 0;
    omp_set_num_threads(2);
    #pragma omp parallel for private(i) lastprivate(a)
    for(i = 0;i<20;i++)//OpenMP默认使用静态调度，将迭代次数平均分配给各线程
    {
        a=i+omp_get_thread_num();
        printf("%d  %d\n",omp_get_thread_num(),a);
    }
printf("a=%d",a);
return 0;
}