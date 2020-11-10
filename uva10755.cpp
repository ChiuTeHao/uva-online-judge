#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxn=20;
int main()
{
    long long int num[maxn+1][maxn+1][maxn+1]={},sum[maxn+1][maxn+1][maxn+1]={};
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        for(int i=1;i<=A;i++)
        {
            for(int j=1;j<=B;j++)
            {
                long long int heightsum=0;
                for(int k=1;k<=C;k++)
                {
                    scanf("%lld",&num[i][j][k]);
                    sum[i][j][k]=num[i][j][k]+heightsum+sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
                    heightsum+=num[i][j][k];
                }
            }
        }
        long long int ans=num[1][1][1];
        for(int row2=1;row2<=A;row2++)
        {
            for(int row1=1;row1<=row2;row1++)
            {
                for(int col2=1;col2<=B;col2++)
                {
                    for(int col1=1;col1<=col2;col1++)
                    {
                        long long int minsum=0;
                        for(int h=1;h<=C;h++)
                        {
                            long long int s=sum[row2][col2][h]-sum[row2][col1-1][h]-sum[row1-1][col2][h]+sum[row1-1][col1-1][h];
                            ans=max(ans,s-minsum);
                            minsum=min(minsum,s);
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
        if(kase)    printf("\n");
    }
}
