#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int set[105];
int m,n;

struct road
{
	int u,v,w;
};
road s[10000];

int cmp(road a,road b)
{
	return a.w<b.w;
}

void init()
{
	int i;
	for(i=1;i<=n;i++)
	    set[i]=i;
}

int find(int x)
{
	int r=x;
	while(set[r]!=r)
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
	   set[fx]=fy;
}

int main()
{
	int i,j,sum;
	while(scanf("%d",&n),n)
	{
		m=n*(n-1)/2;
		for(i=0;i<m;i++)
		   scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
		sum=0;
		sort(s,s+m,cmp);
		init();
		for(i=0;i<m;i++)
		{
			if(find(s[i].u) != find(s[i].v))
			{
				merge(s[i].u,s[i].v);
				sum+=s[i].w;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
