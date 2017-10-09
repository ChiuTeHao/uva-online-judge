#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct Case
{
    int id,day,fine;
    bool operator<(const Case &rhs)const
    {
        if(rhs.day*fine!=day*rhs.fine)
            return rhs.day*fine>day*rhs.fine;
        else
            return id<rhs.id;
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        if(k>1) printf("\n");
        int n;
        scanf("%d",&n);
        Case kase[1500];
        for(int i=0;i<n;i++)
        {
            kase[i].id=i+1;
            scanf("%d%d",&kase[i].day,&kase[i].fine);
        }
        sort(kase,kase+n);
        for(int i=0;i<n;i++)
        {
            printf("%d",kase[i]);
            if(i<n-1) printf(" ");
        }
        printf("\n");
    }
}
