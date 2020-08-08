#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int lakecnt,daycnt;
        scanf("%d%d",&lakecnt,&daycnt);
        vector<int> lastrain;
        vector<int> dragon;
        set<int> drinkday;
        lastrain.resize(lakecnt+1);
        for(int i=1;i<=lakecnt;i++)
            lastrain[i]=-1;
        dragon.resize(daycnt);
        bool flag=true;
        for(int i=0;i<daycnt;i++)
        {
            int lake;
            scanf("%d",&lake);
            if(flag==false)
                continue;
            if(lake==0)
                drinkday.insert(i);
            else
            {
                int target=lastrain[lake]+1;
                set<int>::iterator it=drinkday.lower_bound(target);
                if(it!=drinkday.end())
                {
                    dragon[*it]=lake;
                    dragon[i]=-1;
                    drinkday.erase(it);
                }
                else
                    flag=false;
                lastrain[lake]=i;
            }
        }
        
        if(flag)
        {
            printf("YES\n");
            bool first=true;
            for(int i=0;i<dragon.size();i++)
            {
                if(dragon[i]==-1)
                    continue;
                else if(first==true)
                    first=false;
                else
                    printf(" ");
                printf("%d",dragon[i]);
            }
            printf("\n");
        }
        else
            printf("NO\n");
    }
}
