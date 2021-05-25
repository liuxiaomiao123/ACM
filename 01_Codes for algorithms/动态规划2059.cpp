/*
用dp[i]表示 到第i个充电站的最短时间；

这里我们先求到第3个充电站用的最短时间来分析：
1.在第二个充电站时 ， 有充电或不充电 这两种方式到达 第3个充电站
  两个充电站的距离 len=p[3]-p[2];
  不充电用时  T1=len/VT2; 
  充电用时 --有两种情况
              C<len :  T2=C/VT1+(len-C)/VT2;
			  C>-len : T2=Len/VT2;
  所以 dp[3]=dp[2]+min{T1,T2};
  
  那么这就是到达第3个充电站的最短时间吗？不一定，因为有可能从第一个充电站直接到第三个充电站的时间更少
  
 2.故我们还要比较从dp[1]到dp[3] 的情况；从dp[2]到dp[3] 的情况， 从这三者中选出时间最少的。
 
 
 综上分析，我们求第i个充电站的最短时间，就要把从第0个到第i-1个充电站全部扫描一遍，每一趟都包含上述两种情况，再从这i-1趟中
 选择最小的。这也是下面代码中为什么用了两个for循环。 
*/




#include <stdio.h>

int L;
int N,C,T;
int VR,VT1,VT2;
int p[110];
double dp[110];

double min(double a,double b)
{
	return a>b?b:a;
}

int main()
{
	while(scanf("%d",&L) != EOF)
	{
		scanf("%d%d%d",&N,&C,&T);
		scanf("%d%d%d",&VR,&VT1,&VT2);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",p+i);         //p1,p2.....pn分别表示各个充电站离跑道起点的距离 
		}
		p[0]=0;
		p[N+1]=L;
		for(int i=0;i<=N+1;i++)
		{
			dp[i]=0xfffff;
		}
		dp[0]=0.0;
		for(int i=1;i<=N+1;i++)
		{
			for(int j=0;j<i;j++)
			{
				int len=p[i]-p[j];
				double time2=1.0*len/VT2;      //从第j个充电站到第i个充电站  选择  用脚瞪
				double time1;
				if(len > C)                    //从第j个充电站到第i个充电站  选择  充电--则有两种情况，从中选小。 
				        time1=1.0*C/VT1 + 1.0*(len-C)/VT2 + T; 
				else
				        time1=1.0*len/VT1 + T;
				if(j==0)
				     time1-=T;         //第一次出发不需要充电
			    double time=min(time1,time2);
				dp[i]=min(dp[i],dp[j]+time);        
			}
		}
		double rab_t=1.0*L/VR;
		if(rab_t>dp[N+1])
		{
			printf("What a pity rabbit!\n");
		}
		else
		{
			printf("Good job,rabbit!\n");
		}
	}
	return 0;
}
