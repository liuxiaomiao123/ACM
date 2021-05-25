#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}Lnode,*Linklist;


InitLinklist(Linklist L)
{
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
}


CreateLinklist(Linklist L,int n)
{
	int i;
    Linklist p,r;
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


AddLinklist(Linklist La,Linklist Lb,Linklist Lc)
{
	Linklist pa,pb,pc,s;
	pa=La->next;
	pb=Lb->next;
	pc=Lc;
    while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->data=pa->data;
			pc->next=s;
			pc=s;
			pa=pa->next;
		}
		else
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->data=pb->data;
			pc->next=s;
			pc=s;
			pb=pb->next;
		}	
	}
		
	  while(pa)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->data=pa->data;
			pc->next=s;
			pc=s;
			pa=pa->next;
		}
		s->next=NULL;
		while(pb)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->data=pb->data;
			pc->next=s;
			pc=s;
			pb=pb->next;
		}
	    s->next=NULL;
}

printlist(Linklist L)
{
	Linklist p;
	p=L->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
}


main()
{
	
	Linklist La,Lb,Lc;
	int n,x;
    InitLinklist(La);
	printf("Input the La Length:");
	scanf("%d",&n);
	CreateLinklist(La,n);

    InitLinklist(Lb);
	printf("Input the Lb Length:");
	scanf("%d",&x);
	CreateLinklist(Lb,x);

	InitLinklist(Lc);
	AddLinklist(La,Lb,Lc);
	printlist(Lc);
}