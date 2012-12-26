    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
    #define TRUE 1
    #define FALSE 0
    #define INVALID -1
    #define NULL 0
    
    #define total_instruction 320
    #define total_vp 32
    #define clear_period 50
    
    typedef struct  
    {
        int pn, pfn, counter, time;
    }pl_type;
    
    pl_type pl[32];
    
    typedef struct pfc_struct
    {
        int pn, pfn;
        struct pfc_struct *next;
    }pfc_type;
    
    pfc_type pfc[32], *freepf_head, *busypf_head, *busypf_tail;
    
    int diseffect, a[total_instruction];
    int page[total_instruction], offset[total_instruction];
 void initialize(int);
    void FIFO(int);
    
    void main()
    {
        int s, i, j;
        srand(time(NULL));
        
        s=(float)319*rand()/32767+1; // 前面两位是页号，后面是偏移地址
        
        for (i=0; i<total_instruction; i+=4)
        {
            if (s<0||s>319)
            {
                printf("When i==%d, Error, s==%d\n",i,s);
                exit(0);
            }
            a[i] = s;
            a[i+1] = a[i]+1;
            a[i+2] = (float)a[i]*rand()/32767;
            a[i+3] = a[i+2]+1;
            s=(float)(318-a[i+2])*rand()/32767/2+a[i+2]+2;
            if ((a[i+2]>318)||(s>319))
                printf("a[%d+2], a number which is: %d and s==%d\n",
                     i, a[i+2], s);
        }
 for (i=0; i<total_instruction; i++)
        {
            page[i] = a[i]/10;
            offset[i] = a[i]%10;
        }
        for (i=4; i<=32; i++)
        {
            printf("%2d page frames", i);
            FIFO(i); 
         
            printf("\n");
        }
    }
    
    void initialize(int total_pf) // 通过total_pf控制页框大小
    {
        int i;
        diseffect=0;
    
        for (i=0; i<total_vp; i++) // 初始虚拟页面
        {
            pl[i].pn=i;
            pl[i].pfn=INVALID;
            pl[i].counter=0;
            pl[i].time=-1;
        }
       for(i=0; i<total_pf-1; i++) // 初始页表
        {
            pfc[i].next=&pfc[i+1];
            pfc[i].pfn=i;
        }
        pfc[total_pf-1].next = NULL;
        pfc[total_pf-1].pfn = total_pf-1;
        freepf_head = &pfc[0];  //空闲页面指针
    }
    
    void FIFO(int total_pf)
    {
        int i,j;
        pfc_type *p;
        initialize(total_pf);
        busypf_head = busypf_tail = NULL;
        for (i=0; i<total_instruction; i++)
        {
            if (pl[page[i]].pfn==INVALID)
            {
                diseffect+=1;
                if (freepf_head==NULL) // 页面置换
                {
                    p=busypf_head->next;
                    pl[busypf_head->pn].pfn=INVALID; // 清空页框
                    freepf_head = busypf_head;
                    freepf_head->next = NULL;
                    busypf_head = p; //指向下一页
                }
                p=freepf_head->next;
 freepf_head->next = NULL;
                freepf_head->pn = page[i]; //填页号
                pl[page[i]].pfn = freepf_head->pfn;
    
                // 尾插入
                if (busypf_tail==NULL)  // 第一次
                    busypf_head = busypf_tail = freepf_head;
                else{
                    busypf_tail->next = freepf_head;
                    busypf_tail = freepf_head;
                }
                freepf_head = p;
            }
        }
        printf("FIFO:%6.4f", 1-(float)diseffect/320);
    }

