#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int maxn=1000001;
typedef long long int LL;
LL c[maxn+10];
int main()
{
    int n;
    int num[maxn+10];
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        LL sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        LL m=sum/n;
        c[0]=0;
        for(int i=1;i<n;i++)
            c[i]=c[i-1]+num[i]-m;
        sort(c,c+n);
        LL x=c[n/2],ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(x-c[i]);
        printf("%lld\n",ans);
    }
}
