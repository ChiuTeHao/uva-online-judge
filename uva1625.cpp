#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int dp[5005][5005],c[5005][5005];
int main()
{
    int kase;
    scanf("%d",&kase);
    char str1[5005],str2[5005];
    while(kase--)
    {
        scanf(" %s %s",str1+1,str2+1);
        int pos1[26][2],pos2[26][2];
        int len1=strlen(str1+1),len2=strlen(str2+1);
        for(int i=0;i<26;i++)
        {
            pos1[i][0]=pos2[i][0]=6000;
            pos1[i][1]=pos2[i][1]=-1;
        }
        for(int i=1;i<=len1;i++)
        {
            int ch=str1[i]-'A';
            pos1[ch][0]=min(pos1[ch][0],i);
            pos1[ch][1]=i;
        }
        for(int i=1;i<=len2;i++)
        {
            int ch=str2[i]-'A';
            pos2[ch][0]=min(pos2[ch][0],i);
            pos2[ch][1]=i;
        }
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                dp[i][j]=1000000000;
                if(i==0&&j==0)
                {
                    dp[i][j]=0;
                    c[i][j]=0;
                }
                else
                {
                    if(i>0)
                    {
                        dp[i][j]=min(dp[i-1][j]+c[i-1][j],dp[i][j]);
                        c[i][j]=c[i-1][j];
                        int ch=str1[i]-'A';
                        if(pos1[ch][0]==i&&j<pos2[ch][0])   c[i][j]++;
                        if(pos1[ch][1]==i&&j>=pos2[ch][1])  c[i][j]--;
                    }
                    if(j>0)
                    {
                        dp[i][j]=min(dp[i][j-1]+c[i][j-1],dp[i][j]);
                        c[i][j]=c[i][j-1];
                        int ch=str2[j]-'A';
                        if(pos2[ch][0]==j&&i<pos1[ch][0])   c[i][j]++;
                        if(pos2[ch][1]==j&&i>=pos1[ch][1])  c[i][j]--;
                    }
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
