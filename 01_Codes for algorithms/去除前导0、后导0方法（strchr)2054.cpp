#include <stdio.h>
#include <string.h>
#define M 100000

char a[M],b[M];

void ridlastz(char *s)
{
	int len=strlen(s);
	char *p=s+len-1;
	if(strchr(s,'.'))
	{
		while(*p=='0')
		{
			*p--=NULL;
		}
	}
	if(*p=='.')
	  *p=NULL;
}


int main()
{
	while(scanf("%s%s",a,b) !=EOF)
	{
		char *pa=a;
		char *pb=b;
		while(*pa=='0')
		     pa++;
		while(*pb=='0')
		     pb++;
	    ridlastz(pa);
	    ridlastz(pb);
	    if(strcmp(pa,pb)==0)
	       printf("YES\n");
	       else
	       printf("NO\n");	    
	}
	return 0;
}
