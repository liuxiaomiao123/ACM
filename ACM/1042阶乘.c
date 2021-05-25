#include <stdio.h>
#include <string.h>
#define M 100000
int main()
{
	int n,i,j,temp,c,count;
	int a[M];
	while(scanf("%d",&n) != EOF)
	{
		c=0;
		memset(a,0,sizeof(a));
		a[0]=1;
		count=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<count;j++)
			{
				temp=i*a[j]+c;
				a[j]=temp%10;
				c=temp/10;
			}
	
		    while(c)
			{
				a[count++]=c%10;
				c/=10;
			}
		}
		j=M-1;
	while(a[j]==0)
	{
		j--;
	}
	while(j>=0)
	{
		printf("%d",a[j--]);
	}
	printf("\n");
	}
	return 0;
}