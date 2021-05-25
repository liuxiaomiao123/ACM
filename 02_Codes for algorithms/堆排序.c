#include <stdio.h>

void fixdown(int a[],int i,int n)
{
	int t;
	int j=2*i+1;
	while(j<n)
	{
		if(a[j]>a[j+1] && j+1<n)
			j=j+1;
		if(a[i]>a[j])
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
		i=j;
		j=2*i+1;
	}
}

void CreateBinaryTree(int a[],int n)  
{
	int i=(n-2)/2;
	for(;i>=0;i--)
		fixdown(a,i,n);
}

void SortBinaryTree(int a[],int n)   
{
	int t;
	int i;
	for(i=n-1;i>=0;i--)
	{
	    t=a[0];   //a[0]存的都是当前堆的最小值
	    a[0]=a[i];
		a[i]=t;
		fixdown(a,0,n);
	}
}

int main()
{
	int n,i;
	int a[100];
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		CreateBinaryTree(a,n);
		printf("创建的二叉堆为: ");
        for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		SortBinaryTree(a,n);
		printf("创建的极小堆为: ");
        for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}