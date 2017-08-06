#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long int combination(int n,int k)
{
    long long int ans=1;
    for(int i=k+1;i<=n;i++)
    {
        ans*=i;
        ans/=(i-k);
    }
    return ans;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m) break;
        long long int ans;
        int tmp=n-m;
        if(n<tmp)
            ans=combination(n,m);
        else
            ans=combination(n,tmp);
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,ans);
    }
}
