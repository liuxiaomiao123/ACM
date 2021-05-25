#include <stdio.h>
int main()
{
    int wage,i,temp,n,sum,count;
    int a[6]={100,50,10,5,2,1};
    while(scanf("%d",&n) != EOF && n)
    {
        sum=0;
        while(n--)
        {
            scanf("%d",&wage);
            for(i=0;i<6;i++)
            {
                count=wage/a[i];
                temp=wage%a[i];
                sum+=count;
                if(temp==0)
                    break;
                wage=temp;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}