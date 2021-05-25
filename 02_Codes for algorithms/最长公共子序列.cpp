#include <iostream>
using namespace std;

char s1[100];
char s2[100];
char record[100];
int maxlen[100][100];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	while(cin>>s1>>s2)
	{
		int length1=strlen(s1);
		int length2=strlen(s2);
		int i,j,k;
		for(i=0;i<=length1;i++)
			maxlen[i][0]=0;
		for(j=0;j<=length2;j++)
			maxlen[0][j]=0;
		for(i=1;i<=length1;i++)
		{
			for(j=1;j<=length2;j++)
			{
				if(s1[i-1]==s2[j-1])
					maxlen[i][j]=maxlen[i-1][j-1]+1;
				else
					maxlen[i][j]=max(maxlen[i][j-1],maxlen[i-1][j]);
			}
		}
		cout<<"最长公共子序列的长度为："<<maxlen[length1][length2]<<endl;
		k=0;
		i=length1;
		j=length2;
		while(i>=0 && j>=0)
		{
			if(s1[i-1]==s2[j-1])
			{
				record[k++]=s1[i-1];
				i--;
				j--;
			}
			else
			{
				if(maxlen[i][j]==maxlen[i-1][j])
					i--;
				else
					j--;

			}
		}
		cout<<"最长公共子序列的其中一种可能的情况：";
		for(i=k-1;i>=0;i--)
			cout<<record[i];
		cout<<endl;
	}
	return 0;
}
