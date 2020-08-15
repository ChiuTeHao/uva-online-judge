#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int len,n,places[51];
    while(scanf("%d",&len)==1)
    {
        if(len==0)   break;
        int cost[51][51]={};
        scanf("%d",&n);
        places[0]=0;
        places[n+1]=len;
        for(int i=1;i<=n;i++)
            scanf("%d",&places[i]);
        for(int j=2;j<=n+1;j++)
        {
            for(int i=0;i+j<=n+1;i++)
            {
                cost[i][i+j]=1e9;
                for(int k=i+1;k<i+j;k++)
                {
                    cost[i][i+j]=min(cost[i][i+j],cost[i][k]+cost[k][i+j]+places[i+j]-places[i]);
                }
            }
        }
        /*
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=n+1;j++)
                printf("%4d ",cost[i][j]);
            printf("\n");
        }
        */
        printf("The minimum cutting is %d.\n",cost[0][n+1]);
    }
}
