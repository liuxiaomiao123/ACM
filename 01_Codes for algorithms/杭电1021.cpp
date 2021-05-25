#include <stdio.h>

int main()
{
	/* 因为菲波数是个大数，大数用整型数组存储，而数组是无法进行%3运算的，这时我们有两种方法：找规律和数论。
	   先来用代码试一下是否有规律， 结果是有的，下标依次为2，6,10,14....即一个等差数列。 
	int a[40],i;
	a[0]=7;a[1]=11;
	for(i=2;i<40;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]%3==0)
		{
			printf("%d:%d\n",i,a[i]);
		}
	}
	*/
	int i,a[260000];   //an=a1+(n-1)*d,an<1000000,算出n=250000.5,故取260000，否则取1000000会超出整数范围。 
	int n;
	a[0]=2;
	for(i=0;i<260000;i++)
	{
		a[i+1]=a[i]+4;
	}
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<260000;i++)
	   {
	   	   if(n>a[i])
	   	      continue;
	   	   else if(n==a[i])
	   	   {
	   	   	printf("yes\n");
	   	   	break;
		   }
		   else
		   {
		      printf("no\n");
		      break;
		   }

	   }
	}
	return 0;
}
