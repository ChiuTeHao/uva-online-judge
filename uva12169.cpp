#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const long long int MOD=10001;
bool check(long long int nums[],int n,long long int a,long long int b)
{
    long long int num=nums[0];
    for(int i=0;i<n;i++)
    {
        if(num!=nums[i])    return false;
        int tmp=(num*a+b)%10001;
        num=(tmp*a+b)%10001;
    }
    return true;
}
void exGCD(long long int a,long long int b,long long int &d,long long int &x,long long int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        d=a;
        return;
    }
    else
    {
        exGCD(b,a%b,d,y,x);
        y-=(a/b)*x;
        return;
    }
}
int main()
{
    int T;
    while(scanf("%d",&T)==1)
    {
        long long int nums[200],a,b;
        bool flag=false;
        for(int i=0;i<T;i++)
            scanf("%lld",&nums[i]);
        for(int i=0;i<=10000;i++)
        {
            long long int d,x,y;
            exGCD(10001,i+1,d,x,y);
            if( (i*i*nums[0]-nums[1])%d==0)
            {
                long long int pow=((nums[1]-i*i*nums[0]))/d;
                if(check(nums,T,static_cast<long long int>(i),(y*pow)%MOD))
                {
                    a=i;
                    b=(y*pow)%MOD;
                    break;
                }
                
            }
        }
        for(int i=0;i<T;i++)
        {
            printf("%lld\n",(nums[i]*a+b)%MOD);
        }
        
    }
}
