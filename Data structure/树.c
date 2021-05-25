#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100


//孩子链表表示法创建树


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

	printf("请输入结点数：");
	scanf("%d",&T->n);
	//getchar();
	printf("请按层次依次输入%d个结点的值",T->n);
	for(i=0;i<T->n;i++)
	{
		scanf("%d",&T->nodes[i].data);
		T->nodes[i].link=NULL;
	}
	//getchar();
    T->r=0;
	printf("请按<双亲，孩子>输入%d分支<从上至下，从左至右>：\n",T->n-1);
	for(i=1;i<=T->n-1;i++)
	{
		scanf("%d%d",&father,&child);
		//getchar();
		for(j=0;j<T->n;j++)
		   if(father==T->nodes[j].data)
			   break;                  //用j保存父结点的数组下标
		if(j>T->n)
		{
			printf("输入的数据有错！\n");
			return;                  
		}
		for(k=0;k<T->n;k++)
			if(child==T->nodes[k].data)
				break;                  //用k保存孩子结点的数组下标
		if(k>=T->n)
		{			
			printf("输入的数据有错！\n");
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