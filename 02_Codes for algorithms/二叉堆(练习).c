#include <stdio.h>

int heap[5]={20,35,24,65,0};

void Insert(int i)
{
	int j=(i-1)/2;
	int tmp;
	while(heap[j]>heap[i] && j>=0)
	{
		tmp=heap[j];
		heap[j]=heap[i];
		heap[i]=tmp;
		i=j;
		j=(i-1)/2;
	}
}

int main()
{
	int i;
	heap[4]=15;
	Insert(4);
	for(i=0;i<5;i++)
		printf("%d ",heap[i]);
	printf("\n");
	return 0;
}