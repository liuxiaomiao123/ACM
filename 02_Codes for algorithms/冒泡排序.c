#include <stdio.h>

int main()
{
	int n;
	int i,j;
	int t;
	int a[100];
	int flag;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++)
		   scanf("%d",&a[i]);
		flag=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
					flag=0;
				}
			}
		 if(flag)
			  break;
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}