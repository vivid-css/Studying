# include<stdio.h>
#include<omp.h>
#include<math.h>
#include<sys/time.h>

# define f(x) (1.0/(1.0+pow(x,2)))

int main()
{
    int thread_number = 20;
    float min = 0.0;
    float max = 1000.0;
    double result = 0.0;
    double interval = 0.0;
    int step = 1e5;
    int i;
    interval = (max-min)/step;
    struct  timeval start,end;
    long totaltime = 0;
    gettimeofday(&start,NULL);

    #pragma omp parallel for reduction(+:result) num_threads(thread_number)
    for(i = 0;i < step;i++){
        result+=(f(min+i*interval)+f(min+(i+1)*interval))*interval/2.0;
    }
    gettimeofday(&end,NULL);
    totaltime = 1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
    printf("Calculated result : %lf\n",result);
    printf("total used time is %ld\n",totaltime);
    return 0;


   
    
}