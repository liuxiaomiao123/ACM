#include <stdio.h>
#define M 10005

int main()
{
	int c,n,i;
	_int64 a[M];
	for(i=1;i<M;i++)
	{
		a[i]=2*i*i-i+1;
	}
	while(scanf("%d",&c) != EOF)
	{
		while(c--)
		{
			scanf("%d",&n);
			printf("%I64d\n",a[n]);
		}
	}
	return 0;
}
