#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 100

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}BiTNode,*BiTree;


typedef struct 
{
	int top;
	int *base;
	int stacksize;
}SqStack;



CreateBiTree(BiTree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}



InitStack(SqStack *S)
{
	S->base=(int *)malloc(INIT_SIZE*sizeof(int));
	S->top=-1;
	S->stacksize=INIT_SIZE;
}


int StackEmpty(SqStack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}


PushStack(SqStack *S,BiTree e)
{	
	S->top++;
	S->base[S->top]=e;
}


int PopStack(SqStack *S,BiTree *e)
{
	if(S->top==-1)
		return 0;
	*e=S->base[S->top];
	S->top--;
	return 1;
}




/*
preorder(BiTree T)
{
	if(T)
	{
		printf("%6d",T->data);
		preorder(T->lchild);
		preorder(T->rchild);   
	}
}
*/




preorder(BiTree T)
{
	SqStack S;
	BiTree p=T;
	InitStack(&S);
	while(p || !StackEmpty(&S))
	{
		if(p)
		{
			printf("%c->",p->data);
			PushStack(&S,p);
			p=p->lchild;
		}
		else
		{
			PopStack(&S,&p);
			p=p->rchild;
		}
	}
}




/*
Postorder(BiTree T)
{
	SqStack S;
	InitStack(&S);
	BiTree p=T;
    while(p)
	{
		PushStack(&S,p);
		p=p->lchild;
	}
	p=S->base[S->top];

	p=p->rchild;
	while(p)
	{
		Push(&S,p);
		p=p->lchild;
	}
	PopStack(&S,&p);
}
*/




main()
{
	BiTree T;
	CreateBiTree(&T);
	preorder(T);
}
