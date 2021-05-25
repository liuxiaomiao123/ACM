#include <stdio.h>

int getmin(int a[],int k)
{
	if(k==0)
		return a[0];
	return a[k]<getmin(a,k-1)?a[k]:getmin(a,k-1);
}

int main()
{
	int n;
	int i;
	int a[100];
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",getmin(a,n-1));
	}
	return 0;
}

