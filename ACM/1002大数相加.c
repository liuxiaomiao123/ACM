#include <stdio.h>
#include <string.h>
#define M 1000

void ADD(char str1[],char str2[])
{
	int num1[M]={0};
	int num2[M]={0};
	int num3[M]={0};
	int i,j;
    for(i=strlen(str1)-1,j=0;i>=0;i--)
	{
		num1[j++]=str1[i]-'0';
	}
	for(i=strlen(str2)-1,j=0;i>=0;i--)
	{
		num2[j++]=str2[i]-'0';
	}
	for(i=0;i<M;i++)
	{
		num3[i]+=num1[i]+num2[i];
		if(num3[i]>9)
		{
			num3[i+1]=num3[i]/10;		
			num3[i]=num3[i]%10;

		   //num3[i]-=10;
			//num3[i+1]++;
		}
	}
	for(i=M-1;num3[i]==0 && i>=0;i--);
	printf("%s  +  %s  =  ",str1,str2);
	if(i>=0)
	{
		i++;
		while(i--)
		{
			printf("%d",num3[i]);
		}
	}
	else
		printf("0");

}



int main()
{
	int T,k=1;
    char str1[M]={0};
	char str2[M]={0};
	scanf("%d",&T);
	if(T>=1 && T<=20)
	{
		while(T--)
		{
			scanf("%s%s",str1,str2);
			printf("Case %d:\n",k++);
			ADD(str1,str2);
         	if(T>0)
			{
     	         printf("\n\n");
			}
         	else
		         printf("\n");
		}
	}
}
