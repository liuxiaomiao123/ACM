#include <stdio.h>

/*��С������=�������ĳ˻�/���Լ��

  ���Լ���㷨��շת�����
  1. a%b������c
  2. ��c=0,��b��Ϊ���������Լ��
  3. ��c!=0,��a=b,b=c,�ٻ�ȥִ��1

*/


int main()
{
	int a,b,c,m,n;
	scanf("%d%d",&a,&b);
	m=a;
	n=b;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	printf("���Լ��Ϊ��%d\n",a);
	printf("��С������Ϊ��%d\n",m*n/a);
}


//��ٷ�����С������  ��a>b

for(i=a;;i++)
{
	if(i%a==0 && i%b==0)
		break;
	printf("��󹫱���Ϊ��%d\n",i);
}
