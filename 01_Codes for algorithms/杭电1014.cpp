#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main()
{
	int step,mod;
	int seed[100010];
	int i; 
	while(scanf("%d%d",&step,&mod) != EOF)
	{
		//srand(time(NULL));
		//seed[0]=rand()%100+1;    //����0~100�������
		seed[0]=1;                //��������޷��������ʵֻҪ�����ڲ���mod������seed[0]ȡ���ٶ�����ı���
		                          //�ʿ����ȡseed[0]. 
		for(i=0;i<mod;i++)
		{
			seed[i+1]=(seed[i]+step) % mod;
		}
		for(i=1;i<=mod;i++)
		{
			if(seed[i]==seed[0])
			{
				if(i==mod)    //һ��ʼ����ͨ��seed[0]==seed[mod]��ֱ���жϣ����ǿ�����©��������ѭ��������2��
				              //Ҳ�п��ܻ����seed[0]==seed[mod].�ʻ�����ѭ���ж����i�Ƿ����mod.
				{
					printf("%10d%10d    Good Choice\n",step,mod); 
					break;
				}
				else
				{
					printf("%10d%10d    Bad Choice\n",step,mod);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
