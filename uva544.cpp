#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
struct Edge
{
    int to,weight;
    bool operator<(const Edge &rhs)const
    {
        if(weight!=rhs.weight) return weight<rhs.weight;
        else return to>rhs.to;
    }
    bool operator==(const Edge &rhs)const
    {
        return weight==rhs.weight&&to==rhs.to;
    }
    bool operator>(const Edge &rhs)const
    {
        return !(*(this)<rhs||*(this)==rhs);
    }
};
int Find_index(string str,map<string,int> &index)
{
    int n=index.size();
    if(index.count(str)==0)
        index[str]=n;
    else
        return index[str];
}
int Dij(int from,int to,int n,vector<Edge> edge[])
{
    int cargo[n]={};
    priority_queue<Edge,vector<Edge>,greater<Edge> >Q;
    cargo[from]=100000000;
    Edge first;
    first.to=from;
    first.weight=cargo[from];
    Q.push(first);
    while(!Q.empty())
    {
        Edge now=Q.top();
        Q.pop();
        for(int i=0;i<edge[now.to].size();i++)
        {
            int restrict=min(cargo[now.to],edge[now.to][i].weight);
            if(restrict>cargo[edge[now.to][i].to])
            {
                cargo[edge[now.to][i].to]=restrict;
                Edge tmp;
                tmp.to=edge[now.to][i].to;
                tmp.weight=restrict;
                Q.push(tmp);
            }
        }
    }
    return cargo[to];
}
int main()
{
    int n,m;
    int kase=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m) break;
        kase++;
        string city1,city2;
        vector<Edge> edge[300];
        map<string,int> city_index;
        for(int i=0;i<m;i++)
        {
            int w;
            cin>>city1>>city2>>w;
            int vertex1=Find_index(city1,city_index);
            int vertex2=Find_index(city2,city_index);
            Edge tmp1,tmp2;
            tmp1.to=vertex1;
            tmp1.weight=w;
            tmp2.to=vertex2;
            tmp2.weight=w;
            edge[vertex1].push_back(tmp2);
            edge[vertex2].push_back(tmp1);
        }
        cin>>city1>>city2;
        int vertex1=Find_index(city1,city_index);
        int vertex2=Find_index(city2,city_index);
        int ans=Dij(vertex1,vertex2,city_index.size(),edge);
        printf("Scenario #%d\n",kase);
        printf("%d tons\n",ans);
        printf("\n");
    }
}
