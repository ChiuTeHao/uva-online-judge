#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
using namespace std;

int main()
{
    int kase;
    scanf("%d",&kase);
    int s,n,id[100001];
    for(int t=1;t<=kase;t++)
    {
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&id[i]);
        bool norepeat[100001]={};
        map<int,int> repeat;
        queue<int> q;
        int dup=0;
        for(int i=0;i<min(s,n);i++)
        {
            q.push(id[i]);
            if(repeat.count(id[i])==0)
                repeat[id[i]]=1;
            else
                repeat[id[i]]+=1;
            if(repeat[id[i]]==2)
                dup+=1;
        }
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                if(i+s-1<n)
                {
                    q.push(id[i+s-1]);
                    if(repeat.count(id[i])==0)
                        repeat[id[i+s-1]]=1;
                    else
                        repeat[id[i+s-1]]+=1;
                    if(repeat[id[i+s-1]]==2)
                        dup+=1;
                }
                int out=q.front();
                q.pop();
                if(repeat[out]==2)
                    dup-=1;
                repeat[out]-=1;
            }
            if(dup)
                norepeat[i]=false;
            else
                norepeat[i]=true;
        }
        int ans=0;
        set<int>appear;
        for(int i=0;i<s;i++)
        {
            if(i<n)
            {
                if(appear.count(id[i])!=0)
                    break;
                appear.insert(id[i]);
            }
            bool flag=true;
            for(int j=i+1;j<n;j+=s)
            {
                if(norepeat[j]==false)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                ans+=1;
        }
        printf("%d\n",ans);
    }
}
