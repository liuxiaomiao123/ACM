//现有面值为1元、3元、5元的硬币若干，问要组成面值为n元最少需要多少个硬币？

#include <stdio.h>
#include <limits.h>

int main()
{
	int i,n,j;
	int coin[3]={1,3,5};
	int f[100];     //面值为i时，所需硬币最少的个数
	int min;
	f[0]=0;
	printf("请输入面值n：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		min=INT_MAX;
		for(j=0;j<3;j++)
		{
			if(i>=coin[j])
			{
				if((f[i-coin[j]]+1)<min)
					min=f[i-coin[j]]+1;
			}
		}
		f[i]=min;
	}
	printf("组成面值为n元最少需要的硬币个数为：");
	printf("%d\n",f[n]);
	return 0;
}