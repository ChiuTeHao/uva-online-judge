#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
    int stop=static_cast<int>(sqrt(n));
    for(int i=2;i<=stop;i++)
    {
        if(n%i==0)  return false;
    }
    return true;
}
int main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        kase++;
        printf("Case %d: ",kase);
        long long int ans=0;
        int num=n;
        if(n>1)
        {
            if(isPrime(n))   ans=static_cast<long long int>(n)+1;
            else
            for(int i=2;i<=num;i++)
            {
                int factor=1;
                while(num%i==0)
                {
                    factor*=i;
                    num/=i;
                    if(num%i)   ans+=factor;
                }
            }
            if(ans==n)  ans+=1;
            printf("%lld\n",ans);
        }
        else
            printf("2\n");
    }
}

