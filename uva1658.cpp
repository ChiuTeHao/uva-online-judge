#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long int LL;
class Edge
{
    public:
        int from,to,cap,flow,cost;
        Edge(int from_,int to_,int cap_,int cost_);
};
Edge::Edge(int from_,int to_,int cap_,int cost_):from(from_),to(to_),cap(cap_),cost(cost_),flow(0)
{
}
class MCMF
{
    public:
        vector<Edge> edges;
        vector<vector<int> > G;
        MCMF(int nodeno);
        void addEdge(int src,int dest,int cap,int cost);
        bool BellmanFord(int s,int t,int &flow,LL &cost);
        int n,m;
        const int INF;
};
MCMF::MCMF(int nodeno):n(nodeno),INF(1000000000)
{
    edges.clear();
    G.clear();
    G.resize(n+n-1);
    for(int i=2;i<n;i++)
        addEdge(i,n+i-1,1,0);
}
bool MCMF::BellmanFord(int s,int t,int &maxflow,LL &cost)
{
    vector<int> p(2*n-1);
    vector<int> a(n*2-1);
    vector<int> d(n*2-1);
    vector<bool> inq(n*2-1);
    queue<int> q;
    for(int i=1;i<=n+n-2;i++)
        d[i]=INF;
    q.push(s);
    inq[s]=true;
    p[s]=-1;
    a[s]=1;
    d[s]=0;
    while(q.empty()==false)
    {
        int node=q.front();
        q.pop();
        inq[node]=false;
        for(int i=0;i<G[node].size();i++)
        {
            Edge &e=edges[G[node][i]];
            if(e.cap>e.flow&&d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                a[e.to]=min(a[e.from],e.cap-e.flow);
                p[e.to]=G[node][i];
                if(inq[e.to]==false)
                {
                    inq[e.to]=true;
                    q.push(e.to);
                }
            }
        }
    }
    if(d[t]==INF) return false;
    maxflow+=a[t];
    cost+=static_cast<LL>(d[t])*a[t];
    for(int node=t;node!=s;node=edges[p[node]].from)
    {
        edges[p[node]].flow+=a[t];
        edges[p[node]^1].flow-=a[t];
    }
    return true;
}
void MCMF::addEdge(int src,int dest,int cap,int cost)
{
    Edge edge1(src,dest,cap,cost),edge2(dest,src,0,-1*cost);
    edges.push_back(edge1);
    G[src].push_back(static_cast<int>(edges.size()-1));
    edges.push_back(edge2);
    G[dest].push_back(static_cast<int>(edges.size()-1));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        MCMF mcmf(n);
        for(int i=0;i<m;i++)
        {
            int src,dest,c;
            scanf("%d%d%d",&src,&dest,&c);
            if(src>1&&src<n)    src+=n-1;
            mcmf.addEdge(src,dest,1,c);
        }
        int flow=0;
        LL cost=0;
        mcmf.BellmanFord(1,n,flow,cost);
        mcmf.BellmanFord(1,n,flow,cost);
        printf("%lld\n",cost);
    }
}
