#include <stdio.h>
#include <string.h>
char s[1010][16];

//此题难点：可能有多个最大值
//解题关键：每个气球都统计次数，不用考虑颜色的重复性，因为是从这个气球的后面气球循环比较，若颜色有重复，
//前面的肯定比后面次数要多。 

int main()
{
	int n,i,j;
	int count[1010]={1};     //因为可能有多个最大值，必须要用数组存放 
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
