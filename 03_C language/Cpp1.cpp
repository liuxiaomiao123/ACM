#include <stdio.h>
void change(int a,int b)
{
	int x;
	x=a;
	a=b;
	b=x;
}

main()
{
	int a,b;
	printf("a=");
scanf("%d",&a);
printf("\n");
printf("b=");
scanf("%d",&b);

	change(a,b);
	printf("%d   %d\n",a,b);
}
