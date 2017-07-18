#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
using namespace std;
void build(map<long long int,int> &Mobile,char str[],int left,int right,int depth)
{
    if(str[left]=='[')
    {
        int p=0;
        for(int i=left+1;i<=right-1;i+=1)
        {
            if(str[i]=='[')
                p+=1;
            if(str[i]==']')
                p-=1;
            if(str[i]==','&&p==0)
            {
                build(Mobile,str,left+1,i-1,depth+1);
                build(Mobile,str,i+1,right-1,depth+1);
            }
        }
    }
    else
    {
        long long int w;
        sscanf(str+left,"%lld",&w);
        if(Mobile.count(w<<depth)==0)
            Mobile[w<<depth]=1;
        else
            Mobile[w<<depth]+=1;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char str[1048576];
        map<long long int,int> Mobile;
        scanf(" %s",str);
        build(Mobile,str,0,strlen(str)-1,0);
        map<long long int,int>::iterator it;
        int cnt=0,ans,Max=0;
        for(it=Mobile.begin();it!=Mobile.end();it++)
        {
            cnt+=it->second;
            if(Max<it->second)
                Max=it->second;
        }
        ans=cnt-Max;
        printf("%d\n",ans);
    }
}
