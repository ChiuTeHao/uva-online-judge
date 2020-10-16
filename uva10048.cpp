#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int MAXVAL=30000;
int main()
{
    int C,S,Q,kase=0;
    while( scanf("%d%d%d",&C,&S,&Q) == 3 )
    {
        if(!C&&!S&&!Q)  break;
        kase++;
        int graph[105][105]={};
        for(int i=1;i<=C;i++)
            for(int j=1;j<=C;j++)
                graph[i][j]=MAXVAL;
        for(int i=0;i<S;i++)
        {
            int from,to,weight;
            scanf("%d%d%d",&from,&to,&weight);
            graph[from][to]=graph[to][from]=weight;
        }
        for(int k=1;k<=C;k++)
        {
            for(int i=1;i<=C;i++)
            {
                for(int j=1;j<=C;j++)
                {
                    if(graph[i][k]<MAXVAL&&graph[k][j]<MAXVAL)
                        graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]) );
                }
            }
        }
        if(kase>1)  printf("\n");
        printf("Case #%d\n",kase);
        for(int i=0;i<Q;i++)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            if(graph[from][to]<MAXVAL)
                printf("%d\n",graph[from][to]);
            else
                printf("no path\n");
        }
    }
}
