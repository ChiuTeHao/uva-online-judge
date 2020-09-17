#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        unsigned long long int a,b;
        int n;
        scanf("%llu%llu%d",&a,&b,&n);
        int last2=0,last1=1;
        set<pair<int,int> > s;
        int round=2;
        vector<int> v;
        v.push_back(last2%n);
        v.push_back(last1%n);
        for(int i=0;i<n*n;i++)
        {
            pair<int,int> p(last2%n,last1%n);
            if(s.count(p)==0)
            {
                s.insert(p);
                round++;
            }
            else
                break;
            int next=(last2+last1)%n;
            last2=last1;
            last1=next;
            v.push_back(next);
        }
        round-=2;
        /*
        printf("%d\n",round);
        for(int i=1;i<=round;i++)
            printf("%d ",v[i]);
        printf("\n");
        */
        long long int idx=1;
        //printf("first %lld %lld %lld\n",a,b,idx);
        while(b)
        {
            if(b%2)
                idx=(idx*(a%round))%round;
            a=((a%round)*(a%round))%round;
            b/=2;
        }
        idx%=round;
        if(idx==0)
            idx=round;
        printf("%d\n",v[idx]);
    }
}
