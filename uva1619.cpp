#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<stack>
using namespace std;
int main()
{
    int n;
    bool first=true;
    while(scanf("%d",&n)==1)
    {
        if(first==false)
            printf("\n");
        else
            first=false;
        int num[150000],left[150000],right[150000];
        long long int prefixsum[150000]={};
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            prefixsum[i]=prefixsum[i-1]+num[i];
        }
        stack< pair<int,int> > s;
        for(int i=1;i<=n;i++)
        {
            if(s.empty()||s.top().first<num[i])
            {
                left[i]=i;
            }
            while(s.empty()==0&&s.top().first>=num[i])
            {
                left[i]=s.top().second;
                s.pop();
            }
            pair<int,int> p(num[i],left[i]);
            s.push(p);
        }
        while(s.empty()==false)
            s.pop();
        for(int i=n;i>=1;i--)
        {
            if(s.empty()||s.top().first<num[i])
                right[i]=i;
            while(s.empty()==0&&s.top().first>=num[i])
            {
                right[i]=s.top().second;
                s.pop();
            }
            pair<int,int> p(num[i],right[i]);
            s.push(p);
        }
        long long int ans=num[0];
        int start=1,end=1;
        for(int i=1;i<=n;i++)
        {
            long long int tmp=(prefixsum[right[i]]-prefixsum[left[i]-1])*num[i];
            if(tmp>ans)
            {
                start=left[i];
                end=right[i];
                ans=tmp;
            }
        }
        printf("%lld\n%d %d\n",ans,start,end);
    }
}
