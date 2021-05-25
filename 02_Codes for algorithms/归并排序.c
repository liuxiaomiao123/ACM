#include <stdio.h>
int a[100];
int tmp[100];


void merge(int a[],int s,int m,int e,int tmp[])
{
	int p1,p2,k,i;
	p1=s;
    p2=m+1;
	k=0;
	while(p1<=m && p2<=e)
	{
		if(a[p1]<a[p2])
			tmp[k++]=a[p1++];
		else
			tmp[k++]=a[p2++];
	}
	while(p1<=m)
		tmp[k++]=a[p1++];
    while(p2<=e)
		tmp[k++]=a[p2++];
	for(i=0;i<e-s+1;i++)
		a[s+i]=tmp[i];
}

void sort(int a[],int s,int e,int tmp[])
{
	int m;
	if(s<e)
	{
		m=(s+e)/2;    //m=s+(e-s)/2
		sort(a,s,m,tmp);
		sort(a,m+1,e,tmp);
		merge(a,s,m,e,tmp);
	}
}  

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,0,n-1,tmp);
    for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}