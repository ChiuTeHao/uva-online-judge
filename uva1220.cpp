#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>
#include<vector>
using namespace std;
int getIndex(map<string,int> &table,string &user)
{
    if(table.count(user)==0)
    {
        int idx=static_cast<int>(table.size());
        table[user]=idx;
    }
    return table[user];
}
void DFS(int node,vector<vector<int> > &child,vector<vector<int> > &come,vector<vector<int> > &only)
{
    int n=static_cast<int>(child[node].size());
    come[node].push_back(0);
    come[node].push_back(1);
    int flag1=1,flag2=1;
    for(int i=0;i<n;i++)
    {
        int childid=child[node][i];
        DFS(childid,child,come,only);
        come[node][1]+=come[childid][0];
        if(come[childid][0]>come[childid][1])
        {
            come[node][0]+=come[childid][0];
            flag1&=only[childid][0];
        }
        else if(come[childid][0]<come[childid][1])
        {
            come[node][0]+=come[childid][1];
            flag1&=only[childid][1];
        }
        else
        {
            come[node][0]+=come[childid][0];
            flag1&=0;
        }
        flag2&=only[childid][0];
    }
    only[node].push_back(flag1);
    only[node].push_back(flag2);
    return;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        map<string,int> table;
        char name1[101],name2[101];
        vector< vector<int> > child;
        vector< vector<int> > come,only;
        come.resize(n);
        /*
        for(int i=0;i<n;i++)
        {
            come[i].push_back(-1);
            come[i].push_back(-1);
        }
        */
        only.resize(n);
        child.resize(n);
        int bossidx;
        for(int i=0;i<n;i++)
        {
            scanf(" %s",name1);
            if(i>0)
            {
                scanf(" %s",name2);
                string user1(name1),user2(name2);
                int idx1=getIndex(table,user1),idx2=getIndex(table,user2);
                child[idx2].push_back(idx1);
            }
            else
            {
                string boss(name1);
                bossidx=getIndex(table,boss);
            }
        }
        DFS(bossidx,child,come,only);
        /*
        for(int i=0;i<n;i++)
        {
            printf("%d %d\n",come[i][0],come[i][1]);
            printf("%d %d\n",only[i][0],only[i][1]);
            printf("===============\n");
        }
        */
        if(come[bossidx][0]>come[bossidx][1])
        {
            printf("%d ",come[bossidx][0]);
            if(only[bossidx][0])    printf("Yes\n");
            else    printf("No\n");
        }
        else if(come[bossidx][0]<come[bossidx][1])
        {
            printf("%d ",come[bossidx][1]);
            if(only[bossidx][1])    printf("Yes\n");
            else    printf("No\n");
        }
        else
        {
            printf("%d No\n",come[bossidx][0]);
        }
    }
}
