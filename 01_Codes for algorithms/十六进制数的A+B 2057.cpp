#include <stdio.h>

int main()
{
	_int64 a,b;
	while(scanf("%I64x%I64x",&a,&b) != EOF)   //����a,bֵ���ܻ�ܴ���_int64���ͣ����������ʮ�����Ƶĸ�ʽ�����޷����� 
	{
		if(a+b>=0)
		   printf("%I64X\n",a+b);
		   else
		     printf("-%I64X\n",-(a+b));       //XΪ��дʱ����ʾ�����ʮ���������ô�д��ĸ��ʾ�� 
	}
	return 0; 
}
