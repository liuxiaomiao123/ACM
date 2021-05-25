/*����n������{A1,A2...An},����Ai��Ai+1�ǿɳ˵�,i=1,2...n-1,���ȷ���������˵ļ������ʹ�ó˻���������*/

#include <stdio.h>
#include <limits.h>

int main()
{
	int p[]={30,35,15,5,10,20,25};
	int M[100][100];  
	int n,i,j,R,k;
	int min;
	int t;
	n=6;
	for(i=0;i<n;i++)
		M[i][i]=0;
	for(R=2;R<=n;R++)
	{
		for(i=0;i<=n-R;i++)
		{
			j=i+R-1;
			min=INT_MAX;
			for(k=i;k<j;k++)
			{
				t=M[i][k]+M[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(t<min)
					min=t;
			}
			M[i][j]=min;
		}
	}
	printf("%d\n",M[0][n-1]);
	return 0;
}