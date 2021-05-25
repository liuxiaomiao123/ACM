//已知一顺序表A，其元素非递减有序排列，编写一个函数删除顺序表中多余的值相同的元素


#include <stdio.h>
#include <stdlib.h>
#define InitSize 100

typedef strcut
{
	int length;
	int listsize;
	int *elem;
}SqList;


InitSqList(SqList *L)
{
	L->elem=(SqList *)malloc(InitSize*sizeof(int));
	L->length=0;
	L->listsize=InitSize;
}


CreateSqList(SqList L)
{
	int i;
	printf("input the list length:");
	scanf("%d",&(L.length));
	for(i=0;i<L.length;i++)
	{
		scanf("%d",&L.elem[i]);
	}
}



Delete(SqList *L)
{
	int i=j=0;
	for(;i<L->length;i++)
	{
		if(L->elem[i] != L->elem[i+1])
		{
			L->elem[j]=L->elem[i];
			j++;
		}
	}
}




PrintSqList(SqList)
{
}