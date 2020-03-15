#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
const int SIZE=(1E6)+5;
int ceil[SIZE],floor[SIZE],water[SIZE];
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        
        int n;
        scanf("%d",&n);
        memset(ceil,0,sizeof(ceil));
        memset(floor,0,sizeof(floor));
        memset(water,0,sizeof(water));
        for(int i=0;i<n;i++)
            scanf("%d",&floor[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&ceil[i]);
        int level=ceil[0];
        for(int i=0;i<n;i++)
        {
            if(level>ceil[i])
                level=ceil[i];
            if(level<floor[i])
                level=floor[i];
            water[i]=level;
        }
        level=ceil[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(level>ceil[i])
                level=ceil[i];
            if(level<floor[i])
                level=floor[i];
            water[i]=min(water[i],level);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=water[i]-floor[i];
        printf("%d\n",ans);
    }
}
