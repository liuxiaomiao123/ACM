#include <stdio.h>
#include <stdlib.h>  //malloc函数等
#define INITSIZE 100

//typedef int elemtype;
struct list
{
	int *elem;
	int length;
	int listsize;
};

typedef struct list sqlist; 
   
                      
sqlist initlist()
{
	sqlist L;            // struct list L;
	L.elem=(int *) malloc(INITSIZE*sizeof(int));     //malloc函数默认是void型,需要强制转换 
	L.length=0;
	L.listsize=INITSIZE;
	return L;
}

void setlist(sqlist *L)
{
	int i;
	printf("input the length:");
	scanf("%d",&(L -> length));
	for(i=1;i<=L->length;i++)
		scanf("%d",&(L -> elem[i])); //用 
}


void printlist(sqlist *L)
{
	int i;
	printf("input the value");
	for(i=1;i<=L->length;i++)
		printf("->%d\n",L->elem[i]);
}


main()
{
     sqlist L;
	 L=initlist();        //调用函数
	 setlist(&L);
	 printlist(&L);
}