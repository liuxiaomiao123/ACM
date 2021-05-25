#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node
{
	int num;   //num为编号
	int m;     //m为密码
	struct node *next;
}CirNode,*CirLinkList;


/*InitCirLinkList(CirLinkList *L)
{
	*L=(CirLinkList)malloc(sizeof(CirNode));
	(*L)->next=*L;
}*/


CirLinkList CreateCirLinkList(int n)
{
	CirLinkList p,s;CirLinkList L;
	int num,m,i;
    p=L=(CirLinkList)malloc(sizeof(CirNode));
    L->num=1;
    scanf("%d",&L->m);
	for(i=2;i<=n;i++)
	{
		s=(CirLinkList)malloc(sizeof(CirNode));
		//scanf("%d",&s.num);
         s->num=i;
		scanf("%d",&s->m);//这样写，省略了后面两句
		//s->num=num;
		//s->m=m;
		p->next=s;
		//p=p->next;
		p=s;

	}
	   p->next=L;
	return p;
}


Josephu(int m)
{
	CirLinkList prior,p,L;
	int i,j;
	//InitCirLinkList(&L);
	L=CreateCirLinkList(N);
	prior=L;
   for(j=1;j<=N;j++)
  {
    for(i=1;i<=m-1;i++)
	   prior=prior->next;
	  p=prior->next;
      m=p->m;
	  printf("出队编号的序列为：");
	  printf("%d->",p->num);
	  prior->next=p->next;
	  free(p);


  }
	/*if(prior->next != NULL)
	   Josephu(m);
	printf("\n");*/
}


main()
{
	int m;
	printf("请输m的值：");
	scanf("%d",&m);
	Josephu(m);
}





