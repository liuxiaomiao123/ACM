#include <stdio.h>
#include <string.h>

/*这个题目只给出了起始点，没有给出终点，那么终点在哪呢？越界的时候就是终点吗？这样理解是不对的。
  每个黑色瓷砖代表一个节点，每次都要把其相邻的结点尝试一遍，那么最终一定是回到了起点，这样所有的
  黑色瓷砖才算被走完，这就是图的遍历。与模板唯一不同的是，模板的结点都是已知的，这里你要判断一下
  哪个方向上是黑色结点，才能走那个方向，与城堡问题大同小异*/

char tile[25][25];    //全局变量要注意 
int visited[25][25];
int w,h;
int num;

void dfs(int i,int j)
{
	if(i<0 || i>=h || j<0 || j>=w)     //与模板不同，模板里的结点都是给定的，这里走哪个相邻结点要自己判断
	    return;                        //注意越界情况 
	if(visited[i][j])
	   return;
	visited[i][j]=1;
	num++;
	if(tile[i][j-1]=='.')
	    dfs(i,j-1);
	if(tile[i+1][j]=='.')
	    dfs(i+1,j);
	if(tile[i][j+1]=='.')
	    dfs(i,j+1);
	if(tile[i-1][j]=='.')
	    dfs(i-1,j);
}

int main() 
{
	int i,j;
	int x,y;
	while(scanf("%d%d",&w,&h) != EOF && (w||h)) 
	{
		getchar();          //%c是能够读取空格和回车的 
		num=0;             //num注意清零 
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%c",&tile[i][j]);
				if(tile[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
			getchar();    ////%c是能够读取空格和回车的，故换行时一定要注意 
		}
		memset(visited,0,sizeof(visited));
		dfs(x,y);
		printf("%d\n",num);
	}
	return 0;
}
