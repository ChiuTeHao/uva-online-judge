#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector< vector<int> > &child,int nodeid,int threshold)
{
    if(child[nodeid].size()==0) return 1;
    vector<int> d;
    int childcnt=static_cast<int>(child[nodeid].size());
    for(int i=0;i<childcnt;i++)
        d.push_back(solve(child,child[nodeid][i],threshold));
    int need=childcnt*threshold/100+((childcnt*threshold%100)>0);
    sort(d.begin(),d.end());
    int ans=0;
    for(int i=0;i<need;i++)
        ans+=d[i];
    return ans;
}
int main()
{
    int n,T;
    while(scanf("%d%d",&n,&T)==2)
    {
        if(n==0&&T==0) return 0;
        vector< vector<int> > child;
        child.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            int parent;
            scanf("%d",&parent);
            child[parent].push_back(i);
        }
        printf("%d\n",solve(child,0,T));
    }
}
