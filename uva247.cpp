#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <queue>
using namespace std;
int main()
{
    
    int n,m,kase=0;
    while( scanf("%d%d",&n,&m) == 2 )
    {
        if(n==0&&m==0)  break;
        kase++;
        map<string,int> nameid;
        map<int,string> idname;
        char name1[100],name2[100];
        int graph[30][30]={};
        for(int i=0;i<m;i++)
        {
            scanf(" %s %s",name1,name2);
            string str1(name1),str2(name2);
            int id1,id2;
            if(nameid.count(str1)==0)
            {
                id1=static_cast<int>(nameid.size());
                nameid[name1]=id1;
                idname[id1]=name1;
            }
            else    id1=nameid[name1];
            if(nameid.count(str2)==0)
            {
                id2=static_cast<int>(nameid.size());
                nameid[name2]=id2;
                idname[id2]=name2;
            }
            else    id2=nameid[name2];
            graph[id1][id2]=1;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    graph[i][j]=graph[i][j] || (graph[i][k]&&graph[k][j]);
        bool print[30]={};
        if(kase>1)  printf("\n");
        printf("Calling circles for data set %d:\n",kase);
        for(int i=0;i<n;i++)
        {
            if(print[i]==false)
            {
                printf("%s",idname[i].c_str());
                print[i]=true;
                for(int j=0;j<n;j++)
                {
                    if(graph[i][j]&&graph[j][i]&&print[j]==false)
                    {
                        printf(", %s",idname[j].c_str());
                        print[j]=true;
                    }
                }
                printf("\n");
            }
        }
    }
}
