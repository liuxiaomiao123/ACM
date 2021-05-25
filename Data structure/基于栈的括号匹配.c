#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct snode
{
	char data;
	struct snode *next;
}Snode,*LinkStack;


InitStack(LinkStack *S)
{
	*S=NULL;
}



PushStack(LinkStack *S,char e)
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(Snode));
	p->data=e;
	p->next=*S;
	*S=p;
}


int PopStack(LinkStack *S)
{
	LinkStack p;
	if(*S==NULL)
       return 0;
	p=*S;
	*S=p->next;
	free(p);
	return 1;
}


int GetTopStack(LinkStack S,char *e)
{
	if(S==NULL)
		return 0;
	*e=S->data;
	return 1;
}


Matching(char str[])
{
	int i,flag=1;
	char e;
	LinkStack S;
	InitStack(&S);
    for(i=0;str[i]!='\0' && flag;i++)
	{
		switch(str[i])
		{
		case '(':case '{':case '[': 
			     PushStack(&S,str[i]);break;
		case ')': 
			if(S!=NULL)
			{
					  GetTopStack(S,&e);
					  if(e=='(')
						  PopStack(&S);
					  else
						  flag=0;
				  }
			else flag=0;break;

		case '}':
			if(S!=NULL)
			{ 
					  GetTopStack(S,&e);
					  if(e=='{')
						  PopStack(&S);
					  else
						  flag=0;
			}
		   else flag=0;break;

        case ']':
			if(S!=NULL)
			{
				      GetTopStack(S,&e);
					  if(e=='[')
						  PopStack(&S);
					  else
						  flag=0;
			}
		   else flag=0;break;
		}
	}
	if(flag==1 && S==NULL)
		printf("¿®∫≈∆•≈‰£°\n");
	else
		printf("¿®∫≈≤ª∆•≈‰£°\n");
}


main()
{
	char str[6];
	printf("«Î ‰»Î◊÷∑˚£∫");
	gets(str);
	Matching(str);
}