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


//쳲��������еĵ�47����ѳ���int�͵ķ�Χ����50�ʼ��Ϊ11λ������int���޷����㣬��VC���޷�ʶ��long long���ͣ�����_int64����
