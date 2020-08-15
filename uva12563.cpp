#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
    int n,T;
    int song[50];
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        scanf("%d%d",&n,&T);
        int sum=0;
        int dp1[50][9001],dp2[50][9001];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&song[i]);
            sum+=song[i];
        }
        if(sum<T)
            printf("Case %d: %d %d\n",t,n+1,sum+678);
        else
        {
            for(int i=0;i<=T;i++)
            {
                if(i>song[0])
                {
                    dp1[0][i]=1;
                    dp2[0][i]=song[0];
                }
                else
                    dp1[0][i]=dp2[0][i]=0;
            }
            
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<=T;j++)
                {
                    if(j<=song[i])
                    {
                        dp1[i][j]=dp1[i-1][j];
                        dp2[i][j]=dp2[i-1][j];
                    }
                    else
                    {
                        if(dp1[i-1][j]<dp1[i-1][j-song[i]]+1)
                        {
                            dp1[i][j]=dp1[i-1][j-song[i]]+1;
                            dp2[i][j]=dp2[i-1][j-song[i]]+song[i];
                        }
                        else if(dp1[i-1][j]>dp1[i-1][j-song[i]]+1)
                        {
                            dp1[i][j]=dp1[i-1][j];
                            dp2[i][j]=dp2[i-1][j];
                        }
                        else
                        {
                            dp1[i][j]=dp1[i-1][j];
                            dp2[i][j]=max(dp2[i-1][j],dp2[i-1][j-song[i]]+song[i]);
                        }
                    }
                }
            }
            printf("Case %d: %d %d\n",t,dp1[n-1][T]+1,dp2[n-1][T]+678);
        }
        
    }
}
