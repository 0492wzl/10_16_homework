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
    void OPT(int);
    
    void main()
    {
        int s, i;
        srand(time(NULL));
        
        s=(int)319*rand()/32767+1; // 前面两位是页号，后面是偏移地址
        
        for (i=0; i<total_instruction; i+=4)
        {
            if (s<0||s>319)
            {
                printf("When i==%d, Error, s==%d\n",i,s);
                exit(0);
            }
            a[i] = s;
            a[i+1] = a[i]+1;
            a[i+2] = (int)a[i]*rand()/32767;
            a[i+3] = a[i+2]+1;
            s=(int)(318-a[i+2])*rand()/32767/2+a[i+2]+2;
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
            OPT(i);
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
void OPT(int total_pf)
    {
        int i, j, max, maxpage, d, dist[total_vp];
        pfc_type *t;
        initialize(total_pf);
        for (i=0; i<total_instruction; i++)
        {if (pl[page[i]].pfn==INVALID)
            {
                diseffect++;
                if (freepf_head==NULL)
                {
                    for (j=0; j<total_vp;j++)
                    {
                        if (pl[j].pfn!=INVALID)
                        {
                            dist[j]=32767;
                        }else
                            dist[j]=0;
                    }
                    d=1;
                    for (j=i+1; j<total_instruction;j++)
                    {
                        if (pl[page[j]].pfn!=INVALID)
                        {
                            dist[page[j]]=d;
                        }
                        d++;
                    }
                
                    max=-1;
                    for(j=0;j<total_vp;j++)
                    {
                        if (max<dist[j])
                        {
                            max=dist[j];
           }
                    freepf_head = &pfc[pl[maxpage].pfn];
                    freepf_head->next = NULL;
                    pl[maxpage].pfn = INVALID;
                }
                pl[page[i]].pfn = freepf_head->pfn;
                freepf_head = freepf_head->next;
            }
        }
        printf("OPT:%6.4f", 1-(float)diseffect/320);
	}
}