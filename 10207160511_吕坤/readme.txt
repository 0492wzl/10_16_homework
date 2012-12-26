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
cout<<"----------�����ȷ����㷨-----------"<<endl;
cout<<"��������̵ĵ���ʱ�䣺"<<endl;
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
	cout<<"ʱ��   "<<FinishTime[i]-ServiceTime[i]<<"����   "<<i+1<<"��ʼ���� "<<"���ʱ�䣺"<<FinishTime[i]<<"��תʱ�䣺"<<WholeTime[i]<<"��Ȩ��תʱ�䣺"<<WeightWholeTime[i]<<endl;
	/*cout<<"���ʱ�䣺"<<FinishTime[i]<<endl;
	cout<<"��תʱ�䣺"<<WholeTime[i]<<endl;
	cout<<"��Ȩ��תʱ�䣺"<<WeightWholeTime[i]<<endl;*/
}
cout<<"ƽ����תʱ�䣺"<<AverageWT_FCFS<<endl;
cout<<"ƽ����Ȩ��תʱ�䣺"<<AverageWWT_FCFS<<endl;
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
	cout<<"ʱ��"<<FinishTime[0]-ServiceTime[0]<<": ����"<<1<<"��ʼ���С�";
    int turm=0,j,k;
	for(i=1;i<Num;i++)//����ѭ�����ӵڶ�������Ľ��̿�ʼ
	{
		k=1;min=0;
		if(turm==0)//�ҵ��Ѿ�����Ľ��̸���
		{
			j=0;
			while(ArrivalTime[j]<=NowTime && j<Num)//�Ѿ�����Ľ���
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
		FinishTime[min]=NowTime;//���ʱ��
	}
	for(i=0;i<Num;i++)//������תʱ�䣬��Ȩ��תʱ�䣬�ܵ���תʱ����ܵĴ�Ȩ��תʱ��
	{
		WholeTime[i]=FinishTime[i]-ArrivalTime[i];
		WeightWholeTime[i]=(double)WholeTime[i]/ServiceTime[i];
		SumWT+=WholeTime[i];
		SumWWT+=WeightWholeTime[i];
	}
	AverageWT_SJF=SumWT/Num;//ƽ����תʱ��
	AverageWWT_SJF=SumWWT/Num;//ƽ����Ȩ��תʱ��
	for(i=1;i<Num;i++)//������
	{
		cout<<"ʱ��   "<<FinishTime[i]-ServiceTime[i]<<"����   "<<i+1<<"��ʼ���� "<<"���ʱ�䣺"<<FinishTime[i]<<"��תʱ�䣺"<<WholeTime[i]<<"��Ȩ��תʱ�䣺"<<WeightWholeTime[i]<<endl;
	}
	cout<<"ƽ����תʱ�䣺"<<AverageWT_SJF<<endl;
	cout<<"ƽ����Ȩ��תʱ�䣺"<<AverageWWT_SJF<<endl;
}

void input()
{
	cout<<"��������̸�����";
	cin>>Num;
	while(Num>100||Num<=0)
	{
		cout<<"���̸����������0��С�ڵ���100��������������̸�����";
		cin>>Num;

	}
	cout<<"-------------------------------------"<<endl;
	for(i=0;i<Num;i++)
	{
		cout<<"�������"<<i+1<<"�����̵ĵ���ʱ�䣺";
		cin>>ArrivalTime[i];
		

	}
	cout<<"-----------------------------------------"<<endl;
     for(i=0;i<Num;i++)
	 {
		int data=0;
		cout<<"�������"<<i+1<<"�����̵ķ���ʱ�䣺";
		cin>>data;
		ServiceTime[i]=data;
		ServiceTime_SJF[i]=data;
	}
	 cout<<"-----------------------------------------"<<endl;
	 cout<<"��ѡ��Ҫʹ�õ��㷨(1-FCFS,2-SJF): ";
	 cin>>choice;
}

void main()
{
    cout<<"*******************************************************************"<<endl;
	cout<<"**   ���̵����㷨 10��ҽѧ��Ϣ����ϵͳ  ����  ѧ�ţ�10207160511  **"<<endl;
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
			cout<<"���ѡ������������ѡ��"<<endl;
			cout<<"����ѡ��Ҫʹ�õ��㷨��1-FCFS,2-SJF����";
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
	cout<<endl<<"�Ƿ����ʹ�øó��򣬰�'y'��'Y'��������������������˳���";
	cin>>flag;
	if(flag=='y'||flag=='Y')
		goto Loop;
}
