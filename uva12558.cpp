#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long int LL;
LL ans[1000],path[1000];
int ban[1000],bancnt;
bool better(int depth)
{
    for(int i=depth;i>=0;i--)
    {
        if(ans[i]==-1) return true;
        if(ans[i]>path[i])
            return true;
        if(ans[i]<path[i])
            return false;
    }
    return false;
}
bool banned(int num)
{
    for(int i=0;i<bancnt;i++)
    {
        if(ban[i]==num) return true;
    }
    return false;
}
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}
void sub(LL &a,LL &b,LL c,LL d)
{
    a=a*d-b*c;
    b=b*d;
    LL div=gcd(a,b);
    a/=div;
    b/=div;
}
bool bigger(LL a,LL b,LL c,LL d)
{
    return a*d>b*c;
}
bool noless(LL a,LL b,LL c,LL d)
{
    return a*d>=b*c;
}
LL getfirst(LL a,LL b)
{
    for(int i=1;;i++)
    {
        if(a*i>=b)
            return i;
    }
}
bool DFS(int depth,int maxdepth,LL from,LL a,LL b)
{
    if(depth==maxdepth)
    {
        if(b%a) return false;
        else if(banned(b)||b<from) return false;
        else path[depth]=b;
        if(better(maxdepth))
        {
            for(int i=0;i<=maxdepth;i++)
            {
                ans[i]=path[i];
            }
            return true;
        }
        return false;
    }
    int start=max(from,getfirst(a,b));
    bool findans=false;
    for(int i=start;;i++)
    {
        if(noless(maxdepth+1-depth,i,a,b)==false)
            break;
        if(banned(i)) continue;
        LL tmpa=a,tmpb=b;
        sub(tmpa,tmpb,1LL,i);
        path[depth]=i;
        if(DFS(depth+1,maxdepth,i+1,tmpa,tmpb))
            findans=true;
    }
    return findans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        LL a,b;
        scanf("%lld%lld%d",&a,&b,&bancnt);
        for(int i=0;i<bancnt;i++)
            scanf("%d",&ban[i]);
        int anscnt=0;
        for(int i=1;;i++)
        {
            for(int j=0;j<=i;j++)
                ans[i]=-1;
            if(DFS(0,i,1LL,a,b))
            {
                anscnt=i;
                break;
            }
        }
        printf("Case %d: %lld/%lld=",kase,a,b);
        for(int i=0;i<=anscnt;i++)
        {
            if(i) printf("+");
            printf("1/%d",ans[i]);
        }
        printf("\n");
    }
}
