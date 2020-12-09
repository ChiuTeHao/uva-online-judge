#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m)  break;
        int dragon[20002],knight[20002];
        for(int i=0;i<n;i++)
            scanf("%d",&dragon[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&knight[i]);
        if(n>m)
            printf("Loowater is doomed!\n");
        else
        {
            sort(dragon,dragon+n);
            sort(knight,knight+m);
            long long int ans=0;
            int ptr=0;
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                while(ptr<m&&dragon[i]>knight[ptr]) ptr++;
                if(ptr==m)
                {
                    flag=false;
                    break;
                }
                else    ans+=knight[ptr++];
            }
            if(flag)    printf("%lld\n",ans);
            else    printf("Loowater is doomed!\n");
        }
        
    }
}
