#include <stdio.h>
    main()
    {
        int p1, p2;
        while((p1=fork())==-1);       /* 创建子进程p1 */
        if (p1==0)                  /* 子进程创建成功 */
          { printf("子进程b输出：");
	    putchar('b');
	    putchar('\n');}
        else
        {
            while((p2=fork())==-1);   /* 创建另一个子进程 */
            if (p2==0)              /* 子进程创建成功 */
                   {printf("子进程c输出：");
 putchar('c');putchar('\n');}
            else {printf("父进程a输出：");
 putchar('a');putchar('\n');}   /* 父进程执行 */
        }
    }
