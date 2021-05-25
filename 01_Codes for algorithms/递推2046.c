#include <stdio.h>
#define M 55

int main()
{
	int n,i;
	_int64 a[M];
	a[1]=1;
	a[2]=2;
	for(i=3;i<M;i++)
		a[i]=a[i-1]+a[i-2];
	while(scanf("%d",&n) != EOF)
	{
		printf("%I64d\n",a[n]);
	}
}


//第n个，即2*n时，可由第n-1个的竖直排列再加一个，和第n-2个中横着排两个（因为竖着的一个、横着的两个是最基本元素，当n>=3时，所有情况都由这两种组成）