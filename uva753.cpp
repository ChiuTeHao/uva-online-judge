#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Edge
{
    public:
        int from,to,cap,flow;
        Edge(int from_,int to_,int cap_):from(from_),to(to_),cap(cap_),flow(0){}
};
class EdmondsCarp
{
    public:
        vector<vector<int> > G;
        vector<Edge> edges;
        int maxflow;
        int n,m;
        const int INF;
        EdmondsCarp(int nodeno,int edgecnt=0):n(nodeno),m(edgecnt),INF(1000000000),maxflow(0)
        {
            G.clear();
            G.resize(nodeno);
            edges.clear();
        }
        void addEdge(int src,int dest,int c)
        {
            Edge edge1(src,dest,c),edge2(dest,src,0);
            edges.push_back(edge1);
            edges.push_back(edge2);
            int m=edges.size();
            G[src].push_back(m-2);
            G[dest].push_back(m-1);
        }
        int maxFlow(int s,int t)
        {
            maxflow=0;
            for(;;)
            {
                vector<int> a(n),p(n);
                queue<int> q;
                q.push(s);
                a[s]=INF;
                while(q.empty()==false)
                {
                    int node=q.front();
                    q.pop();
                    //cout<<"node "<<node<<endl;
                    for(int i=0;i<G[node].size();i++)
                    {
                        Edge &e=edges[G[node][i]];
                        
                        if(a[e.to]==0&&e.cap>e.flow)
                        {
                            //cout<<e.from<<" "<<e.to<<" "<<e.cap<<" "<<e.flow<<endl;
                            a[e.to]=min(a[e.from],e.cap-e.flow);
                            p[e.to]=G[node][i];
                            q.push(e.to);
                        }
                    }
                    if(a[t])    break;
                }
                //cout<<endl;
                if(a[t]==0) break;
                //cout<<"maxflow "<<maxflow<<endl;
                maxflow+=a[t];
                for(int node=t;node!=s;node=edges[p[node]].from)
                {
                    edges[p[node]].flow+=a[t];
                    edges[p[node]^1].flow-=a[t];
                }
            }
            return maxflow;
        }
};
int getTypeID(map<string,int> &typeID,string name)
{
    int id;
    if(typeID.count(name)==0)
    {
        id=typeID.size();
        typeID[name]=id;
    }
    else
        id=typeID[name];
    return id;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        int reccnt;
        scanf("%d",&reccnt);
        map<string,int> typeID;
        int recarr[120];
        for(int i=0;i<reccnt;i++)
        {
            char str[50];
            scanf(" %s",str);
            string type(str);
            int id=getTypeID(typeID,type); 
            recarr[i]=id;
        }
        int appcnt,apparr[120];
        scanf("%d",&appcnt);
        for(int i=0;i<appcnt;i++)
        {
            char str[50];
            scanf(" %s",str);
            scanf(" %s",str);
            string type(str);
            int id=getTypeID(typeID,type);
            apparr[i]=id;
        }
        int u[120],v[120],adaptercnt;
        scanf("%d",&adaptercnt);
        for(int i=0;i<adaptercnt;i++)
        {
            char from[50],to[50];
            scanf(" %s %s",from,to);
            string src(from),dest(to);
            int srcid=getTypeID(typeID,src),destid=getTypeID(typeID,dest);
            u[i]=srcid;
            v[i]=destid;
        }
        int typecnt=typeID.size();
        vector<vector<int> > connect(typecnt,vector<int>(typecnt) );
        for(int i=0;i<adaptercnt;i++)
            connect[u[i]][v[i]]=1;
        for(int i=0;i<typecnt;i++)
            connect[i][i]=1;
        for(int k=0;k<typecnt;k++)
        {
            for(int i=0;i<typecnt;i++)
            {
                for(int j=0;j<typecnt;j++)
                {
                    if(connect[i][k]&&connect[k][j])
                        connect[i][j]=1;
                }
            }
        }
        /*
        for(map<string,int>::iterator it=typeID.begin();it!=typeID.end();it++)
            cout<<it->first<<" "<<it->second<<endl;
        */
        EdmondsCarp carp(appcnt+reccnt+2);
        for(int i=0;i<appcnt;i++)
            carp.addEdge(0,i+1,1);
        for(int i=0;i<reccnt;i++)
            carp.addEdge(appcnt+1+i,appcnt+reccnt+1,1);
        for(int i=0;i<appcnt;i++)
        {
            for(int j=0;j<reccnt;j++)
            {
                int rectype=recarr[j],apptype=apparr[i];
                if(connect[apptype][rectype])
                {
                    carp.addEdge(i+1,appcnt+1+j,carp.INF);
                }
            }
        }
        if(t>1)  printf("\n");
        printf("%d\n",appcnt-carp.maxFlow(0,appcnt+reccnt+1));
    }
}
