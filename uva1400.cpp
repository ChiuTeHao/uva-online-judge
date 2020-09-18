#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int maxnodeid=0;
struct Node
{
    long long int  max_sum,max_prefix_sum,max_suffix_sum,sum;
    int max_sum_left,max_sum_right,max_prefix_sum_left,max_prefix_sum_right;
    int max_suffix_sum_left,max_suffix_sum_right,sum_left,sum_right;
};
const int MAXNODE=500000;
struct Node tree[MAXNODE*4+10];
void update(int nodeid,int idx,int value,int left,int right)
{
    Node &node=tree[nodeid];
    if(nodeid>maxnodeid)    maxnodeid=nodeid;
    if(left==right)
    {
        node.max_sum=node.max_prefix_sum=node.max_suffix_sum=node.sum=static_cast<long long int>(value);
        node.max_sum_left=node.max_sum_right=node.max_prefix_sum_left=node.max_prefix_sum_right=node.max_suffix_sum_left=node.max_suffix_sum_right=node.sum_left=node.sum_right=left;
    }
    else
    {
        Node &leftchild=tree[nodeid*2],&rightchild=tree[nodeid*2+1];
        int mid=(left+right)/2;
        if(idx<=mid)    update(nodeid*2,idx,value,left,mid);
        else    update(nodeid*2+1,idx,value,mid+1,right);
        node.sum=leftchild.sum+rightchild.sum;
        node.sum_left=left;
        node.sum_right=right;
        if(leftchild.max_prefix_sum<leftchild.sum+rightchild.max_prefix_sum)
        {
            node.max_prefix_sum=leftchild.sum+rightchild.max_prefix_sum;
            node.max_prefix_sum_left=left;
            node.max_prefix_sum_right=rightchild.max_prefix_sum_right;
        }
        else
        {
            node.max_prefix_sum=leftchild.max_prefix_sum;
            node.max_prefix_sum_left=left;
            node.max_prefix_sum_right=leftchild.max_prefix_sum_right;
        }
        if(leftchild.max_suffix_sum+rightchild.sum<rightchild.max_suffix_sum)
        {
            node.max_suffix_sum=rightchild.max_suffix_sum;
            node.max_suffix_sum_left=rightchild.max_suffix_sum_left;
            node.max_suffix_sum_right=right;
        }
        else
        {
            node.max_suffix_sum=leftchild.max_suffix_sum+rightchild.sum;
            node.max_suffix_sum_left=leftchild.max_suffix_sum_left;
            node.max_suffix_sum_right=right;
        }
        node.max_sum=leftchild.max_sum;
        node.max_sum_left=leftchild.max_sum_left;
        node.max_sum_right=leftchild.max_sum_right;
        long long int val1=node.max_sum;
        long long int val2=leftchild.max_suffix_sum+rightchild.max_prefix_sum;
        if(val1<val2||(val1==val2&&node.max_sum_left>leftchild.max_suffix_sum_left))
        {
            node.max_sum=val2;
            node.max_sum_left=leftchild.max_suffix_sum_left;
            node.max_sum_right=rightchild.max_prefix_sum_right;
        }
        if(node.max_sum<rightchild.max_sum)
        {
            node.max_sum_left=rightchild.max_sum_left;
            node.max_sum_right=rightchild.max_sum_right;
            node.max_sum=rightchild.max_sum;
        }
        
    }
}
void query(int nodeid,int targetleft,int targetright,int left,int right,struct Node *ptr)
{
    if(left==targetleft&&right==targetright)
    {
        *ptr=tree[nodeid];
    }
    else
    {
        int mid=(left+right)/2;
        Node leftchild,rightchild;
        if(mid<targetleft)
        {
            query(nodeid*2+1,targetleft,targetright,mid+1,right,&rightchild);
            *ptr=rightchild;
        }
        else if(targetright<=mid)
        {
            query(nodeid*2,targetleft,targetright,left,mid,&leftchild);
            *ptr=leftchild;
        }
        else
        {
            query(nodeid*2,targetleft,mid,left,mid,&leftchild);
            query(nodeid*2+1,mid+1,targetright,mid+1,right,&rightchild);
            //printf("%d %d %lld\n",leftchild.max_sum_left,leftchild.max_sum_right,leftchild.max_sum);
            //printf("%d %d %lld\n",rightchild.max_sum_left,rightchild.max_sum_right,rightchild.max_sum);
            ptr->sum=leftchild.sum+rightchild.sum;
            ptr->sum_left=targetleft;
            ptr->sum_right=targetright;
            ptr->max_prefix_sum=leftchild.max_prefix_sum;
            ptr->max_prefix_sum_left=leftchild.max_prefix_sum_left;
            ptr->max_prefix_sum_right=leftchild.max_prefix_sum_right;
            if(ptr->max_prefix_sum<leftchild.sum+rightchild.max_prefix_sum)
            {
                ptr->max_prefix_sum=leftchild.sum+rightchild.max_prefix_sum;
                ptr->max_prefix_sum_left=leftchild.sum_right;
                ptr->max_prefix_sum_right=rightchild.max_prefix_sum_right;
            }
            ptr->max_suffix_sum=rightchild.max_suffix_sum;
            ptr->max_suffix_sum_right=rightchild.max_suffix_sum_right;
            ptr->max_suffix_sum_left=rightchild.max_suffix_sum_left;
            if(ptr->max_suffix_sum<=rightchild.sum+leftchild.max_suffix_sum)
            {
                ptr->max_suffix_sum=rightchild.sum+leftchild.max_suffix_sum;
                ptr->max_suffix_sum_left=leftchild.max_suffix_sum_left;
                ptr->max_suffix_sum_right=rightchild.sum_right;
            }
            ptr->max_sum=leftchild.max_sum;
            ptr->max_sum_left=leftchild.max_sum_left;
            ptr->max_sum_right=leftchild.max_sum_right;
            long long int val1=ptr->max_sum,val2=leftchild.max_suffix_sum+rightchild.max_prefix_sum;
            if(val1<val2||(val1==val2&&leftchild.max_suffix_sum_left<ptr->max_sum_left)||(val1==val2&&ptr->max_sum_right>rightchild.max_prefix_sum_right))
            {
                ptr->max_sum=val2;
                ptr->max_sum_left=leftchild.max_suffix_sum_left;
                ptr->max_sum_right=rightchild.max_prefix_sum_right;
            }
            if(ptr->max_sum<rightchild.max_sum)
            {
                ptr->max_sum=rightchild.max_sum;
                ptr->max_sum_left=rightchild.max_sum_left;
                ptr->max_sum_right=rightchild.max_sum_right;
            }
            //printf("%d %d %lld\n",ptr->max_sum_left,ptr->max_sum_right,ptr->max_sum);
        }
    }
}
int main()
{
    int n,q,kase=0;
    while(scanf("%d%d",&n,&q)==2)
    {
        kase++;
        memset(tree,0,sizeof(tree));
        int num;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            update(1,i,num,1,n);
        }
        printf("Case %d:\n",kase);
        for(int i=1;i<=q;i++)
        {
            Node ans;
            int left,right;
            scanf("%d%d",&left,&right);
            query(1,left,right,1,n,&ans);
            printf("%d %d\n",ans.max_sum_left,ans.max_sum_right);
        }
    }
}
