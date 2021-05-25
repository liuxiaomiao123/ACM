#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int weight;
	int parent,lchild,rchild;
}TNode,*HufTree;



void select(HufTree *ht,int n,*s1,*s2)
{
	int i,min=100;
	for(i=1;i<2*n;i++)
	{
		if(ht[i]->weight <= min && ht[i]->parent ==0 && ht[i]->weight != 0)
		{
			min=ht[i]->weight;
			*s1=i;
		}
	}
	for(i=1;i<2*n;i++)
	{
		if(ht[i]->weight <= min && ht[i]->parent ==0 && ht[i]->weight != 0 && i != s1)
		{
			min=ht[i]->weight;
			*s2=i;
		}
	}
}



void huffman(HufTree *ht,int n,int *w)
{
	int i,s1,s2;
	*ht=(HufTree)malloc((2*n)*sizeof(TNode));
    for(i=1;i<2*n;i++)
	{
		ht[i]->weight=w[i-1];
		ht[i]->parent=0;
		ht[i]->lchild=0;
		ht[i]->rchild=0;
	}                      //¹þ·òÂüÊ÷µÄ³õÊ¼»¯
    for(i=n+1;i<2*n;i++)
	{
		select(&ht,n,&s1,&s2);
		ht[i]->weight=ht[s1]->weight+ht[s2]->weight;
		ht[i]->lchild=s1;
		ht[i]->rchild=s2;
		ht[s1]->parent=i;
	    ht[s2]->parent=i;
	}
}



void PrintHufTree(HufTree ht,int n)
{
	int i;
	for(i=1;i<2*n;i++)
	{
		printf("%d  %d  %d  %d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
	}
}


main()
{
	HufTree ht;
	int n=4;
	int w[4]={4,3,1,3};
	Huffman(&ht,n,&w);
	PrintHufTree(&ht,n);
}