#include <stdio.h>
#include <string.h>

int a[1005][1010];
int main()
{
	int i,j,s,c,n,m;

	memset(a,0,sizeof(a));
	a[1][0]=1;
	a[2][0]=1;
	for(i=3;i<1005;i++)
	{
		c=0;
		for(j=0;j<=1000;j++)
		{
			s=a[i-2][j]+a[i-1][j]+c;
			a[i][j]=s%10;
			c=s/10;
			
		}
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i=1010;a[m][i]==0 && i>=0;i--);
		i++;
		while(i--)
		{
			printf("%d\n",a[m][i]);
		}
	}
	return 0;
}