#include <stdio.h>
#include <string.h>

/*�����Ŀֻ��������ʼ�㣬û�и����յ㣬��ô�յ������أ�Խ���ʱ������յ�����������ǲ��Եġ�
  ÿ����ɫ��ש����һ���ڵ㣬ÿ�ζ�Ҫ�������ڵĽ�㳢��һ�飬��ô����һ���ǻص�����㣬�������е�
  ��ɫ��ש���㱻���꣬�����ͼ�ı�������ģ��Ψһ��ͬ���ǣ�ģ��Ľ�㶼����֪�ģ�������Ҫ�ж�һ��
  �ĸ��������Ǻ�ɫ��㣬�������Ǹ�������Ǳ������ͬС��*/

char tile[25][25];    //ȫ�ֱ���Ҫע�� 
int visited[25][25];
int w,h;
int num;

void dfs(int i,int j)
{
	if(i<0 || i>=h || j<0 || j>=w)     //��ģ�岻ͬ��ģ����Ľ�㶼�Ǹ����ģ��������ĸ����ڽ��Ҫ�Լ��ж�
	    return;                        //ע��Խ����� 
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
		getchar();          //%c���ܹ���ȡ�ո�ͻس��� 
		num=0;             //numע������ 
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
			getchar();    ////%c���ܹ���ȡ�ո�ͻس��ģ��ʻ���ʱһ��Ҫע�� 
		}
		memset(visited,0,sizeof(visited));
		dfs(x,y);
		printf("%d\n",num);
	}
	return 0;
}
