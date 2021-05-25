
#include <stdio.h>
#include <math.h>
#define M 1000

int main()
{
	int n,r,a[M],i,m;
	int b[]={'A','B','C','D','E','F'};
	while(scanf("%d%d",&m,&r) != EOF)
	{
		i=0;
		n=m;
		while(n)
		{
			a[i++]=abs(n%r);
			n=n/r;
		}
		if(m<0)
			printf("-");
		while(i--)
		{
			if(abs(a[i]) >= 10)
				printf("%c",b[a[i]-10]);
			else
				printf("%d",a[i]);
		}
		if(m==0)
			printf("0");
		printf("\n");
	}
	return 0;
}
