#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int n,d,r;
    int morning[150],evening[150];
    while(scanf("%d%d%d",&n,&d,&r)==3)
    {
        if(!n&&!d&&!r) break;
        for(int i=0;i<n;i++)
            scanf("%d",&morning[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&evening[i]);
        sort(morning,morning+n);
        sort(evening,evening+n,greater<int>());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(morning[i]+evening[i]>d)
                ans+=(morning[i]+evening[i]-d)*r;
        }
        printf("%d\n",ans);
    }
}
