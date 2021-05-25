/*
                             0/1�������� 
��N����Ʒ��һ������ΪM�ı�������i����Ʒ�ķ�����c[i]����ֵ��w[i]����⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ����
���룺3        //��Ʒ���� 
      2 3 5    //��Ʒ���� 
      7 4 8    //��Ʒ�۸�
	  5        //��������M
�����11  
*/

#include <stdio.h>
#define max(x,y) (x)>(y)?x:y
typedef struct 
{
	int weight;
	int price;
}goods;

int main()
{
	int i,j;
	int N;
	int M;
	goods g[100];
	int d[100][100];              //d[i][m]   ��ʾ��������i����Ʒʱ��������ʣ������m.��m��ȡ1-5. ��ʱ������ֵ 
	
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&g[i].weight);
	for(i=1;i<=N;i++)
	    scanf("%d",&g[i].price);
	scanf("%d",&M);
	
    for(i=0;i<=M;i++)           //�ٽ�����
		d[0][i]=0;
	for(i=0;i<=N;i++)
		d[i][0]=0;

	for(i=1;i<=N;i++)           //��ѡ����Ʒ���� 
	{
		for(j=1;j<=M;j++)
		{
		    if(j>=g[i].weight)	
			    d[i][j]=max(d[i-1][j],d[i-1][j-g[i].weight]+g[i].price); 
	 /*������i����Ʒ������ѡ��Ż��߲���ʱ����Ե�i-1����Ʒ��״̬����Ӱ�죬������ѡ��ŵ�i����Ʒ��
       ��ôѡ���i-1����Ʒʱ�ı���ʣ������������j,����Ϊ��j-g[i].weight��Ȼ������j-g[i].weight�Ƕ��٣�
	   ��ȡֵֻ������1--5֮�䣬�������Χ�ڵ���������Ѿ����������ά���鱣�档 
	*/     else
	            d[i][j]=d[i-1][j];
		}
	}
	printf("%d\n",d[N][M]);
	return 0;
} 
 
