#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Lnode,*Linklist;


InitList(Linklist *L)
{
	*L=(Linklist)malloc(sizeof(Lnode));
    (*L)->next=NULL;
}


CreateList(Linklist L,int n)
{
	Linklist p,r;
	int i;
	r=L;
	for(i=0;i<n;i++)
	{
		p=(Linklist)malloc(sizeof(Lnode));
		scanf("%d",&p->data);
		r->next=p;
		r=p;
	}
	r->next=NULL;
}



ConvertList(Linklist L)
{
	Linklist p,q;
	
	p=L->next;       
	L->next=NULL;      
	while(p)
	{
		q=p;           //q指向当前要操作的结点
		p=p->next;     //p指向下一个结点
		q->next=L->next;
		L->next=q;
	}
	/*
	p=L->next;
	L->next=NULL;
	q=p->next;
	while(p)
	{
       p->next=L->next;
	   L->next=p;
	   p=q;
	   q=q->next;
	}
    */
}

PrintList(Linklist L)
{
	Linklist p=L->next;
	while(p)
	{
		printf("%d->",p->data);
		p=p->next;
	}
   printf("\n");
}


main()
{
	int n;
	Linklist L;
	InitList(&L);
	printf("input the list length:");
	scanf("%d",&n);
	CreateList(L,n);
	PrintList(L);
	ConvertList(L);
    PrintList(L);
}