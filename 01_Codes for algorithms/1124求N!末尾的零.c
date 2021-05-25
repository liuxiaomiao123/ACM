#include <stdio.h>
int main()
{
	int T,n,count;
	scanf("%d",&T);
	while(T--)
	{
		count=0;
		scanf("%d",&n);
		while(n)
		{
			count+=n/5;
			n/=5;
		}
		printf("%d\n",count);
	}
	return 0;
}