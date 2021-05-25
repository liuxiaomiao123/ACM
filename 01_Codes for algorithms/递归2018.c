#include <stdio.h>
int main()
{
    int n,i;
    int a[55]={1,2,3,4};
    while(scanf("%d",&n) != EOF && n)
    {
        for(i=4;i<n;i++)
        {
            a[i]=a[i-1]+a[i-3];
        }
        printf("%d\n",a[n-1]);
    }
    return 0;
}