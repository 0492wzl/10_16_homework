#include<iostream>
#define MaxNum 100
using namespace std;
int ArrivalTime[MaxNum],ServiceTime[MaxNum],FinishTime[MaxNum],WholeTime[MaxNum];
double AVEWholeTime[MaxNum],AVEWeightWholeTime[MaxNum],WeightWholeTime[MaxNum],AverageWT_FCFS,AverageWT_SJF,AverageWWT_FCFS,AverageWWT_SJF;
int ServiceTime_SJF[MaxNum];
int Num=0;
int NowTime=0;
double SumWT=0,SumWWT=0;
int i;
int choice;
void FCFS();
void SJF();
void FCFS()
{
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"-----------------------------FCFS-----------------------------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	int i;
	//temp_time=0;
cout<<"----------先来先服务算法-----------"<<endl;
cout<<"请输入进程的到达时间："<<endl;
//temp_time=ArrivalTime[0];
//for(i=0;i<N;i++)
//{
//    ServiceTime[i]=temp_time;
//    FinishTime[i]=ServiceTime[i]+WholeTime[i];
//	run_flag[i]=1;
//    temp_time=FinishTime[i];
//}
//return 0;
for(int i=0;i<Num;i++)
{
	if(ArrivalTime[i]>NowTime)
	{
		NowTime=ArrivalTime[i];
	}
	NowTime+=ServiceTime[i];
	FinishTime[i]=NowTime;
	WholeTime[i]=FinishTime[i]-ArrivalTime[i];
	WeightWholeTime[i]=WholeTime[i]/ServiceTime[i];
	SumWT+=WholeTime[i];
	SumWWT+=WeightWholeTime[i];
}
AverageWT_FCFS=SumWT/Num;
AverageWWT_FCFS=SumWWT/Num;
for(i=0;i<Num;i++)
{
	cout<<"时刻   "<<FinishTime[i]-ServiceTime[i]<<"进程   "<<i+1<<"开始运行 "<<"完成时间："<<FinishTime[i]<<"周转时间："<<WholeTime[i]<<"帯权周转时间："<<WeightWholeTime[i]<<endl;
	/*cout<<"完成时间："<<FinishTime[i]<<endl;
	cout<<"周转时间："<<WholeTime[i]<<endl;
	cout<<"帯权周转时间："<<WeightWholeTime[i]<<endl;*/
}
cout<<"平均周转时间："<<AverageWT_FCFS<<endl;
cout<<"平均带权周转时间："<<AverageWWT_FCFS<<endl;
}
void SJF()
{
    cout<<"--------------------------------------------------------------"<<endl;
	cout<<"-----------------------------SJF-----------------------------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	int min=0;
	NowTime=ArrivalTime[0]+ServiceTime[0];
    FinishTime[0]=NowTime;
    ServiceTime_SJF[0]=100;
	cout<<"时刻"<<FinishTime[0]-ServiceTime[0]<<": 进程"<<1<<"开始运行。";
    int turm=0,j,k;
	for(i=1;i<Num;i++)//进入循环，从第二个到达的进程开始
	{
		k=1;min=0;
		if(turm==0)//找到已经到达的进程个数
		{
			j=0;
			while(ArrivalTime[j]<=NowTime && j<Num)//已经到达的进程
			{
				j++;
				if(j>=Num)
				{
					turm=1;
				}
			}
		}
		else
		{
			j=Num;
		}
		j=j-1;
		while(k<=j)
		{
			if(ServiceTime_SJF[k]==0)
				k++;
			else
			{
				if(ServiceTime_SJF[min]>ServiceTime_SJF[k])
					min=k;
				k++;
			}
		}
		ServiceTime_SJF[min]=0;
		NowTime+=ServiceTime[min];
		FinishTime[min]=NowTime;//完成时间
	}
	for(i=0;i<Num;i++)//计算周转时间，带权周转时间，总的周转时间和总的带权周转时间
	{
		WholeTime[i]=FinishTime[i]-ArrivalTime[i];
		WeightWholeTime[i]=(double)WholeTime[i]/ServiceTime[i];
		SumWT+=WholeTime[i];
		SumWWT+=WeightWholeTime[i];
	}
	AverageWT_SJF=SumWT/Num;//平均周转时间
	AverageWWT_SJF=SumWWT/Num;//平均带权周转时间
	for(i=1;i<Num;i++)//输出结果
	{
		cout<<"时刻   "<<FinishTime[i]-ServiceTime[i]<<"进程   "<<i+1<<"开始运行 "<<"完成时间："<<FinishTime[i]<<"周转时间："<<WholeTime[i]<<"帯权周转时间："<<WeightWholeTime[i]<<endl;
	}
	cout<<"平均周转时间："<<AverageWT_SJF<<endl;
	cout<<"平均帯权周转时间："<<AverageWWT_SJF<<endl;
}

void input()
{
	cout<<"请输入进程个数：";
	cin>>Num;
	while(Num>100||Num<=0)
	{
		cout<<"进程个数必须大于0且小于等于100！请重新输入进程个数：";
		cin>>Num;

	}
	cout<<"-------------------------------------"<<endl;
	for(i=0;i<Num;i++)
	{
		cout<<"请输入第"<<i+1<<"个进程的到达时间：";
		cin>>ArrivalTime[i];
		

	}
	cout<<"-----------------------------------------"<<endl;
     for(i=0;i<Num;i++)
	 {
		int data=0;
		cout<<"请输入第"<<i+1<<"个进程的服务时间：";
		cin>>data;
		ServiceTime[i]=data;
		ServiceTime_SJF[i]=data;
	}
	 cout<<"-----------------------------------------"<<endl;
	 cout<<"请选择要使用的算法(1-FCFS,2-SJF): ";
	 cin>>choice;
}

void main()
{
    cout<<"*******************************************************************"<<endl;
	cout<<"**   进程调度算法 10级医学信息管理系统  吕坤  学号：10207160511  **"<<endl;
	cout<<"*******************************************************************"<<endl;
	char flag='y';
Loop:
	NowTime=0;SumWT=0;SumWWT=0;
	input();
	if (choice==1)
		FCFS();
	else if(choice==2)
		SJF();
	else
	{
		while(1)
		{
			cout<<"你的选择有误！请重新选择！"<<endl;
			cout<<"请你选择要使用的算法（1-FCFS,2-SJF）：";
			cin>>choice;
			if(choice==1)
			{
				FCFS();
				break;

			}
			else if(choice==2)
			{
				SJF();
				break;

			}
		}

	}
	cout<<endl<<"是否继续使用该程序，按'y'或'Y'键继续，按其他任意键退出：";
	cin>>flag;
	if(flag=='y'||flag=='Y')
		goto Loop;
}
