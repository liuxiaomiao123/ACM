#include <stdio.h>


int strrindex(char s[],char t[])
{
	int i,j,k,max-1;
	for(i=0;s[i] != '\0';i++)
	{
		for(j=i,k=0;s[j]==t[k] && t[k] != '\0';j++,k++)
			;
		if(t[k] == '\0' && k>0)
			max=i;
	}
	return max;
}



int strrindex(char s[],char t[])
{
	int i,j,k;
	for(i=strlen(s)-strlen(t);i>=0;i++)
	{
		for(j=i,k=0;s[j]==t[k] && t[k] != '\0';j++,k++)
			;
		if(t[k] == '\0' && k>0)
			return i;
	}
}         //逆向查找效率更高