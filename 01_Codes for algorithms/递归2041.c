/*
当你到达第n阶的时候有两种到达方式。 在n-1处上 1个楼梯。在n-2处上2个楼梯

所以上N阶楼梯的情况总数=上n-1的总数+上n-2的总数

这样递推公式就出来了
f（n）=f（n-1）+f（n-2）
*/



#include <stdio.h>

int main()
{
	int n,a[45],m,i;
	a[1]=1;
	a[2]=1;
	while(scanf("%d",&n) != EOF)
	{
		for(i=3;i<=45;i++)
				a[i]=a[i-1]+a[i-2];
			while(n--)
			{			

			scanf("%d",&m);
			printf("%d\n",a[m]);
			}
	}
	return 0;
}