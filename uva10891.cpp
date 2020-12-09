#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        long long int nums[200],prefixsum[200]={};
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&nums[i]);
            prefixsum[i]+=nums[i];
            if(i-1>=0)  prefixsum[i]+=prefixsum[i-1];
        }
        long long int dp[105][105]={};
        for(int l=1;l<=n;l++)
        {
            for(int start=0;start+l-1<n;start++)
            {
                int end=start+l-1;
                long long int sum=0,tmp,total;
                dp[start][end]=prefixsum[end]-prefixsum[start]+nums[start];
                for(int j=start;j<=end;j++)
                {
                    sum+=nums[j];
                    tmp=0;
                    if(j+1<=end)    tmp+=dp[j+1][end];
                    total=prefixsum[end];
                    total-=prefixsum[j];
                    tmp=total-tmp;
                    dp[start][end]=max(dp[start][end],sum+tmp);
                }
                sum=0;
                for(int j=end;j>=start;j--)
                {
                    sum+=nums[j];
                    tmp=0;
                    total=0;
                    if(j-1>=start)
                        tmp+=dp[start][j-1];
                    if(j-1>=start)
                        total=prefixsum[j-1]-prefixsum[start]+nums[start];
                    tmp=total-tmp;
                    dp[start][end]=max(dp[start][end],sum+tmp);
                }
            }
        }
        printf("%lld\n",2*dp[0][n-1]-prefixsum[n-1]);
    }
}
