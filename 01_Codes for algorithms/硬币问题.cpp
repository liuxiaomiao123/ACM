/*
   硬币问题：给你一些面额的硬币，然后给一个值N，求出构成N所需最少的硬币的数量 
   例：输入：3      //表示输入的种类个数 
             2 3 5
             11
       输出：3 
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
	int choice[M];        //硬币面额的种类 
	int d[M];             //d[i]表示值N为i时所需最少的硬币数量
	d[0]=0; 
	scanf("%d",&T);          //表示输入的种类个数
	for(i=0;i<T;i++)
	    scanf("%d",&choice[i]);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	    d[i]=1000000;
	
	for(i=1;i<=N;i++)
	{
		for(j=0;j < T;j++)
		{
			if(choice[j] > i || i-choice[j] == 1)         //找到硬币面额比i小的;由于不存在面值为一块的硬币,所以这种情况去除 
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
	       d[i]=0;               //硬币面额全部大于N，找不到比它小的
	}
	
	for(i=1;i<=N;i++)
	   printf("d[%d]=%d\n",i,d[i]);
}
