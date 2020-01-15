#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int cnt;
        scanf("%d",&cnt);
        int head=0,ans=0;
        map<int,int> table;
        for(int i=0;i<cnt;i++)
        {
            int id;
            scanf("%d",&id);
            if(table.count(id)!=0)
            {
                if(table[id]>=head)
                    head=table[id]+1;
                table[id]=i;
            }
            else
                table[id]=i;
            if(i-head+1>ans)
                ans=i-head+1;
        }
        printf("%d\n",ans);
    }
}
