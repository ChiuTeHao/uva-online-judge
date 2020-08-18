#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;
const int MAXCOMPUTER=10000;
void DFS(int node,vector< vector<int> > &edge,int dp[][3])
{
    int n=static_cast<int>(edge[node].size());
    dp[node][1]=0;
    dp[node][0]=1;
    vector<int> child;
    for(int i=0;i<n;i++)
    {
        int childid=edge[node][i];
        if(dp[childid][0]==-1)
        {
            DFS(childid,edge,dp);    
            dp[node][0]+=min(dp[childid][0],dp[childid][1]);
            dp[node][1]+=dp[childid][2];
            child.push_back(edge[node][i]);
        }
    }
    int childcnt=static_cast<int>(child.size());
    if(childcnt==0)
    {
        dp[node][2]=20000;
    }
    else
    {
        
        dp[node][2]=dp[node][1]-dp[child[0]][2]+dp[child[0]][0];
        for(int i=1;i<childcnt;i++)
        {
            dp[node][2]=min(dp[node][2],dp[node][1]-dp[child[i]][2]+dp[child[i]][0]);
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector< vector<int> > edge;
        edge.resize(n+1);
        int node1,node2;
        //bool visit[MAXCOMPUTER+1]={};
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&node1,&node2);
            edge[node1].push_back(node2);
            edge[node2].push_back(node1);            
        }
        int tmp;
        scanf("%d",&tmp);
        int dp[MAXCOMPUTER+1][3]={};
        memset(dp,-1,sizeof(dp));
        DFS(1,edge,dp);
        int ans=min(dp[1][0],dp[1][2]);
        /*
        for(int i=1;i<=n;i++)
        {
            printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
        }
        */
        printf("%d\n",ans);
        if(tmp==-1) break;
    }
}
