#include <stdio.h>

/*最小公倍数=两整数的乘积/最大公约数

  最大公约数算法：辗转相除法
  1. a%b得余数c
  2. 若c=0,则b即为两数的最大公约数
  3. 若c!=0,则a=b,b=c,再回去执行1

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
	printf("最大公约数为：%d\n",a);
	printf("最小公倍数为：%d\n",m*n/a);
}


//穷举法求最小公倍数  设a>b

for(i=a;;i++)
{
	if(i%a==0 && i%b==0)
		break;
	printf("最大公倍数为：%d\n",i);
}
