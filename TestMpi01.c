#include<stdio.h>
#include<string.h>
#include "mpi.h"

int main(int argc,char* argv[])
{
    int numprocs,myid,source;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    printf("通信域WORLD中共%d个进程，这是第%d个进程\n",numprocs,myid);
    MPI_Finalize();
}