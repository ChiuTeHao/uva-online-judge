#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n,m,num[100000];
    while(scanf("%d%d",&n,&m)==2)
    {
        int sum=0,ptr=-1,ans=n+1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
            while(ptr<i&&sum-num[ptr+1]>=m)
            {
                sum-=num[ptr+1];
                ptr++;
            }
            if(sum>=m)  ans=min(ans,i-ptr);
        }
        if(ans==n+1)    ans=0;
        printf("%d\n",ans);
    }
}
