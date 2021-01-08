#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long int LL;
void dp(int cards[],int n,LL prefixsum[],LL d[][102],LL f[][102],LL g[][102])
{
    for(int l=1;l<=n;l++)
    {
        for(int start=0;start+l-1<n;start++)
        {
            int end=start+l-1;
            LL m=0;
            if(start+1<=end)    m=min(m,f[start+1][end]);
            if(end-1>=start)    m=min(m,g[start][end-1]);
            d[start][end]=prefixsum[end]-prefixsum[start]+cards[start]-m;
            f[start][end]=g[start][end]=d[start][end];
            if(start+1<=end)    f[start][end]=min(f[start+1][end],d[start][end]);
            if(end-1>=start)    g[start][end]=min(g[start][end-1],d[start][end]);
        }
    }
}
int main()
{
    int n;
    int cards[102];
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        LL d[102][102];
        LL prefixsum[102]={},f[102][102],g[102][102];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&cards[i]);
            if(i>0) prefixsum[i]+=prefixsum[i-1];
            prefixsum[i]+=cards[i];
        }
        dp(cards,n,prefixsum,d,f,g);
        printf("%lld\n",2*d[0][n-1]-prefixsum[n-1]);
    }
}
