#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
const int MAXSUBJECT=8;
void getSubject(char subject[],int &teacher)
{
    int ptr=0,num=0,len=strlen(subject);
    while(ptr<len)
    {
        while(ptr<len&&isdigit(subject[ptr])==0)
            ptr++;
        while(ptr<len&&isdigit(subject[ptr]))
        {
            num*=10;
            num+=subject[ptr]-'0';
            ptr++;
        }
        if(num>0)
            teacher|=(1<<(num-1));
        num=0;
    }
}
int DP(int S,int M,int N,int* subject,int *salary,int dp[][1<<MAXSUBJECT][1<<MAXSUBJECT],int cur,int s0,int s1,int s2)
{
    if(cur==M+N)
    {
        if(s2==(1<<S)-1)    return 0;
        else return 1e7;
    }
    int &ans=dp[cur][s1][s2];
    if(ans>=0)   return ans;
    ans=1e7;
    if(cur>=M)  ans=min(ans,DP(S,M,N,subject,salary,dp,cur+1,s0,s1,s2));
    int m0=(subject[cur]&s0),m1=(subject[cur]&s1);
    s0^=m0;
    s1=(s1^m1)|(m0);
    s2=s2|m1;
    ans=min(ans,salary[cur]+DP(S,M,N,subject,salary,dp,cur+1,s0,s1,s2));
    return ans;
}
int dp[150][1<<MAXSUBJECT][1<<MAXSUBJECT]={};
int main()
{
    int S,M,N;
    while(scanf("%d%d%d",&S,&M,&N)==3)
    {
        if(S==0)    break;
        int subject[120],salary[120];
        memset(subject,0,sizeof(subject));
        for(int i=0;i<M+N;i++)
        {
            char str[1000];
            scanf("%d",&salary[i]);
            fgets(str,999,stdin);
            getSubject(str,subject[i]);
        }
        
        memset(dp,-1,sizeof(dp));
        DP(S,M,N,subject,salary,dp,0,(1<<S)-1,0,0);
        printf("%d\n",dp[0][0][0]);
    }
}
