#include <stdio.h>
#define M 25

_int64 cal(int n,int m)
{
	int i;
	_int64 s1,s2,s3;
	s1=s2=s3=1;
	for(i=1;i<=n;i++)
	    s1*=i;
	    for(i=1;i<=m;i++)
	    s2*=i;
	    for(i=1;i<=(n-m);i++)
	    s3*=i;
	    return s1/s2/s3;
}


int main()
{
	int n,m,c;
	int i;
	_int64 a[M],k;
	a[1]=0;
	a[2]=1;
	for(i=3;i<M;i++)
	{
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	}
	while(scanf("%d",&c) != EOF)
	{   
		while(c--)
	{
		scanf("%d%d",&n,&m);
	    k=cal(n,m);
		printf("%I64d\n",k*a[m]);
	}

	}
	return 0;
}