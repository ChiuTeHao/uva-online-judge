#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
const int MAXWORD=4005;
const int MAXLEN=1003;
const int MAXNODE=MAXWORD*MAXLEN;
const int sigmasize=63;
class Trie
{
    public:
        int pointers[MAXNODE][sigmasize],cnt[MAXNODE][sigmasize];
        int sz;
        int val[MAXNODE];
        Trie();
        void init();
        void insert(char *str,long long int &ans);
        map<char,int> table;
};
void Trie::init()
{
    sz=1;
    memset(pointers[0],0,sizeof(pointers[0]) );
    memset(cnt[0],0,sizeof(cnt[0]) );
    memset(val,0,sizeof(val) );
}
Trie::Trie():sz(1)
{
    memset(pointers[0],0,sizeof(pointers[0]) );
    memset(cnt[0],0,sizeof(cnt[0]) );
    memset(val,0,sizeof(val) );
    for(int i=0;i<=9;i++)
    {
        int id=table.size();
        table[i+'0']=id;
    }
    for(int i=0;i<26;i++)
    {
        int id=table.size();
        table[i+'a']=id;
    }
    for(int i=0;i<26;i++)
    {
        int id=table.size();
        table[i+'A']=id;
    }
    int id=table.size();
    table['\0']=id;
}
void Trie::insert(char *str,long long int &ans)
{
    int nodeno=0;
    int len=strlen(str);
    for(int i=0;i<=len;i++)
    {
        int idx=table[ str[i] ];
        if(pointers[nodeno][idx]==0)
        {
            memset(pointers[sz],0,sizeof(pointers[sz]) );
            memset(cnt[sz],0,sizeof(cnt[sz]) );
            pointers[nodeno][idx]=sz;
            sz++;
        }
        ans+=val[nodeno]+cnt[nodeno][idx];
        cnt[nodeno][idx]++;
        val[nodeno]++;
        nodeno=pointers[nodeno][idx];
    }
    val[nodeno]++;
}
Trie trie;
int main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        trie.init();
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            char str[1200];
            scanf(" %s",str);
            trie.insert(str,ans);
        }
        kase++;
        printf("Case %d: %lld\n",kase,ans);
    }
}
