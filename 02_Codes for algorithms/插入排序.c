#include <stdio.h>

int main()
{
	int n;
	int a[100];
	int i,j,k;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
        for(i=1;i<n;i++)
		{
			j=i;
			k=a[j];
			while(a[j-1]>k && j>0)
			{
				a[j]=a[j-1];
				j--;
			}
			a[j]=k;
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
return 0;
}