#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100


//���������ʾ��������


typedef struct Node
{
	int child;
	struct Node *next;
}CNode,*ChildPtr;


typedef struct 
{
	int data;
	ChildPtr link;
}CBox;


typedef struct
{
	CBox nodes[MAXLEN];
	int n,r; 
}ChildList;




CreateTree(ChildList *T)
{
	int i,j,k;
	ChildPtr p,s;
	char father,child;

	printf("������������");
	scanf("%d",&T->n);
	//getchar();
	printf("�밴�����������%d������ֵ",T->n);
	for(i=0;i<T->n;i++)
	{
		scanf("%d",&T->nodes[i].data);
		T->nodes[i].link=NULL;
	}
	//getchar();
    T->r=0;
	printf("�밴<˫�ף�����>����%d��֧<�������£���������>��\n",T->n-1);
	for(i=1;i<=T->n-1;i++)
	{
		scanf("%d%d",&father,&child);
		//getchar();
		for(j=0;j<T->n;j++)
		   if(father==T->nodes[j].data)
			   break;                  //��j���游���������±�
		if(j>T->n)
		{
			printf("����������д�\n");
			return;                  
		}
		for(k=0;k<T->n;k++)
			if(child==T->nodes[k].data)
				break;                  //��k���溢�ӽ��������±�
		if(k>=T->n)
		{			
			printf("����������д�\n");
			return;
		}

        p=T->nodes[j].link;
        if(p)
		{
			s=(ChildPtr)malloc(sizeof(CNode));
			s->child=k;
			s->next=NULL;
			T->nodes[j].link=s;
		}
		else
		{
			while
		}
	}
}