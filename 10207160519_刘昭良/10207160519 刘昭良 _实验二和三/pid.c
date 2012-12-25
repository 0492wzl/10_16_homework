#include <unistd.h>
    #include <stdio.h>
    #include <signal.h>
    
    int pid1, pid2;
    
    main()
    {
        int fd[3],p1,p2;
        char OutPipe[100], InPipe[100];
        pipe(fd);
        while((p1=fork())==-1);     
        if (p1==0)
        {
            printf("p1\n");
            lockf(fd[1],1,0);
            sprintf(OutPipe, "Child 1 process is sending a message!");
            write(fd[1], OutPipe, 50);
            sleep(1);
            lockf(fd[1], 0, 0);
           
        }
        else
        {
            while((p2=fork())==-1);     
            if (p2==0)
            {
                printf("p2\n");
                lockf(fd[1],1,0);
                sprintf(OutPipe, "Child 2 process is sending a message!");
                write(fd[1], OutPipe, 50);
                sleep(1);
                lockf(fd[1], 0, 0);
                
            }
            else
            {
                printf("parent\n");
                wait(0);
                read(fd[0], InPipe, 50);
                printf("%s\n", InPipe);
                wait(0);
                read(fd[0], InPipe, 50);
                printf("%s\n", InPipe);
                
            }
        }
    }
