#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXSIZE=1000000+5;
const int INF=1000000000+5;
struct Tree
{
    int Min[MAXSIZE*3],Max[MAXSIZE*3],Sum[MAXSIZE*3],addv[MAXSIZE*3],setv[MAXSIZE*3];
};
struct Result
{
    int Min,Max,Sum;
};
void maintain(Tree *tree,int nodeid,int left,int right)
{
    int lc=(nodeid<<1),rc=(nodeid<<1)+1;
    if(right>left)
    {
        tree->Sum[nodeid]=tree->Sum[lc]+tree->Sum[rc];
        tree->Min[nodeid]=min(tree->Min[lc],tree->Min[rc]);
        tree->Max[nodeid]=max(tree->Max[lc],tree->Max[rc]);
    }
    if(tree->setv[nodeid]>=0)
    {
        tree->Sum[nodeid]=tree->setv[nodeid]*(right-left+1);
        tree->Min[nodeid]=tree->setv[nodeid];
        tree->Max[nodeid]=tree->setv[nodeid];
    }
    if(tree->addv[nodeid]>=0)
    {
        tree->Sum[nodeid]+=tree->addv[nodeid]*(right-left+1);
        tree->Min[nodeid]+=tree->addv[nodeid];
        tree->Max[nodeid]+=tree->addv[nodeid];
    }
}
void pushDown(Tree *tree,int nodeid)
{
    int lc=(nodeid<<1),rc=(nodeid<<1)+1;
    if(tree->setv[nodeid]>=0)
    {
        tree->setv[lc]=tree->setv[rc]=tree->setv[nodeid];
        tree->addv[lc]=tree->addv[rc]=0;
        tree->setv[nodeid]=-1;
    }
    if(tree->addv[nodeid]>0)
    {
        tree->addv[lc]+=tree->addv[nodeid];
        tree->addv[rc]+=tree->addv[nodeid];
        tree->addv[nodeid]=0;
    }
}
void addVal(Tree *tree,int nodeid,int left,int right,int ql,int qr,int val)
{
    int lc=(nodeid<<1),rc=(nodeid<<1)+1;
    if(ql<=left&&right<=qr) tree->addv[nodeid]+=val;
    else
    {
        pushDown(tree,nodeid);
        int mid=(left+right)/2;
        if(ql<=mid)
            addVal(tree,lc,left,mid,ql,qr,val);
        else
            maintain(tree,lc,left,mid);
        if(mid<qr)
            addVal(tree,rc,mid+1,right,ql,qr,val);
        else
            maintain(tree,rc,mid+1,right);
    }
    maintain(tree,nodeid,left,right);
}
void setVal(Tree *tree,int nodeid,int left,int right,int ql,int qr,int val)
{
    if(ql<=left&&right<=qr)
    {
        tree->addv[nodeid]=0;
        tree->setv[nodeid]=val;
    }
    else
    {
        int mid=(left+right)/2,lc=nodeid<<1,rc=(nodeid<<1)+1;
        pushDown(tree,nodeid);
        if(ql<=mid) setVal(tree,lc,left,mid,ql,qr,val); else    maintain(tree,lc,left,mid);
        if(mid<qr)  setVal(tree,rc,mid+1,right,ql,qr,val);  else    maintain(tree,rc,mid+1,right);
    }
    maintain(tree,nodeid,left,right);
}
void query(Tree *tree,int nodeid,int left,int right,int add,int ql,int qr,Result *result)
{
    if(tree->setv[nodeid]>=0)
    {
        int interval=min(right,qr)-max(left,ql)+1;
        result->Min=min(result->Min,tree->setv[nodeid]+tree->addv[nodeid]+add);
        result->Max=max(result->Max,tree->setv[nodeid]+tree->addv[nodeid]+add);
        result->Sum+=interval*tree->setv[nodeid]+interval*(tree->addv[nodeid]+add);
    }
    else if(ql<=left&&right<=qr)
    {
        result->Min=min(result->Min,tree->Min[nodeid]+add);
        result->Max=max(result->Max,tree->Max[nodeid]+add);
        result->Sum+=tree->Sum[nodeid]+add*(right-left+1);
    }
    else
    {
        int mid=(left+right)/2,lc=(nodeid<<1),rc=(nodeid<<1)+1;
        if(ql<=mid) query(tree,lc,left,mid,add+tree->addv[nodeid],ql,qr,result);
        if(mid<qr)  query(tree,rc,mid+1,right,add+tree->addv[nodeid],ql,qr,result);
    }
    printf("%d %d %d %d %d\n",left,right,tree->Sum[nodeid],tree->Min[nodeid],tree->Max[nodeid]);
}
Tree trees[22];
int main()
{
    int R,C,Q;
    while(scanf("%d%d%d",&R,&C,&Q)==3)
    {
        int action,row1,col1,row2,col2,val;
        for(int i=1;i<=R;i++)
        {
            memset(&trees[i],0,sizeof(trees[i]) );
            memset(trees[i].setv,-1,sizeof(trees[i].setv) );
            trees[i].setv[1]=0;
        }
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d%d%d%d",&action,&row1,&col1,&row2,&col2);
            if(action==1||action==2)
                scanf("%d",&val);
            if(action==1)
            {
                for(int row=row1;row<=row2;row++)
                    addVal(&trees[row],1,1,C,col1,col2,val);
            }
            else if(action==2)
            {
                for(int row=row1;row<=row2;row++)
                    setVal(&trees[row],1,1,C,col1,col2,val);
            }
            else
            {
                Result result;
                result.Min=INF;
                result.Max=-INF;
                result.Sum=0;
                for(int row=row1;row<=row2;row++)
                    query(&trees[row],1,1,C,0,col1,col2,&result);
                printf("%d %d %d\n",result.Sum,result.Min,result.Max);
            }
        }
    }
}
/*
0 2 7 7 7
0 2 7 7 7
0 2 7 7 7
0 0 5 5 5
*/
