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
		//seed[0]=rand()%100+1;    //生成0~100的随机数
		seed[0]=1;                //用随机数无法输出，其实只要它周期不是mod，无论seed[0]取多少都不会改变结果
		                          //故可随便取seed[0]. 
		for(i=0;i<mod;i++)
		{
			seed[i+1]=(seed[i]+step) % mod;
		}
		for(i=1;i<=mod;i++)
		{
			if(seed[i]==seed[0])
			{
				if(i==mod)    //一开始是想通过seed[0]==seed[mod]来直接判断，但是可能有漏洞，比如循环周期是2，
				              //也有可能会造成seed[0]==seed[mod].故还是用循环判断这个i是否等于mod.
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
