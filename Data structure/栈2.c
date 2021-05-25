#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct Stack
{
	int *base;
	int top;
	int stacksize;
}SqStack;


InitStack(SqStack *S)
{
	S->base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	S->top=-1;
	S->stacksize=STACK_INIT_SIZE;
}


Push(SqStack *S,int e)
{
	if(S->top+1==STACK_INIT_SIZE)
		S->base=(int*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(int));
	S->top++;
	S->base[S->top]=e;
}


int Pop(SqStack *S,int *e)
{
	if(S->top==-1)
	return 0;
    *e=S->base[S->top];
	S->top--;
	return 1;
}


int StackEmpty(SqStack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}


Conversion(int n)
{
	int e;SqStack S;
	InitStack(&S);
	while(n)
	{
		Push(&S,n%8);
		n=n/8;
	}
	while(!StackEmpty(&S))
	{
		Pop(&S,&e);
		printf("%7d",e);
	}
}



main()
{

	int n;
	
    printf("input a number:");
	scanf("%d",&n);
	printf("the number is:");
	Conversion(n);
}