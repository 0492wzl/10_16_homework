#include "stdio.h"
#define n 20
#define m 5
void main(){
	int ym[n],t[n]={1,5,4,3,2,4,5,8,7,45,4,12,1,4,1,4,46,25,3,51},i,j,q,mem[m]={0},table[m][n];
	char flag,f[n];
	int count=0;
	/*printf("������ҳ����ʵ�˳��\n");
	for(i=0;i<n;i++)scanf("%d",&ym[i]);*//*����ÿ�ζ�Ҫ���������ԣ������޸�ֵ����t[n]�����޸ģ���ʵ����ֱ�ӳ�ʼ��ym[n]������*/
	for(i=0;i<n;i++)ym[i]=t[i];
	printf("\n");
	for(i=0;i<n;i++){
	q=0;
	while((ym[i]!=mem[q])&&(q!=m))q++;
	if(q==m){count++;flag='*';}
	else flag=' ';
	for(j=q;j>0;j--)
		mem[j]=mem[j-1];
	mem[0]=ym[i];
	for(j=0;j<m;j++)
		table[j][i]=mem[j];
	f[i]=flag;
	}
	printf("������Ϊ��0����գ�*����ȱҳ��\n");
	for(i=0;i<m;i++){
	for(j=0;j<n;j++)printf("%3d",table[i][j]);
	printf("\n");
	}
	for(i=0;i<n;i++)printf("%3c",f[i]);
	printf("\nһ������%d��ȱҳ\n",count);
}
