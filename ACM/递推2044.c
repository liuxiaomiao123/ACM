#include <stdio.h>
#define M 55

int main()
{
	int n,a,b,i;
	_int64 f[M];
	f[1]=1;
	f[2]=1;
	for(i=3;i<M;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&n) != EOF)
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			printf("%I64d\n",f[b-a+1]);
		}
	}
	return 0;
}


//斐波那契数列的第47项就已超出int型的范围，第50项开始就为11位数，故int型无法满足，而VC中无法识别long long类型，故用_int64类型
