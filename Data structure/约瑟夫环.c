#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node
{
	int num;   //num为编号
	int m;     //m为密码
	struct node *next;
}CirNode,*CirLinkList;


/*void InitCirLinkList(CirLinkList *L)
{
	*L=(CirLinkList)malloc(sizeof(CirNode));
	(*L)->next=*L;
}*/


int CreateCirLinkList(CirLinkList *L,int n)
{
	CirLinkList p,s;
	int num,m,i;
    
	if(n<=0)  return 0;
	else
	{
		p=*L=(CirLinkList)malloc(sizeof(CirNode));
	   scanf("%d%d",&p->num,&p->m);
 	for(i=2;i<=n;i++)
	{
		s=(CirLinkList)malloc(sizeof(CirNode));
		scanf("%d",&num);
		scanf("%d",&m);
		s->num=num;
		s->m=m;
		p->next=s;
		p=p->next;
	}
	p->next=*L;
	}
	return 1;
}





Josephu(CirLinkList prior,int m)
{
	CirLinkList p;
	int i;
//	InitCirLinkList(&L);
	
//	prior=L;
	for(i=1;i<m-1;i++)
		prior=prior->next;
	p=prior->next;
    m=p->m;

	printf("%d->",p->num);
	prior->next=p->next;
	free(p);
     p=prior->next;
	if(prior->next != prior)
	   Josephu(p,m);
	else
		printf("%d",prior->num);
	printf("\n");
}


main()
{
	int m;CirLinkList L;
	printf("请输m的值：");
	scanf("%d",&m);
	CreateCirLinkList(&L,N);//初始化约瑟夫环
    printf("出队编号的序列为：");
	Josephu(L,m);
}





