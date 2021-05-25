#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextArc;
}ArcNode;


typedef struct VertexNode
{
	char vertex;
	ArcNode *firstArc;
}VertexNode;


typedef struct ALGraph
{
	VertexNode adjlist[Maxsize];
	int vexNum,arcNum;
}ALGraph;


//创建有向图的邻接表
void CreateAdjlist(ALGraph *G)
{
	int i,j,k;
    ArcNode *p;
	printf("请输入图的顶点数、弧数：");
	scanf("%d%d",&G->vexNum,&G->arcNum); 
	for(i=0;i<G->vexNum;i++)       //创建表结点
	{
		printf("请输入编号为%d顶点的值：",i+1);
		scanf("%c",&G->adjlist[i].vertex);
		G->adjlist[i].firstArc=NULL;
	}
	for(k=0;k<G->arcNum;k++)
	{
		printf("请输入弧所依附的弧尾和弧头的序号i和j：");
		scanf("%d%d",&i,&j);     //输入弧所依附的弧尾和弧头的序号i和j
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j-1;
		p->nextArc=G->adjlist[i-1].firstArc;
        G->adjlist[i-1].firstArc=p;
	}
}


int FirstAdjVex(ALGraph G,int i)
{
	int w;
    ArcNode *p;
	p=G.adjlist[i].firstArc;
	w=p->adjvex;
	return w;
}


int NextAdjVex(ALGraph G,int i,int w)
{
    ArcNode *p;
	p=G.adjlist[i].firstArc;
	while(p->adjvex != w)
	{
		p=p->nextArc;
	}
	if(p)
	return p->nextArc->adjvex; 
	else
	return -1;
}



void DFS(ALGraph G,int i,int visited[])
{
	int w;
	printf("%c->",G.adjlist[i-1].vertex);
	visited[i-1]=1;
	w=FirstAdjVex(G,i-1);
    while(w>=0)
	{
		if(visited[w]==0)
			DFS(G,w,visited);
		w=NextAdjVex(G,i,w);
	}
}



main()
{
    ALGraph G;
	int i;
	int visited[4]={0};
    CreateAdjlist(&G);
	printf("从哪个结点开始遍历？请输入结点序号（1--5）");
    scanf("%d",&i);
	DFS(G,i,visited);
}