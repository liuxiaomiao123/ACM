#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node
{
	int num;   //numΪ���
	int m;     //mΪ����
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
		scanf("%d",&s->m);//����д��ʡ���˺�������
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
	  printf("���ӱ�ŵ�����Ϊ��");
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
	printf("����m��ֵ��");
	scanf("%d",&m);
	Josephu(m);
}





