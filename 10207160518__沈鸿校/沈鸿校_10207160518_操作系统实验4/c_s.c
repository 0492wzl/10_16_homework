    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/msg.h>
    #include <sys/ipc.h>
    #include<stdlib.h>
    #define MSGKEY 75   /*  定义关键词MSGKEY */
    
    struct msgform      /* 消息结构 */
    {
        long mtype;
        char mtrex[1030];   /* 文本长度 */
    }msg;
    
    int msgqid, i;
    
    void CLIENT()
    {
        int i;
        msgqid = msgget(MSGKEY,0777);
        for (i=10; i>=1; i--)
        {
            msg.mtype = i;
            printf("(client)sent\n");
            msgsnd(msgqid, &msg, 1024, 0);  /* 发送消息 msg 入 msgqid消息队例 */
        }
    }
    
    void SERVER()
    {
        msgqid = msgget(MSGKEY, 0777|IPC_CREAT); /* 由关键字获得消息队列 */
        do
        {
            msgrcv(msgqid, &msg, 1030, 0, 0);   /* 从msgqid队列接收消息msg */
            printf("(server)received\n");
        }while(msg.mtype!=1);
     msgctl(msgqid, IPC_RMID, 0);
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
