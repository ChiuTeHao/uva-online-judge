#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
const int MAXN=102;
using namespace std;
enum Color{Red=0,Blue=1};
bool DFS(int node,int color,int nodeno,int graph[][MAXN],int nodecolor[],int &diff,int ccid[],int ccno);
void DP(int dp[][2*MAXN+1],int cc,int n,int diff[]);
void print(int ans,int dp[][2*MAXN+1],int cc,int ccid[],int n,int nodecolor[],int diff[]);
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=0;t<kase;t++)
    {
        int graph[MAXN][MAXN]={};
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            set<int> s;
            for(int j=0; ;j++)
            {
                int node;
                scanf("%d",&node);
                if(node==0) break;
                s.insert(node);
            }
            for(int j=1;j<=n;j++)
            {
                if(s.count(j)==0)
                    graph[i][j]=graph[j][i]=1;
            }
        }
        int nodecolor[MAXN],cc=0,diff[MAXN]={},ccid[MAXN]={};
        memset(nodecolor,-1,sizeof(nodecolor));
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(nodecolor[i]==-1)
            {
                if(!DFS(i,Red,n,graph,nodecolor,diff[cc],ccid,cc+1))
                {
                    printf("No solution");
                    flag=false;
                    break;
                }
                else
                    cc+=1;
            }
        }
        if(flag)
        {
            int dp[MAXN][2*MAXN+1]={};
            DP(dp,cc,n,diff);
            for(int i=0;i<=n;i++)
            {
                if(dp[cc][i+n]==1){   print(i,dp,cc,ccid,n,nodecolor,diff);break;}
                if(dp[cc][-i+n]==1){  print(-i,dp,cc,ccid,n,nodecolor,diff);break;}
            }
        }
        printf("\n");
        if(t<kase-1)  printf("\n");
    }
    
}
void DP(int dp[][2*MAXN+1],int cc,int n,int diff[])
{
    dp[0][0+n]=1;
    for(int i=1;i<=cc;i++)
    {
        for(int j=-n;j<=n;j++)
        {
            if(dp[i-1][j+n]==1)
            {
                dp[i][j+diff[i-1]+n]=1;
                dp[i][j-diff[i-1]+n]=1;
            }
        }
    }
}
bool DFS(int node,int color,int nodeno,int graph[][MAXN],int nodecolor[],int &diff,int ccid[],int ccno)
{
    nodecolor[node]=color;
    ccid[node]=ccno;
    if(color==Red)  diff+=1;
    else diff-=1;
    for(int j=1;j<=nodeno;j++)
    {
        if(node!=j && graph[node][j]==1)
        {
            if(nodecolor[j]==-1&&DFS(j,1-color,nodeno,graph,nodecolor,diff,ccid,ccno)==false)
            {
                return false;
            }
            if(nodecolor[j]==nodecolor[node])
            {
                return false;
            }
        }
    }
    return true;
}
void print(int ans,int dp[][2*MAXN+1],int cc,int ccid[],int n,int nodecolor[],int diff[])
{
    vector<int> team1,team2;
    for(int i=cc;i>0;i--)
    {
        int group1color;
        if(dp[i-1][ans+diff[i-1]+n]==1)   {group1color=Blue;ans+=diff[i-1];}
        else{group1color=Red;ans-=diff[i-1];}
        for(int j=1;j<=n;j++)
        {
            if(ccid[j]==i&&nodecolor[j]==group1color)
            {
                team1.push_back(j);
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(ccid[j]==i&&nodecolor[j]==1-group1color)
            {
                team2.push_back(j);
            }
        }
        
    }
    sort(team1.begin(),team1.end());
    sort(team2.begin(),team2.end());
    printf("%d",(int)team1.size());
    for(int i=0;i<team1.size();i++)
        printf(" %d",team1[i]);
    printf("\n");
    printf("%d",(int)team2.size());
    for(int i=0;i<team2.size();i++)
        printf(" %d",team2[i]);
}
