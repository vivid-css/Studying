#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<omp.h>

int main(int argc,char*argv[]){
    int tn = atoi(argv[1]);
    int i = 0;
    int count = 0;
    double x = 0;
    double y = 0;
    double pi = 0;
    int n = 1e9;
    struct  timeval start,end;
    long totaltime = 0;
    gettimeofday(&start,NULL);
    #pragma omp parallel num_threads(tn)

    {
        unsigned seed = time(NULL);
        #pragma omp for reduction(+:count) private(x,y)
        for(i = 0;i<n;i++){
            x=rand_r(&seed)/(double)(RAND_MAX);
            y=rand_r(&seed)/(double)(RAND_MAX);
            if((x*x)+(y*y)<1){
                count++;
            }
        }
    }
    gettimeofday(&end,NULL);

    pi = 4*(count/(double)(n));
    totaltime = 1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
    printf("pi value is %lf\n",pi);
    printf("total used time is %ld milliseconds\n",totaltime);
    
return 0;
}