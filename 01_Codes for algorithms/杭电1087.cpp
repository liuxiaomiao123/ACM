#include <stdio.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int N;
	int i,j;
	int a[1005];
	int maxsum[1005];
	int maxtotal;
	while(scanf("%d",&N) != EOF && N)
	{
		maxtotal=0;
		for(i=0;i<N;i++)
		{
		    scanf("%d",&a[i]);
		    maxsum[i]=a[i];
		}
		for(i=1;i<N;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i])
				   maxsum[i]=max(maxsum[i],maxsum[j]+a[i]);
			}
		}
		for(i=0;i<N;i++)
		     maxtotal=max(maxtotal,maxsum[i]);
		printf("%d\n",maxtotal);
	}
	return 0;
}
