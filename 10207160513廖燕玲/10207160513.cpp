// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>
using namespace std;
#define MAX 10
struct task_struct
   {
     char name[10];          /*��������*/
     int number;             /*���̱��*/
     float come_time;         /*����ʱ��*/
     float run_begin_time;     /*��ʼ����ʱ��*/
     float run_time;           /*����ʱ��*/
     float run_end_time;       /*���н���ʱ��*/
     int order;               /*���д���*/
     int run_flag;              /*���ȱ�־*/
   }
tasks[MAX];
int counter;                  /*ʵ�ʽ��̸���*/
int fcfs();                   /*�����ȷ���*/
int hrrn();            		 /*��Ӧ�ȸ����ȼ�����*/
int sjf();           		 /*����ҵ����*/
int pinput();          		/*���̲�������*/
int poutput();        		 /*���Ƚ�����*/

int _tmain(int argc, _TCHAR* argv[])
{ 
  int option;
  pinput();
  cout<<"��ѡ������㷨��0~3��:"<<" ";
  cout<<"1.�����ȷ���"<<" ";
  cout<<"2.��Ӧ�ȸ����ȵ���"<<" ";
  cout<<"3.����ҵ����"<<" ";
  cout<<"0.�˳�"<<endl;
  cin>>option;
  if (option==0)
    {
       cout<<"���н�����"<<endl;
     }
  if (option==1)
    { 
       cout<<"�Խ��̰������ȷ�����ȡ�"<<endl;
       fcfs();
       poutput();
     }
   if (option==2)
    { 
       cout<<"�Խ��̰���Ӧ�ȸ����ȵ��ȡ�"<<endl;
       hrrn();
       poutput();
     }
   if (option==3)
    { 
       cout<<"�Խ��̰�����ҵ���ȵ��ȡ�"<<endl;
       sjf();
       poutput();
    }
}
int fcfs()    /*�����ȷ���*/
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

int hrrn() /*��Ӧ�ȸ�����*/
{ 
   int j,number_schedul,temp_counter;
   float temp_time,respond_rate,max_respond_rate;
   /*��һ�����̱�����*/
   tasks[0].run_begin_time=tasks[0].come_time;
   tasks[0].run_end_time=tasks[0].run_begin_time+tasks[0].run_time;
   temp_time=tasks[0].run_end_time;
   tasks[0].run_flag=1;
   tasks[0].order=1;
   temp_counter=1;
   /*������������*/
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
             /*����Ӧ�ȸߵĽ���*/
        tasks[number_schedul].run_begin_time=temp_time;
        tasks[number_schedul].run_end_time=tasks[number_schedul].run_begin_time+tasks[number_schedul].run_time;
        temp_time=tasks[number_schedul].run_end_time;
        tasks[number_schedul].run_flag=1;
        temp_counter+=1;
        tasks[number_schedul].order=temp_counter; 
    }
  return 0;
}

int sjf()     /*����ҵ����*/
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
    }     /*���ҵ�һ�������ȵĽ���*/
   /*�Ե�һ�������ȵĽ�������Ӧ�Ĳ���*/
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
        /*������һ�������ȵĽ���*/
       /*���ҵ�����һ�������ȵĽ�������Ӧ�Ĳ���*/
       tasks[number_schedul].run_begin_time=temp_time;
       tasks[number_schedul].run_end_time=tasks[number_schedul].run_begin_time+tasks[number_schedul].run_time;
       tasks[number_schedul].run_flag=1;
       temp_time=tasks[number_schedul].run_end_time;
       temp_counter++;
       tasks[number_schedul].order=temp_counter;  
    }
  return 0;
}

int pinput() /*���̲�������*/
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
int poutput() /*���Ƚ�����*/
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


