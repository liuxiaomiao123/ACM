#include <stdio.h>

int main()
{
	_int64 a,b;
	while(scanf("%I64x%I64x",&a,&b) != EOF)   //由于a,b值可能会很大，用_int64类型，输入输出有十六进制的格式，是无符号数 
	{
		if(a+b>=0)
		   printf("%I64X\n",a+b);
		   else
		     printf("-%I64X\n",-(a+b));       //X为大写时，表示输出的十六进制数用大写字母表示。 
	}
	return 0; 
}
