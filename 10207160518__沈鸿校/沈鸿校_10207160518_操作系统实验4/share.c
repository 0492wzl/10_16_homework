 #include <sys/types.h>
    #include <sys/msg.h>
    #include <sys/ipc.h>
    #include<stdlib.h>
    #include<stdio.h>
   #include <sys/shm.h>
    #define SHMKEY 75   /* 定义共享区关键词 */
    
    int shmid, i;
    int *addr;
    
    void CLIENT()
    {
        int i;
        shmid=shmget(SHMKEY, 1024, 0777);   /* 获取共享区, 长度1024， 关键词SHMKEY */
       addr=shmat(shmid, 0, 0);    /* 共享区起始地址为addr */
        for (i=9; i>=0; i--)
        {
            while(*addr!=-1);
            printf("(client)sent\n");   /* 打印(client) sent */
            *addr=i;    /* 把i赋予addr */
        }
        exit(0);
    }
    
    void SERVER()
    {
        shmid=shmget(SHMKEY, 1024, 0777|IPC_CREAT); /* 创建共享区 */
        addr=shmat(shmid, 0, 0);    /* 共享区起始地址为addr */
        do
        {
            *addr=-1;
            while(*addr==-1);
            printf("(server)received\n"); /* 服务进程使用共享区 */
        }while(*addr);
        shmctl(shmid, IPC_RMID, 0);
        exit(0);
    }
int  main()
    {
        while((i=fork())==-1);
        if (!i)SERVER();
        while((i=fork())==-1);
        if (!i)CLIENT();
        wait(0);
        wait(0);
    }
