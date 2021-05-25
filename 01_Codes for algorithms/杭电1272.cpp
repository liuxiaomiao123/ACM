#include <stdio.h>

int set[100005];
int visited[100005];

void init()
{
	for(int i=1;i<100005;i++)
	{
	  set[i]=i;
	  visited[i]=0;
	}
}

int find(int x)
{
	int r=x;
	while(set[r] != r)
	    r=set[r];
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
	int a,b,i;
	int x,y;
	int flag=1;
	int sum=0;
	while(scanf("%d%d",&a,&b))
{
		if(a==-1 && b==-1)
		  break;
		if(a==0 && b==0)
		{
		  printf("Yes\n");
		  continue;	
		}
		init();
		sum=0;
		flag=1;
		visited[a]=visited[b]=1;	
		merge(a,b);
		
		while(scanf("%d%d",&a,&b) != EOF && (a||b))
	 {
		visited[a]=visited[b]=1;
		if(find(a) != find(b))
		{
		    merge(a,b);
		}
		else
		{
		    printf("No\n");
		    flag=0;
		}
	 }
	  for(i=1;i<100005;i++)
	 {
		if(set[i]==i && visited[i])
		   sum++;
	 }
	if(flag && sum==1)
	   printf("Yes\n");
	if(sum>1 && flag)
	   printf("No\n");
}
    return 0;
}
