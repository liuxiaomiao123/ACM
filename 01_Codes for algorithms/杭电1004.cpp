#include <stdio.h>
#include <string.h>
char s[1010][16];

//�����ѵ㣺�����ж�����ֵ
//����ؼ���ÿ������ͳ�ƴ��������ÿ�����ɫ���ظ��ԣ���Ϊ�Ǵ��������ĺ�������ѭ���Ƚϣ�����ɫ���ظ���
//ǰ��Ŀ϶��Ⱥ������Ҫ�ࡣ 

int main()
{
	int n,i,j;
	int count[1010]={1};     //��Ϊ�����ж�����ֵ������Ҫ�������� 
	int max=0;
	while(scanf("%d",&n) != EOF && n)
	{
		max=0;
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(strcmp(s[i],s[j])==0)
				{
					count[i]++;
				}
			}
			if(count[i]>max)
			{
				max=count[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(count[i]==max)
			{
				printf("%s\n",s[i]);
			}
		}

	}
	return 0;
}
