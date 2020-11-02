#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int sigmasize=26;
const int MAXWORD=400000;
const int MAXLEN=300000;
const int MOD= 20071027;
class Trie
{
    public:
        int pointers[MAXWORD+5][sigmasize];
        int val[MAXWORD+5];
        int sz;
        Trie();
        void insert(char *str);
};
Trie::Trie():sz(1)
{
    memset(pointers[0],0,sizeof(pointers[0]) );
    memset(val,0,sizeof(val) );
}
void Trie::insert(char *str)
{
    int nodeno=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int idx=str[i]-'a';
        if(pointers[nodeno][idx]==0)
        {
            memset(pointers[sz],0,sizeof(pointers[sz]) );
            pointers[nodeno][idx]=sz;
            sz++;
        }
        nodeno=pointers[nodeno][idx];
    }
    val[nodeno]++;
}
void search(Trie *trieptr,char str[],int pos,int dp[])
{
    int res=0,nodeno=0;
    int len=strlen(str);
    for(int i=pos;i<len;i++)
    {
        int idx=str[i]-'a';
        if(trieptr->pointers[nodeno][idx]==0)
            break;
        nodeno=trieptr->pointers[nodeno][idx];
        if(trieptr->val[nodeno]) dp[pos]=(dp[pos]+dp[i+1])%MOD;
    }
    return;
}
int main()
{
    char str[MAXLEN+5];
    int dp[MAXLEN+5],kase=0;
    while(scanf(" %s",str)==1)
    {
        int nword;
        scanf("%d",&nword);
        Trie trie;
        for(int i=0;i<nword;i++)
        {
            char word[105];
            scanf(" %s",word);
            trie.insert(word);
        }
        memset(dp,0,sizeof(dp) );
        int length=strlen(str);
        dp[length]=1;
        for(int i=length-1;i>=0;i--)
        {
            search(&trie,str,i,dp);
        }
        kase++;
        printf("Case %d: %d\n",kase,dp[0]);
    }
}
