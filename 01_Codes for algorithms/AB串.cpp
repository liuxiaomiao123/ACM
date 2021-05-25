#include <stdio.h>

int main()
{
	int n;
	int i;
	int m;
	int dp[45];
	dp[2]=3;
	dp[3]=5;
	for(i=4;i<45;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",dp[m]);
	}
	return 0;
}
