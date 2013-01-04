#include "stdio.h"
#define n 20
#define m 5
void main(){
	int ym[n],t[n]={1,5,4,3,2,4,5,8,7,45,4,12,1,4,1,4,46,25,3,51},i,j,q,mem[m]={0},table[m][n];
	char flag,f[n];
	int count=0;
	/*printf("请输入页面访问的顺序\n");
	for(i=0;i<n;i++)scanf("%d",&ym[i]);*//*避免每次都要输入来调试，如需修改值，再t[n]那里修改；其实可以直接初始化ym[n]就行了*/
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
	printf("输出结果为（0代表空，*代表缺页）\n");
	for(i=0;i<m;i++){
	for(j=0;j<n;j++)printf("%3d",table[i][j]);
	printf("\n");
	}
	for(i=0;i<n;i++)printf("%3c",f[i]);
	printf("\n一共发生%d次缺页\n",count);
}
