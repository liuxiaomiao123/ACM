/*
   Ӳ�����⣺����һЩ����Ӳ�ң�Ȼ���һ��ֵN���������N�������ٵ�Ӳ�ҵ����� 
   �������룺3      //��ʾ������������ 
             2 3 5
             11
       �����3 
*/ 

#include <stdio.h>
#define M 100
int main()
{
	int N;
	int T;
	int i,j;
	int flag=0;
	int temp[M];
	int choice[M];        //Ӳ���������� 
	int d[M];             //d[i]��ʾֵNΪiʱ�������ٵ�Ӳ������
	d[0]=0; 
	scanf("%d",&T);          //��ʾ������������
	for(i=0;i<T;i++)
	    scanf("%d",&choice[i]);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	    d[i]=1000000;
	
	for(i=1;i<=N;i++)
	{
		for(j=0;j < T;j++)
		{
			if(choice[j] > i || i-choice[j] == 1)         //�ҵ�Ӳ������iС��;���ڲ�������ֵΪһ���Ӳ��,�����������ȥ�� 
			    continue;
			else
			{ 
		        flag=1;
				temp[i]=d[i-choice[j]]+1;          //d[i]=min{d[i-choice[j]]+1}
				if(temp[i] < d[i])
				   d[i]=temp[i];	
			}
	    }
	    if(flag==0)
	       d[i]=0;               //Ӳ�����ȫ������N���Ҳ�������С��
	}
	
	for(i=1;i<=N;i++)
	   printf("d[%d]=%d\n",i,d[i]);
}
