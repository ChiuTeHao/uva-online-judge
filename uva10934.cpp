#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long int floor[101][64]={};
    for(int i=1;i<=64;i++)
        floor[1][i]=i;
    for(int i=1;i<=100;i++)
        floor[i][1]=1;
    for(int i=2;i<=100;i++)
        for(int j=2;j<=63;j++)
            floor[i][j]=floor[i-1][j-1]+1+floor[i][j-1];
    long long int k;
    long long int n;
    while(scanf("%lld%lld",&k,&n)==2)
    {
        long long int ans=-1;
        if(k==0)  break;
        for(int i=1;i<=63;i++)
        {
            if(floor[k][i]>=n)
            {
                ans=i;
                break;
            }
        }
        if(ans==-1)
            printf("More than 63 trials needed.\n");
        else
            printf("%lld\n",ans);
    }
}
