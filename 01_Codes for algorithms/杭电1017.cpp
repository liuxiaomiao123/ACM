#include <stdio.h>


int main()
{
	int N;
	int n,m;
	int a,b;
	int count;
	int flag=0;
	scanf("%d",&N);
	
	while(N--)           //注意输入输出格式 
	{
		flag=0;
		while(scanf("%d%d",&n,&m) != EOF && (n||m))
		{
			count=0;
			flag++;
			for(a=1;a<n-1;a++)
			{
				for(b=a+1;b<n;b++)
				{
					if((a*a+b*b+m)%(a*b)==0)
					{
						count++;
					}
				}
			}
			printf("Case %d: %d\n",flag,count);
		}
		if(N)      //最后一组数据后没有空行
     		printf("\n");
	}
	return 0;
}
