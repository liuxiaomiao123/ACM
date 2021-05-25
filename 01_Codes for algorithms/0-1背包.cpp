/*
                             0/1背包问题 
有N件物品和一个质量为M的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。
输入：3        //物品个数 
      2 3 5    //物品质量 
      7 4 8    //物品价格
	  5        //背包质量M
输出：11  
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
	int d[100][100];              //d[i][m]   表示当来到第i个物品时，背包的剩余质量m.则m可取1-5. 此时的最大价值 
	
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&g[i].weight);
	for(i=1;i<=N;i++)
	    scanf("%d",&g[i].price);
	scanf("%d",&M);
	
    for(i=0;i<=M;i++)           //临界条件
		d[0][i]=0;
	for(i=0;i<=N;i++)
		d[i][0]=0;

	for(i=1;i<=N;i++)           //先选择物品！！ 
	{
		for(j=1;j<=M;j++)
		{
		    if(j>=g[i].weight)	
			    d[i][j]=max(d[i-1][j],d[i-1][j-g[i].weight]+g[i].price); 
	 /*来到第i个物品，当你选择放或者不放时，会对第i-1个物品的状态产生影响，比如你选择放第i个物品，
       那么选择第i-1个物品时的背包剩余质量不再是j,而变为了j-g[i].weight。然而不论j-g[i].weight是多少，
	   其取值只可能在1--5之间，而这个范围内的情况我们已经计算出并二维数组保存。 
	*/     else
	            d[i][j]=d[i-1][j];
		}
	}
	printf("%d\n",d[N][M]);
	return 0;
} 
 
