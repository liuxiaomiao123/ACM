#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	int N;
	int a[1005];
	int i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		   scanf("%d",&a[i]);
		sort(a,a+N);
		/*用插入排序和sort函数都可以通过 
		for(i=0;i<N-1;i++)
		{
			j=i+1;
			k=a[j];
			for(;a[j-1]>k && j>0;j--)
			   a[j]=a[j-1];
			a[j]=k;
		}*/
		for(i=0;i<N;i++)
		{ 
		if(i!=N-1) 
		  printf("%d ",a[i]);
		  else
		printf("%d\n",a[i]);
		} 
	}
	return 0;
}
