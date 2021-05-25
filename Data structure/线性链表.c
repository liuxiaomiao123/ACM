#include <stdio.h>
#include <stdlib.h>

struct Lnode
{
	int data;
	struct Lnode *next;
};
typedef struct Lnode Lnode,*Linklist;

/*
Linklist createLinklist(int n)
{
	int i;
	Linklist L,p;
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;

	for(i=1;i<=n;i++)
	{ 
	  p=(Linklist)mallloc(sizeof(Lnode));
      scanf("%d",&p->data);
	  p->next=L->next;
	  L->next=p;
	}
	return L;
}
*/


Linklist createLinklist(int n)

{
	int i;
	Linklist L,p,r;
	r=L=(Linklist)malloc(sizeof(Lnode));
	//p=(Linklist)malloc(sizeof(Lnode));
	//L->next=NULL;

	for(i=1;i<=n;i++)
	{ 
	  p=(Linklist)malloc(sizeof(Lnode));
      scanf("%d",&p->data);
	  r->next=p;
	  r=p;
	}
    r->next=NULL;
	return L;
}


InsertLinklist (Linklist L,int i,int e)
{
	Linklist p,s;
	int j=0;
	p=L;
	while(j<i-1 && p)    //p->next是可以为空的，也就是在表尾插入最后一个数
	{
		p=p->next;
		j++;
	}
	s=(Linklist)malloc(sizeof(Lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}


DeleteLinklist(Linklist L,int i)
{
	Linklist p,q;
	int j=0;
	p=L;
	while(j<i-1 && p->next)     //p->next不可以为空，
	{
		p=p->next;
		j++;
	}

	q=p->next;
	p->next=q->next;
	free(q);
}




void printlist(Linklist L)
{
	Linklist p;
	p=L->next;
	while(p != NULL)   //while(p)，这里指的是p指针的地址，而不是p->next
	{	printf("%7d",p->data);
	p=p->next;  
	}//指向下一个结点
}



main()
{
	int n;
	Linklist L;
	printf("input the length");
	scanf("%d",&n);
	L=createLinklist(n);
	InsertLinklist(L,4,100);
	printlist(L);
	printf("\n");
	DeleteLinklist(L,4);
	printlist(L);
}