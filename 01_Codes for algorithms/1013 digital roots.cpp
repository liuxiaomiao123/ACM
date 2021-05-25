#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	char str[1000];
	int s,m;
	while(scanf("%s",str) != EOF)
	{
		if(strlen(str)==1 && str[0]=='0')
		break;
		s=0;
		for(i=strlen(str)-1; i>=0; i--)
		{
			s=s+str[i]-'0';
		}
		do
		{
			m=0;
			while(s)
			{
				m+=s%10;
				s/=10;
			}
		s=m;
		}while(m>=10);
		printf("%d\n",m);
	}
return 0;
}
