#include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    
    void *print_message_function( void *ptr );
    main()
    {
         pthread_t thread1, thread2;
         char *message1 = "Thread 1";
         char *message2 = "Thread 2";
         int  iret1, iret2;
     
        /* 创建两个线程，它们的入口函数为print_message_function，但不同的传入函数 */
     
         iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
         iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
     
         /* 在main函数完成前等待两个线程完成  */
         /* 除非程序出程，那么我们在线程还没有完成时终止进程   */
         
         pthread_join( thread1, NULL);
         pthread_join( thread2, NULL);
    
         printf("Thread 1 returns: %d\n",iret1);
         printf("Thread 2 returns: %d\n",iret2);
         exit(0);
    }

    void *print_message_function( void *ptr )
    {
         char *message;
         message = (char *) ptr;
         printf("%s \n", message);
 }
