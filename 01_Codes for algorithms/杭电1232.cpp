#include <stdio.h>

int set[1005];
int N,M;

void init()
{
	int i;
		for(i=1;i<=N;i++)
		{
			set[i]=i;
		}
}
int find(int x)
{
	int r=x;
	while(set[r] != r)
	{
		r=set[r];
	}
	return r;
}

void merge(int x,int y)
{
	int fx,fy;
	fx=find(x);
	fy=find(y);
	if(fx!=fy)
	{
		set[fx]=fy;
	}
}

int main()
{
	int a,b,i,count;
	while(scanf("%d",&N),N)
	{
		count=0;
		scanf("%d",&M);
	    init();
		while(M--)
		{
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		for(i=1;i<=N;i++)
		{
			if(set[i]==i)
			   count++;
		}
		printf("%d\n",count-1);
	}
	return 0;
}
