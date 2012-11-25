#include<iostream>
using namespace std;
#define MaxNum 100
int  ArrivalTime[MaxNum];
double  ServiceTime[MaxNum];
double  FinishTime[MaxNum];
double  WholeTime[MaxNum];
double  WeightWholeTime[MaxNum];
double AverageWT;
double AverageWWT;
double AllTime,WeightAllTime;
double a[MaxNum];
int ProcessNum;
int b[MaxNum];
void FCFS();
void SJF();

void Input()
{
	cout<<"请输入进程个数：";
	cin>>ProcessNum;
	cout<<"输入进程到达时间：";
	cout<<endl;
	for(int i=0;i<ProcessNum;i++) cin>>ArrivalTime[i];
	cout<<endl;
	cout<<"请输入进程服务时间：";
	cout<<endl;
	for(int i=0;i<ProcessNum;i++) cin>>ServiceTime[i];
	cout<<endl;
}

void Output()
{
	cout<<"时刻"<<ArrivalTime[0]<<":第"<<1<<"个进程开始运行。"<<endl;
	for(int i=0;i<ProcessNum-1;i++)
	{
		cout<<"时刻"<<FinishTime[i]<<":第"<<i+2<<"个进程开始运行。"<<endl;
	}
		for(int i=0;i<ProcessNum;i++)
	{
		WholeTime[i]=FinishTime[i]-ArrivalTime[i];
	}
	AllTime=0;
	for(int i=0;i<ProcessNum;i++)
	{
		AllTime=AllTime+WholeTime[i];
	}
	AverageWT=AllTime/ProcessNum;
	for(int i=0;i<ProcessNum;i++)
	{
		WeightWholeTime[i]=WholeTime[i]/ServiceTime[i];
	}
	WeightAllTime=0;
	for(int i=0;i<ProcessNum;i++)
	{
		WeightAllTime=WeightAllTime+WeightWholeTime[i];
	}
	AverageWWT=WeightAllTime/ProcessNum;
	cout<<"完成时间：";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<FinishTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"周转时间：";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<WholeTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"平均周转时间:"<<AverageWT<<endl;
	cout<<"带权周转时间：";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<WeightWholeTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"平均带权周转时间:"<<AverageWWT<<endl;
}

void FCFS()
{
	cout<<endl<<"----------先来先服务算法----------"<<endl;
	for(int i=0;i<ProcessNum;i++)
	{
		FinishTime[i]=ServiceTime[i];
	}
	FinishTime[0]=ArrivalTime[0]+ServiceTime[0];
	for(int i=0;i<ProcessNum;i++)
	{
		FinishTime[i+1]=FinishTime[i]+FinishTime[i+1];
	}
	Output();
}

void SJF()
{
	cout<<endl<<"----------短作业优先算法----------"<<endl;
	for(int i=0;i<ProcessNum;i++)
	{
		a[i]=ServiceTime[i];
	}
	for(int i=1;i<ProcessNum-1;i++)
	{
		double exchange;
		for(int j=i+1;j<ProcessNum;j++)
		{
			if(a[i]>a[j])
			{
				exchange=a[i];
				a[i]=a[j];
				a[j]=exchange;
			}
		}
	}
	a[0]=FinishTime[0]=ServiceTime[0]+ArrivalTime[0];
	for(int i=1;i<ProcessNum;i++)
	{
		for(int j=1;j<ProcessNum;j++)
		{
			if(a[i]==ServiceTime[j])
			{
				b[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<ProcessNum;i++)
	{
		for(int j=i;j<ProcessNum-1;j++)
		if(FinishTime[b[i-1]]<ArrivalTime[b[i]])
		{
			for(int k=i;k<ProcessNum-1;k++)
			{
				int temp;
				temp=b[k];
				b[k]=b[k+1];
				b[k+1]=temp;
			};
		};
		a[i]=ServiceTime[b[i]];
		a[i]=a[i-1]+a[i];
		FinishTime[b[i]]=a[i];
	}
	Output();
}

void main()
{
	char flag='Y';
	char n;
	cout<<"----------调度算法FCFS && SJF-----------"<<endl;;
	while(flag=='Y'||flag=='y')
	{ 
		cout<<endl;
		cout<<"1、先来先服务 FCFS 算法 ."<<endl;
		cout<<"2、短作业优先 SJF 算法."<<endl;
		cout<<"3、先来先服务 FCFS 算法&短作业优先 SJF 算法.";
	    cout<<"请您选择算法的序号："<<endl;
		cin>>n;
	    switch(n)
		{
		case'1':
			Input();
			FCFS();
		    break;
	    case'2':
			Input();
		    SJF();
			break;
		case'3':
			Input();
			FCFS();
			SJF();
			break;
		default:
			cout<<endl;
			cout<<"您输出有误!"<<endl;
			break;
		}
		cout<<endl;
		cout<<"是否继续调度算法FCFS && SJF，按'Y'or'y'钮继续,按照'N'or'n'键退出"<<endl;
		cin>>flag;
	}
}
