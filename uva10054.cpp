#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
const int maxn=53;
class Edge
{
    public:
    int src,dest;
    Edge(int s,int d):src(s),dest(d){}
};
void DFS(vector<vector<int> > &G,vector<Edge> &edges,vector<bool> &visit,int node)
{
    if(node==-1)
    {
        visit[0]=true;
        DFS(G,edges,visit,edges[0].dest);
        cout<<edges[0].dest<<" "<<edges[0].src<<endl;
    }
    else
    {
        for(int i=0;i<G[node].size();i++)
        {
            int idx=G[node][i];
            if(visit[idx]==false)
            {
                visit[idx]=true;
                DFS(G,edges,visit,edges[idx].src+edges[idx].dest-node);
                cout<<edges[idx].src+edges[idx].dest-node<<" "<<node<<endl;
            }
        }
    }
}
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        vector<vector<int> > G(maxn);
        vector<Edge> edges;
        int beeds,cnt[maxn]={};
        scanf("%d",&beeds);
        vector<bool> visit(beeds);
        for(int i=0;i<beeds;i++)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            Edge edge(from,to);
            cnt[from]++;
            cnt[to]++;
            edges.push_back(edge);
            G[from].push_back(i);
            G[to].push_back(i);
        }
        bool flag=true;
        for(int i=1;i<=50;i++)
        {
            if(cnt[i]&1)
            {
                flag=false;
                break;
            }
        }
        printf("Case #%d\n",t);
        if(flag)
        {
            DFS(G,edges,visit,-1);
        }
        else
        {
            printf("some beads may be lost\n");
        }
        if(t<kase)
            printf("\n");
    }
}
