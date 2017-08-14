#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
void BFS(int graph[][101],bool visit[],int from,int node)
{
    queue<int> Q;
    Q.push(from);
    if(graph[from][from])
        visit[from]=true;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=1;i<=node;i+=1)
        {
            if(!visit[i]&&graph[now][i])
            {
                Q.push(i);
                visit[i]=true;
            }
        }
    }
    int unvisit=0;
    for(int i=1;i<=node;i+=1)
    {
        if(visit[i]==false)
            unvisit++;
    }
    printf("%d",unvisit);
    for(int i=1;i<=node;i+=1)
    {
        if(!visit[i])
            printf(" %d",i);
    }
    printf("\n");
}
int main()
{
    int node;
    while(cin>>node)
    {
        if(!node) break;
        int graph[101][101]={};
        int from,to;
        while(cin>>from)
        {
            if(!from) break;
            while(cin>>to)
            {
                if(!to) break;
                graph[from][to]=1;
            }
        }
        int query;
        cin>>query;
        for(int i=1;i<=query;i+=1)
        {
            cin>>from;
            bool visit[101]={};
            BFS(graph,visit,from,node);
        }
        //printf("fuck");
    }
}
