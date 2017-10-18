#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int Max_Edge=2500;
const int Max_Node=1500;
struct Edge
{
    int from,to,weight;
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int dis[Max_Node],n,m;
        Edge edge[Max_Edge];
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) dis[i]=100000000;
        dis[0]=0;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].weight);
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[edge[j].to]=min(dis[edge[j].to],dis[edge[j].from]+edge[j].weight);
            }
        }
        bool ans=false;
        for(int i=0;i<m;i++)
        {
            if(dis[edge[i].to]>dis[edge[i].from]+edge[i].weight)
            {
                ans=true;
            }
        }
        if(ans) printf("possible\n");
        else printf("not possible\n");
    }
}
