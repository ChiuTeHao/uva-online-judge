#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
int next(int n,int ndigit)
{
    long long int num=static_cast<long long int>(n);
    num*=num;
    stack<int> s;
    int cnt=ndigit;
    while(num)
    {
        s.push( static_cast<int>((num%10)) );
        num/=10;
        ndigit--;
    }
    while(ndigit>0)
    {
        s.push(0);
        ndigit--;
    }
    int res=0;
    for(int i=1;i<=cnt;i++)
    {
        res*=10;
        res+=s.top();
        s.pop();
    }
    return res;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int fast=k,slow=k,ans=k;
        do
        {
            slow=next(slow,n);
            fast=next(fast,n);
            if(fast>ans)    ans=fast;
            fast=next(fast,n);
            if(fast>ans)    ans=fast;
        }while(fast!=slow);
        printf("%d\n",ans);
    }
}
