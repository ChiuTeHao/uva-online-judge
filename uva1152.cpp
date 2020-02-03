#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string.h>
#include<math.h>
using namespace std;
int totalelement;
class Hash
{
    public:
        int val,cnt,next;
};
Hash  table[16000001];
int menu[(1<<25)+1];
void pushIntoHash(int value)
{
    int cur,pre=0;
    int idx=(int)(abs(value))%(1<<25);
    cur=menu[idx];
    while(cur!=0)
    {
        if(table[cur].val==value)
        {
            table[cur].cnt+=1;
            return;
        }
        else
        {
            pre=cur;
            cur=table[cur].next;
        }
    }
    totalelement+=1;
    if(pre==0)
        menu[idx]=totalelement;
    else
        table[pre].next=totalelement;
    table[totalelement].val=value;
    table[totalelement].cnt=1;
    table[totalelement].next=0;
}
int findHash(int value)
{
    int idx=(int)(abs(value))%(1<<25);
    int cur=menu[idx];
    while(cur!=0)
    {
        if(table[cur].val==value)
            return table[cur].cnt;
        else
            cur=table[cur].next;
    }
    return 0;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    for(int t=1;t<=kase;t++)
    {
        int num;
        scanf("%d",&num);
        vector<int> A,B,C,D;
        for(int i=0;i<num;i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            A.push_back(a);
            B.push_back(b);
            C.push_back(c);
            D.push_back(d);
        }
        int ans=0;
        totalelement=0;
        memset(table,0,sizeof(table));
        memset(menu,0,sizeof(menu));
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
               pushIntoHash(A[i]+B[j]); 
            }
        }
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                    ans+=findHash(-1*(C[i]+D[j]));
            }
        }
        printf("%d\n",ans);
        if(t<kase)
            printf("\n");
    }
}
