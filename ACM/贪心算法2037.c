#include <stdio.h>
#include <stdlib.h>
#define M 105

typedef struct
{
	int s;
	int e;
}time;
time t[M];


int cmp(const void *a,const void *b)
{
	return (*(time *)a).e-(*(time *)b).e;
}



int main()
{
	int i,end,count,n;
	while(scanf("%d",&n) != EOF && n)
	{
		count=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&t[i].s,&t[i].e);
		qsort(t,n,sizeof(t[0]),cmp);
		count++;
		end=t[0].e;
		for(i=1;i<n;i++)
		{
			if(t[i].s >= end)
			{
				count++;
				end=t[i].e;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}