#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
class Edge
{
    public:
        int from,to,cap,flow;
        Edge(int src,int dest,int c);
};
Edge::Edge(int src,int dest,int c):from(src),to(dest),cap(c),flow(0)
{
}
class EdmondsCarp
{
    public:
        vector<vector<int> > G;
        vector<Edge> edges;
        vector<int> a,p;
        EdmondsCarp(int n);
        void addEdge(int src,int dest,int f);
        int maxflow(int s,int t);
        int nodeno,edgeno;
        const int INF;
};
int EdmondsCarp::maxflow(int s,int t)
{
    int Flow=0;
    for(;;)
    {
        fill(a.begin(),a.end(),0);
        a[s]=INF;
        queue<int> q;
        q.push(s);
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<G[node].size();i++)
            {
                Edge &e=edges[G[node][i]];
                if(!a[e.to]&&e.cap>e.flow)
                {
                    a[e.to]=min(a[e.from],e.cap-e.flow);
                    p[e.to]=G[node][i];
                    q.push(e.to);
                }
            }
            if(a[t])    break;
        }
        if(!a[t])   break;
        for(int i=t;i!=s;i=edges[p[i]].from)
        {
            edges[p[i]].flow+=a[t];
            edges[p[i]^1].flow-=a[t];
        }
        Flow+=a[t];
    }
    return Flow;
}
void EdmondsCarp::addEdge(int src,int dest,int f)
{
    Edge edge1(src,dest,f),edge2(dest,src,f);
    edges.push_back(edge1);
    edges.push_back(edge2);
    int m=static_cast<int>(edges.size());
    G[src].push_back(m-2);
    G[dest].push_back(m-1);
}
EdmondsCarp::EdmondsCarp(int n):nodeno(n),edgeno(0),INF(1000000000)
{
    G.clear();
    edges.clear();
    a.clear();
    p.clear();
    G.resize(nodeno+1);
    a.resize(nodeno+1);
    p.resize(nodeno+1);
}
int main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1)
    {
        if(!n)  break;
        EdmondsCarp edmondscarp(n);
        int s,t,edgeno;
        scanf("%d%d%d",&s,&t,&edgeno);
        int from,to,cap;
        for(int i=0;i<edgeno;i++)
        {
            scanf("%d%d%d",&from,&to,&cap);
            edmondscarp.addEdge(from,to,cap);
        }
        int maxflow=edmondscarp.maxflow(s,t);
        kase++;
        printf("Network %d\n",kase);
        printf("The bandwidth is %d.\n\n",maxflow);
    }
}
