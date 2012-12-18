  #include <stdio.h>
    main()
    {
        int p1, p2;
        while((p1=fork())==-1);       /* 创建子进程p1 */
        if (p1==0)                  /* 子进程创建成功 */
            putchar('b');
        else
        {
            while((p2=fork())==-1);   /* 创建另一个子进程 */
            if (p2==0)              /* 子进程创建成功 */
                    putchar('c');
            else
                    putchar('a');  /* 父进程执行 */
        }
   } 
