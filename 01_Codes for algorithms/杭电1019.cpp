#include <stdio.h>
/*��С������=�������ĳ˻�/���Լ��

  ���Լ���㷨��շת�����
  1. a%b������c
  2. ��c=0,��b��Ϊ���������Լ��
  3. ��c!=0,��a=b,b=c,�ٻ�ȥִ��1

*/

int main()
{
	int N;
	int m;
	int i;
	int a,b,c;
	int n[100000];
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
		    scanf("%d",&n[i]);
		for(i=0;i<m-1;i++)
		{
				a=n[i];
				b=n[i+1];
				while(b)
				{
					c=a%b;
					a=b;
					b=c;
				}
				n[i+1]=n[i]/a*n[i+1];     //�ȳ��ٳ˷�ֹ��� 
		}
		printf("%d\n",n[m-1]);
	}
 } 
