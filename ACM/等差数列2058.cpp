#include <stdio.h>

/*
int main()
{
	int n,m,i,j,sum;
	while(scanf("%d%d",&n,&m) != EOF &&n &&m)
	{
		for(i=1;i<=n;i++)
		{
			sum=0;
			for(j=i;j<=n;j++)
			{
				sum+=j;
				if(sum==m)
				{
					printf("[%d,%d]\n",i,j);
					break;
				}
			}
		}
		printf("\n");
	}
}此种做法显示超时，那么如何减少时间呢？由于这里是首项为1，公差为1的确定的等差数列，而首项、项数，和是知二求一的。
现在我们已知和为M，可以利用公式s=m=n*a1+n(n-1)/2穷举项数n,求出满足的首项a1,即可求出末项a1+n-1.
（项数n一定有个最大值，而且易知这个最大值是在a1=1时取得，最小值可猜想是ai=m时取得） 
注意：这里是不存在有两种情况的项数是一样的情况的，举例即可得。即唯一的项数n对应唯一的首项a1.
 
这样，我们就把原先的穷举首项a1转化为穷举项数n,由于a1的可能取值是1-1000000000，而n的取值范围要远远小于这么多，故时间缩短。 
*/ 


/* 
等差求和公式:

Sn=(a1+aN)*n/2
    =(a1+a1+d(n-1))*n/2
    =a1*n+d(n-1)*n/2;
因为此处公差d=1，所以Sn=a1*n+(n-1)*n/2,当从第一项开始算起时（因本题首项为1，即a1=1时），Sn=M时的项的个数n最多;
a1=1，现在又可化简为Sn=n+(n-1)*n/2=(n+1)n/2;
由题意得M=Sn,N为项的个数，则N<=n(max)=sqrt(Sn*2)=sqrt(M*2);
因此原式M=Sn =a1*n+(n-1)n/2=a1*N+(N-1)N/2,可得a1*N=M-(N-1)N/2;
数据都已经全了，现在只要遍历n(max)以内项数中，Sn=M的个数即可。
那么如何判断Sn=M呢？也就是判断a1*N=Sn-(N-1)N/2;得到的a1*N这个数能否被N整除，因为整除的话，说明首项存在于序列
*/

#include <stdio.h>
#include <math.h>
int main() 
{
	int n,m,len,len_a1;
	while(scanf("%d%d",&n,&m) != EOF && (n||m))
	{
		len=(int)sqrt(2.0*m);
		for(;len>0;len--)
		{
			len_a1=m-len*(len-1)/2;     //奇数*偶数=偶数，故这里一定能被整除 。利用公式a1*N=M-(N-1)N/2。 
			if(len_a1 % len==0)
			   printf("[%d,%d]\n",len_a1/len,len_a1/len+len-1);
		}
		printf("\n");
	}
	return 0;
}












