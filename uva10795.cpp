#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long int LL;
LL f(int start[],int idx,int finish)
{
    LL ans=0;
    if(idx<=0)   return ans;
    else if(start[idx]==finish) return f(start,idx-1,finish);
    else return f(start,idx-1,6-start[idx]-finish)+(1LL<<(idx-1));
}
int main()
{
    int k;
    int start[70],finish[70],kase=0;
    while(scanf("%d",&k)==1)
    {
        if(k==0)    break;
        kase++;
        for(int i=1;i<=k;i++)
            scanf("%d",&start[i]);
        for(int i=1;i<=k;i++)
            scanf("%d",&finish[i]);
        int diff=0;
        for(int i=k;i>0;i--)
        {
            if(start[i]!=finish[i])
            {
                diff=i;
                break;
            }
        }
        LL ans=0;
        if(diff>0)
        {
            ans=f(start,diff-1,6-finish[diff]-start[diff]);
            ans+=(1+f(finish,diff-1,6-finish[diff]-start[diff]) );
        }
        printf("Case %d: %lld\n",kase,ans);
    }
}
