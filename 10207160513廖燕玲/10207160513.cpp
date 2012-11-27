// 宝贝.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
using namespace std;
#define MAX 10
struct task_struct
   {
     char name[10];          /*进程名称*/
     int number;             /*进程编号*/
     float come_time;         /*到达时间*/
     float run_begin_time;     /*开始运行时间*/
     float run_time;           /*运行时间*/
     float run_end_time;       /*运行结束时间*/
     int order;               /*运行次序*/
     int run_flag;              /*调度标志*/
   }
tasks[MAX];
int counter;                  /*实际进程个数*/
int fcfs();                   /*先来先服务*/
int hrrn();            		 /*响应比高优先级调度*/
int sjf();           		 /*短作业优先*/
int pinput();          		/*进程参数输入*/
int poutput();        		 /*调度结果输出*/

int _tmain(int argc, _TCHAR* argv[])
{ 
  int option;
  pinput();
  cout<<"请选择调度算法（0~3）:"<<" ";
  cout<<"1.先来先服务"<<" ";
  cout<<"2.响应比高优先调度"<<" ";
  cout<<"3.短作业优先"<<" ";
  cout<<"0.退出"<<endl;
  cin>>option;
  if (option==0)
    {
       cout<<"运行结束。"<<endl;
     }
  if (option==1)
    { 
       cout<<"对进程按先来先服务调度。"<<endl;
       fcfs();
       poutput();
     }
   if (option==2)
    { 
       cout<<"对进程按响应比高优先调度。"<<endl;
       hrrn();
       poutput();
     }
   if (option==3)
    { 
       cout<<"对进程按短作业优先调度。"<<endl;
       sjf();
       poutput();
    }
}
int fcfs()    /*先来先服务*/
{
   float time_temp=0;
   int i;
   int number_schedul;
   time_temp=tasks[0].come_time;
   for(i=0;i<counter;i++)
    {
       tasks[i].run_begin_time=time_temp;
       tasks[i].run_end_time=tasks[i].run_begin_time+tasks[i].run_time;
       tasks[i].run_flag=1;
       time_temp=tasks[i].run_end_time;
       number_schedul=i;
       tasks[number_schedul].order=i+1;
    }
   return 0;
}

int hrrn() /*响应比高优先*/
{ 
   int j,number_schedul,temp_counter;
   float temp_time,respond_rate,max_respond_rate;
   /*第一个进程被调度*/
   tasks[0].run_begin_time=tasks[0].come_time;
   tasks[0].run_end_time=tasks[0].run_begin_time+tasks[0].run_time;
   temp_time=tasks[0].run_end_time;
   tasks[0].run_flag=1;
   tasks[0].order=1;
   temp_counter=1;
   /*调度其他进程*/
  while(temp_counter<counter)
    {
       max_respond_rate=0;
       for(j=1;j<counter;j++)
         {
           if((tasks[j].come_time<=temp_time)&&(!tasks[j].run_flag))
	          {
	             respond_rate=(temp_time-tasks[j].come_time)/tasks[j].run_time;
                 if (respond_rate>max_respond_rate)
                   {
                      max_respond_rate=respond_rate;
                      number_schedul=j;
                    }
               }
           }  
             /*找响应比高的进程*/
        tasks[number_schedul].run_begin_time=temp_time;
        tasks[number_schedul].run_end_time=tasks[number_schedul].run_begin_time+tasks[number_schedul].run_time;
        temp_time=tasks[number_schedul].run_end_time;
        tasks[number_schedul].run_flag=1;
        temp_counter+=1;
        tasks[number_schedul].order=temp_counter; 
    }
  return 0;
}

int sjf()     /*短作业优先*/
{
   float temp_time=0;
   int i=0,j;
   int number_schedul,temp_counter;
   float run_time;
   run_time=tasks[i].run_time;
   j=1;
   while ((j<counter)&&(tasks[i].come_time==tasks[j].come_time))
    {
      if (tasks[j].run_time<tasks[i].run_time) 
        { 
           run_time=tasks[j].run_time;
           i=j;
        }
     j++;
    }     /*查找第一个被调度的进程*/
   /*对第一个被调度的进程求相应的参数*/
   number_schedul=i;
   tasks[number_schedul].run_begin_time=tasks[number_schedul].come_time;
   tasks[number_schedul].run_end_time=tasks[number_schedul].run_begin_time+tasks[number_schedul].run_time;
   tasks[number_schedul].run_flag=1;
   temp_time=tasks[number_schedul].run_end_time;
   tasks[number_schedul].order=1;
   temp_counter=1;
   while (temp_counter<counter)
    {
       for(j=0;j<counter;j++)
         {
           if((tasks[j].come_time<=temp_time)&&(!tasks[j].run_flag))
            {
	           run_time=tasks[j].run_time;number_schedul=j;
	           break;
		    }
         }

       for(j=0;j<counter;j++)    
	     { 
	       if((tasks[j].come_time<=temp_time)&&(!tasks[j].run_flag))
           if(tasks[j].run_time<run_time) 
             {
  				run_time=tasks[j].run_time;
                number_schedul=j;
             }
         } 
        /*查找下一个被调度的进程*/
       /*对找到的下一个被调度的进程求相应的参数*/
       tasks[number_schedul].run_begin_time=temp_time;
       tasks[number_schedul].run_end_time=tasks[number_schedul].run_begin_time+tasks[number_schedul].run_time;
       tasks[number_schedul].run_flag=1;
       temp_time=tasks[number_schedul].run_end_time;
       temp_counter++;
       tasks[number_schedul].order=temp_counter;  
    }
  return 0;
}

int pinput() /*进程参数输入*/
{ 
  int i;
  cout<<"please input the process counter:";
  cin>>counter;
  cout<<endl;
  for(i=0;i<counter;i++)
    { 
	   cout<<"******************************************"<<endl;
       cout<<"please input the process of %d th :"<<" "<<i+1<<endl;
	   cout<<"please input the name:";
       cin>>tasks[i].name;
       cout<<endl;
       cout<<"please input the number:";
       cin>>tasks[i].number;
       cout<<endl;
       cout<<"please input the come_time:";
       cin>>tasks[i].come_time;
       cout<<endl;
       cout<<"please input the run_time:";
       cin>>tasks[i].run_time;
       cout<<endl;
       tasks[i].run_begin_time=0;
       tasks[i].run_end_time=0;
       tasks[i].order=0;
       tasks[i].run_flag=0;
    }
  return 0;
}
int poutput() /*调度结果输出*/
{
  int i;
  float turn_round_time=0,f1,w=0;
  cout<<"name number come_time run_time run_begin_time run_end_time order turn_round_time"<<endl;
  for(i=0;i<counter;i++)
    {
       f1=tasks[i].run_end_time-tasks[i].come_time;
       turn_round_time+=f1;
       w+=(f1/tasks[i].run_time);
       cout<<tasks[i].name<<" "<<tasks[i].number<<" "<<tasks[i].come_time<<" "<<tasks[i].run_time<<" "<<tasks[i].run_begin_time<<" "<<tasks[i].run_end_time<<" "<<tasks[i].order<<" "<<f1<<endl;
    }
  cout<<"average_turn_round_timer="<<turn_round_time/counter<<" ";
  cout<<"weight_average_turn_round_timer="<<w/counter<<endl;
  return 0;
}


