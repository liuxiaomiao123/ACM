//������ֵΪ1Ԫ��3Ԫ��5Ԫ��Ӳ�����ɣ���Ҫ�����ֵΪnԪ������Ҫ���ٸ�Ӳ�ң�

#include <stdio.h>
#include <limits.h>

int main()
{
	int i,n,j;
	int coin[3]={1,3,5};
	int f[100];     //��ֵΪiʱ������Ӳ�����ٵĸ���
	int min;
	f[0]=0;
	printf("��������ֵn��");
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
	printf("�����ֵΪnԪ������Ҫ��Ӳ�Ҹ���Ϊ��");
	printf("%d\n",f[n]);
	return 0;
}