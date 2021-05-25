#include <stdio.h>

int main()
{
	int n,x[3],y[3];
	double s;
	while(scanf("%d",&n) != EOF && n)
	{
		s=0;
		scanf("%d%d",&x[0],&y[0]);
		x[2]=x[0];
		y[2]=y[0];
		while(--n)
		{
			scanf("%d%d",&x[1],&y[1]);
			s+=x[0]*y[1]-x[1]*y[0];
			x[0]=x[1];
			y[0]=y[1];
		}
		s+=x[0]*y[2]-x[2]*y[0];
		printf("%.1lf\n",s/2);
	}
	return 0;
}