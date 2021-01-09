#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=100000+10;
void init(int setid[])
{
    for(int i=0;i<MAXSIZE;i++)
        setid[i]=i;
}
int findSet(int setid[],int id)
{
    if(setid[id]!=id)
        setid[id]=findSet(setid,setid[id]);
    return setid[id];
}
void unionSet(int setid[],int id1,int id2)
{
    int setid1=findSet(setid,id1),setid2=findSet(setid,id2);
    setid[setid2]=setid[setid1];
}
int main()
{
    int setid[MAXSIZE];
    int id1,id2,ans=0,flag=1;
    while(scanf("%d",&id1)==1)
    {
        if(id1==-1)
        {
            printf("%d\n",ans);
            ans=0;
            flag=1;
            continue;
        }
        scanf("%d",&id2);
        if(flag)
        {
            init(setid);
            flag=0;
        }
        int setid1=findSet(setid,id1),setid2=findSet(setid,id2);
        if(setid1==setid2)  ans++;
        else    unionSet(setid,id1,id2);
    }
}
