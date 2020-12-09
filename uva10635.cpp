#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        map<int,int> table;
        int n,p,q;
        int num;
        scanf("%d%d%d",&n,&p,&q);
        for(int i=1;i<=p+1;i++)
        {
            scanf("%d",&num);
            table[num]=i;
        }
        int arr[70000],LIS[70000];
        for(int i=0;i<q+1;i++)
        {
            scanf("%d",&num);
            LIS[i+1]=n*n+5;
            if(table.count(num))
                arr[i]=table[num];
            else
                arr[i]=0;
        }
        int ans=0,idx;
        for(int i=0;i<q+1;i++)
        {
            idx=lower_bound(LIS+1,LIS+q+2,arr[i])-LIS;
            ans=max(ans,idx);
            LIS[idx]=arr[i];
        }
        printf("Case %d: %d\n",t,ans);
    }
}
