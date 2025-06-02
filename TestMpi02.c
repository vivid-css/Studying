#include<stdio.h>
#include"mpi.h"

int main(int argc,char *argv[])
{
    int rank,size;
    int flag,rval,i;
    int buffer_1,recv_1;
    int buffer_2,recv_2;
    MPI_Status status,status1,status2,status3,status4;
    int src = 0;
    int dest = 1;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);//获取进程号
    MPI_Comm_size(MPI_COMM_WORLD,&size);//获取总进程数
    if(size != 2)
    {
        printf("***This program uses exactly 2 processes!not %d***\n",size);
        MPI_Abort(MPI_COMM_WORLD,1);//不是两个进程则推出
    }
    if(rank == src)//发送进程
    {
        buffer_1 = 200;
        buffer_2 = 20000;
        printf("standard ,MPI_send\n");
        MPI_Send(&buffer_1,1,MPI_INT,dest,1,MPI_COMM_WORLD);//发送信息(tag1)
        MPI_Send(&buffer_2,1,MPI_INT,dest,2,MPI_COMM_WORLD);
        printf("MPI_Send %d data,tag = 1\n",buffer_1);
        printf("MPI_Send %d data,tag = 2\n",buffer_2);

    }
    else if(rank == dest)//接收进程
    {
        MPI_Recv(&recv_1,1,MPI_INT,src,1,MPI_COMM_WORLD,&status3);//接收信息（tag1）
        MPI_Recv(&recv_2,1,MPI_INT,src,2,MPI_COMM_WORLD,&status4);
        printf("MPI_Recv = %d,tag = 1\n",recv_1);
        printf("MPI_Recv = %d,tag = 2\n",recv_2);
    }
    MPI_Finalize();

}