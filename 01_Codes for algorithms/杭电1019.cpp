#include <stdio.h>
/*最小公倍数=两整数的乘积/最大公约数

  最大公约数算法：辗转相除法
  1. a%b得余数c
  2. 若c=0,则b即为两数的最大公约数
  3. 若c!=0,则a=b,b=c,再回去执行1

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
				n[i+1]=n[i]/a*n[i+1];     //先除再乘防止溢出 
		}
		printf("%d\n",n[m-1]);
	}
 } 
