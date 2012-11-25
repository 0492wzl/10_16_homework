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
	cout<<"��������̸�����";
	cin>>ProcessNum;
	cout<<"������̵���ʱ�䣺";
	cout<<endl;
	for(int i=0;i<ProcessNum;i++) cin>>ArrivalTime[i];
	cout<<endl;
	cout<<"��������̷���ʱ�䣺";
	cout<<endl;
	for(int i=0;i<ProcessNum;i++) cin>>ServiceTime[i];
	cout<<endl;
}

void Output()
{
	cout<<"ʱ��"<<ArrivalTime[0]<<":��"<<1<<"�����̿�ʼ���С�"<<endl;
	for(int i=0;i<ProcessNum-1;i++)
	{
		cout<<"ʱ��"<<FinishTime[i]<<":��"<<i+2<<"�����̿�ʼ���С�"<<endl;
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
	cout<<"���ʱ�䣺";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<FinishTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"��תʱ�䣺";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<WholeTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"ƽ����תʱ��:"<<AverageWT<<endl;
	cout<<"��Ȩ��תʱ�䣺";
	for(int i=0;i<ProcessNum;i++)
	{
		cout<<WeightWholeTime[i]<<"  ";
	}
	cout<<endl;
	cout<<"ƽ����Ȩ��תʱ��:"<<AverageWWT<<endl;
}

void FCFS()
{
	cout<<endl<<"----------�����ȷ����㷨----------"<<endl;
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
	cout<<endl<<"----------����ҵ�����㷨----------"<<endl;
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
	cout<<"----------�����㷨FCFS && SJF-----------"<<endl;;
	while(flag=='Y'||flag=='y')
	{ 
		cout<<endl;
		cout<<"1�������ȷ��� FCFS �㷨 ."<<endl;
		cout<<"2������ҵ���� SJF �㷨."<<endl;
		cout<<"3�������ȷ��� FCFS �㷨&����ҵ���� SJF �㷨.";
	    cout<<"����ѡ���㷨����ţ�"<<endl;
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
			cout<<"���������!"<<endl;
			break;
		}
		cout<<endl;
		cout<<"�Ƿ���������㷨FCFS && SJF����'Y'or'y'ť����,����'N'or'n'���˳�"<<endl;
		cin>>flag;
	}
}
