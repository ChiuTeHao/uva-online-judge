#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n,k,m;
    while( scanf("%d%d%d",&n,&k,&m) == 3 )
    {
        if(n==0&&k==0&&m==0)    break;
        int ans[n+2];
        ans[1]=0;
        for(int i=2;i<=n;i++)
            ans[i]=(ans[i-1]+k)%i;
        ans[n]=(m-k+ans[n])%n;
        if(ans[n]<0)    ans[n]+=n;
        ans[n]+=1;
        printf("%d\n",ans[n]);
    }
}
