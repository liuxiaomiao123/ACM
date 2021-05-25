#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ 
	float coef;     //存放系数
	int exp;        //存放指数
	struct node *next;
}Lnode,*Linklist;


InitList(Linklist *L)
{
	*L=(Linklist)malloc(sizeof(Lnode));
	(*L)->next=NULL;
}



CreateList(Linklist L,int n)
{
	int i;
	Linklist p,r;
	r=L;
    for(i=0;i<n;i++)
	{
		p=(Linklist)malloc(sizeof(Lnode));
		scanf("%f",&p->coef);
		scanf("%d",&p->exp);
		p->next=NULL;
		r->next=p;
		r=p;
	}
}



AddList(Linklist La,Linklist Lb,Linklist Lc)
{
	Linklist pa,pb,pc,s;
	pa=La->next;
	pb=Lb->next;
	pc=Lc;
    while(pa && pb)
	{
		if(pa->exp < pb->exp)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->exp=pa->exp;
			s->coef=pa->coef;
			//s->next=NULL;
			pc->next=s;
			pc=s;
			pa=pa->next;
		}
		else if(pa->exp == pb->exp)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->exp=pa->exp;
		    s->coef=pa->coef+pb->coef;
			//s->next=NULL;
			if(s->coef !=0)
			{
			pc->next=s;
			pc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
		else
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->exp=pb->exp;
			s->coef=pb->coef;
			//s->next=NULL;
			pc->next=s;
			pc=s;
			pb=pb->next;
		}
	}
	while(pa)
	{
		s=(Linklist)malloc(sizeof(Lnode));
		s->exp=pa->exp;
		s->coef=pa->coef;
		s->next=NULL;
		pc->next=s;
		pc=s;
		pa=pa->next;
	}
	while(pb)
	{
		s=(Linklist)malloc(sizeof(Lnode));
		s->exp=pb->exp;
		s->coef=pb->coef;
		s->next=NULL;
		pc->next=s;
		pc=s;
		pb=pb->next;
	}

}	



PrintList(Linklist L)
{
	Linklist p;
	p=L->next;
	while(p)
	{
		printf("%.1fx^%d+",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");

}




main()
{
	Linklist La,Lb,Lc;
	int n,x;
	InitList(&La);
	printf("Input the La list Length:");
	scanf("%d",&n);
	CreateList(La,n);
    PrintList(La);

	InitList(&Lb);
	printf("Input the Lb list Length:");
	scanf("%d",&x);
	CreateList(Lb,x);
    PrintList(Lb);


	InitList(&Lc);
	AddList(La,Lb,Lc);
	PrintList(Lc);
}

