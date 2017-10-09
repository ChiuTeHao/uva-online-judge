#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;
struct Box
{
    int len[10],dim,id;
    bool operator<(const Box &rhs)const
    {
        for(int i=0;i<dim;i++)
        {
            if(len[i]!=rhs.len[i])
                return len[i]<rhs.len[i];
        }
        return true;
    }
};
bool capable(const Box &lhs,const Box &rhs)
{
    for(int i=0;i<lhs.dim;i++)
    {
        if(lhs.len[i]>=rhs.len[i]) return false;
    }
    return true;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        Box box[35];
        for(int i=0;i<n;i++)
        {
            int Size[10];
            for(int j=0;j<m;j++)
                scanf("%d",&Size[j]);
            sort(Size,Size+m);
            for(int j=0;j<m;j++)
                box[i].len[j]=Size[j];
            box[i].dim=m;
            box[i].id=i;
        }
        sort(box,box+n);
        int Max_num=1,lis[35]={},pre[35]={};
        int Max_index=0;
        lis[0]=1;
        pre[0]=0;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            pre[i]=i;
            for(int j=0;j<i;j++)
            {
                if(capable(box[j],box[i])&&lis[j]+1>lis[i])
                {
                    lis[i]=lis[j]+1;
                    pre[i]=j;
                }
            }
            if(Max_num<=lis[i])
            {
                Max_num=lis[i];
                Max_index=i;
            }
        }
        int ptr=Max_index;
        stack<int> S;
        S.push(ptr);
        while(pre[ptr]!=ptr)
        {
            S.push(pre[ptr]);
            ptr=pre[ptr];
        }
        printf("%d\n",Max_num);
        int cnt=0,stop=S.size();
        while(!S.empty())
        {
            printf("%d",box[S.top()].id+1);
            S.pop();
            cnt++;
            if(cnt<stop) printf(" ");
        }
        printf("\n");
    }
}
