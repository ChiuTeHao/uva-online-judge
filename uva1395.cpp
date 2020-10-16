#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
class Edge
{
    public:
        int from,to,weight;
        bool operator<(const Edge &rhs)const
        {
            if(weight!=rhs.weight)  return weight<rhs.weight;
            else if(from!=rhs.from) return from<rhs.from;
            else    return to<rhs.to;
        }
};
int findSet(int s[],int node)
{
    if(s[node]==node)   return node;
    else
    {
        int x=findSet(s,s[node]);
        s[node]=x;
        return x;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)   break;
        int s[101],ans=0;
        Edge edge[10000];
        for(int i=1;i<=n;i++)
            s[i]=i;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].weight);
        }
        sort(edge,edge+m);
        ans=edge[m-1].weight-edge[0].weight+1;
        for(int i=0;i<m;i++)
        {
            int edgecnt=0,R=i;
            while(R<m)
            {
                if(findSet(s,edge[R].from)!=findSet(s,edge[R].to) )
                {
                    s[findSet(s,edge[R].to)]=findSet(s,edge[R].from);
                    edgecnt+=1;
                }
                if(edgecnt==n-1)    break;
                else    R++;
            }
            if(edgecnt==n-1)    ans=min(ans,edge[R].weight-edge[i].weight);
            for(int i=1;i<=n;i++)   s[i]=i;
        }
        if(ans==edge[m-1].weight-edge[0].weight+1)    printf("-1\n");
        else    printf("%d\n",ans);
    }
}
