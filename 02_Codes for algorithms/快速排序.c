#include <stdio.h>
int a[100];

void quicksort(int a[],int s,int e)
{
	int i,j;
	int tmp;
	int mid;
	tmp=a[s];
	if(s>=e)
		return;
	i=s;
	j=e;
	while(i<j)
	{
		while(a[j]>=tmp && j>i)
			j--;
		a[i]=a[j];
		while(a[i]<=tmp && i<j)
			i++;
		a[j]=a[i];
	}
	a[j]=tmp;
	mid=j;
	quicksort(a,s,mid);
	quicksort(a,mid+1,e);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
    for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}