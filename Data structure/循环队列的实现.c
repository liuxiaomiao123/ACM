#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 6

typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;


InitQueue(SqQueue *Q)
{
	Q->base=(int*)malloc(sizeof(int)*MAXQSIZE);
	Q->front=Q->rear=0;
}


int EnQueue(SqQueue *Q,int e)
{
	if((Q->rear+1)%MAXQSIZE==Q->front)
	{ printf("full!");return 0;}
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}


int DeQueue(SqQueue *Q,int *e)
{
	if(Q->front==Q->rear)
	{printf("empty!"); return 0;}
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}


int QueueLength(SqQueue *Q)
{
	return (Q->rear-Q->front+MAXQSIZE) % MAXQSIZE;
}


main()
{
	SqQueue Q;
	int i,e;
	InitQueue(&Q);
	printf("输入5个数入队列：");
	for(i=0;i<5;i++)
	{
		scanf("%d",&e);
		EnQueue(&Q,e);
	}
	printf("当前队列长度为：");
	printf("%d\n",QueueLength(&Q));
    printf("输出队列为：");
	for(i=0;i<5;i++)
	{
		DeQueue(&Q,&e);
		printf("%7d",e);
	}
	printf("\n");
	printf("当前队列长度为：");
	printf("%d\n",QueueLength(&Q));
	printf("\n");
}