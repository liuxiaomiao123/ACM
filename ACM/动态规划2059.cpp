/*
��dp[i]��ʾ ����i�����վ�����ʱ�䣻

�����������󵽵�3�����վ�õ����ʱ����������
1.�ڵڶ������վʱ �� �г��򲻳�� �����ַ�ʽ���� ��3�����վ
  �������վ�ľ��� len=p[3]-p[2];
  �������ʱ  T1=len/VT2; 
  �����ʱ --���������
              C<len :  T2=C/VT1+(len-C)/VT2;
			  C>-len : T2=Len/VT2;
  ���� dp[3]=dp[2]+min{T1,T2};
  
  ��ô����ǵ����3�����վ�����ʱ���𣿲�һ������Ϊ�п��ܴӵ�һ�����վֱ�ӵ����������վ��ʱ�����
  
 2.�����ǻ�Ҫ�Ƚϴ�dp[1]��dp[3] ���������dp[2]��dp[3] ������� ����������ѡ��ʱ�����ٵġ�
 
 
 ���Ϸ������������i�����վ�����ʱ�䣬��Ҫ�Ѵӵ�0������i-1�����վȫ��ɨ��һ�飬ÿһ�˶�������������������ٴ���i-1����
 ѡ����С�ġ���Ҳ�����������Ϊʲô��������forѭ���� 
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
			scanf("%d",p+i);         //p1,p2.....pn�ֱ��ʾ�������վ���ܵ����ľ��� 
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
				double time2=1.0*len/VT2;      //�ӵ�j�����վ����i�����վ  ѡ��  �ýŵ�
				double time1;
				if(len > C)                    //�ӵ�j�����վ����i�����վ  ѡ��  ���--�����������������ѡС�� 
				        time1=1.0*C/VT1 + 1.0*(len-C)/VT2 + T; 
				else
				        time1=1.0*len/VT1 + T;
				if(j==0)
				     time1-=T;         //��һ�γ�������Ҫ���
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
