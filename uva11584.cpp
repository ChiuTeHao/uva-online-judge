#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        char str[1001];
        scanf(" %s",str);
        int len=strlen(str);
        bool p[1001][1001]={};
        for(int k=1;k<=len;k++)
        {
            for(int i=0;i<len;i++)
            {
                if(i+k-1>=len) break;
                if(str[i]!=str[i+k-1]) p[i][i+k-1]=false;
                else
                {
                    if(i+1>i+k-2) p[i][i+k-1]=true;
                    else p[i][i+k-1]=p[i+1][i+k-2];
                }
            }
        }
        int dp[1001]={};
        for(int i=0;i<len;i++)
        {
            dp[i]=len+1;
            for(int j=0;j<=i;j++)
            {
                if(p[j][i]==true)
                {
                    int before;
                    if(j-1>=0) before=dp[j-1];
                    else before=0;
                    dp[i]=min(dp[i],before+1);
                }
            }
        }
        printf("%d\n",dp[len-1]);
    }
}
