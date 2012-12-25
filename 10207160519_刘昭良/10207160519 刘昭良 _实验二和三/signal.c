#include <unistd.h>
    #include <stdio.h>
    #include <signal.h>
    
    void waiting(), stop();
    int wait_mark;
    
    main()
    {
        int p1, p2;
        while((p1=fork())==-1);         /*创建进程p1*/
        if (p1>0)
        {
            while((p2=fork())==-1); 
            if (p2>0)
            {
                printf("parent\n");
                wait_mark=1;
                signal(SIGINT, stop);   /* 接收'Del'信号并转stop *、
                waiting();
                kill(p1, 16);           /* 向p1发中断信号16 */
                kill(p2, 17);           /* 向p2发中断信号17 */
                wait(0);                /* 同步 */
                wait(0);
                printf("parent process is killed!\n");
               
            }
            else
            {
                printf("p2\n");
               wait_mark=1;
                signal(17, stop);
                waiting();
                lockf((int)stdout, 1, 0);
                printf(" child process 2 is killed by parent! \n");
                lockf((int)stdout, 0, 0);
               
            }
        }
        else
        {
            printf("p1\n");
            wait_mark=1;
            signal(16, stop);
            waiting();
            lockf((int)stdout, 1, 0);
            printf(" child process 1 is killed by parent! \n");
            lockf((int)stdout, 0, 0);
            
        }
    }
    
    void waiting()
    {
        while(wait_mark!=0);
}
   void stop()
    {
        wait_mark=0;
    }
