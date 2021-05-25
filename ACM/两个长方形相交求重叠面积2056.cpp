#include <stdio.h>
 
void swap(double *a,double *b)
{
	double t;
	t=*a;
	*a=*b;
	*b=t;
}

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double a,c,b,d;    //重叠部分的长方形的左下方和右上方坐标（a,c）(b,d) 
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4) != EOF)
	{
		if(x1>x2)
		  swap(&x1,&x2);
		if(y1>y2)
		  swap(&y1,&y2);
		if(x3>x4)
		  swap(&x3,&x4);
		if(y3>y4)
		  swap(&y3,&y4);         //将长方形的对角线坐标统一为：左下方和右上方
		if(x3<x2 && y3<y2 && x1<x4 && y1<y4)     //两个长方形相交（或者包含）的条件： 第3个点在第2个点的左下方；第1个点在第4个点的左下方      可画图先将一个长方形固定，然后将另一个长方形旋转，即可发现规律 
	    {
	    	a=(x1>x3)?x1:x3;
			c=(y1>y3)?y1:y3;    //观察图形可知，（a,c）这个坐标是在第1个点和第3个点中取横纵坐标大的值 
			b=(x2<x4)?x2:x4;
			d=(y2<y4)?y2:y4;    //观察图形可知，（b,d）这个坐标是在第2个点和第4个点中取横纵坐标大的值 
			printf("%.2lf\n",(b-a)*(d-c));
		}
		else
		    printf("0.00\n");
	}
	return 0;
}
