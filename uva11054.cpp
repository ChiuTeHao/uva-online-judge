#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        long long int last=0,ans=0;
        int alcohol;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&alcohol);
            ans+=abs(last);
            last+=alcohol;
        }
        printf("%lld\n",ans);
    }
}
