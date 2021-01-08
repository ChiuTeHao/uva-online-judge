#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
class Item
{
    public:
        int sum,bidx;
        bool operator<(const Item &rhs)const ;
        Item(int s,int b);
};
bool Item::operator<(const Item &rhs)const
{
    return sum>rhs.sum;
}
Item::Item(int s,int b):sum(s),bidx(b)
{
}
void merge(int A[],int B[],int C[],int n)
{
    priority_queue<Item> q;
    for(int i=0;i<n;i++)
        q.push(Item(A[i]+B[0],0));
    for(int i=0;i<n;i++)
    {
        Item item=q.top();
        q.pop();
        C[i]=item.sum;
        if(item.bidx+1<n)
        {
            Item newitem(item.sum-B[item.bidx]+B[item.bidx+1],item.bidx+1);
            q.push(newitem);
        }
    }
}
int main()
{
    int n;
    int arr[1000][1000];
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        for(int i=0;i<n;i++)
            sort(arr[i],arr[i]+n);
        for(int i=1;i<n;i++)
            merge(arr[0],arr[i],arr[0],n);
        sort(arr[0],arr[0]+n);
        for(int i=0;i<n;i++)
        {
            printf("%d",arr[0][i]);
            if(i<n-1)   printf(" ");
        }
        printf("\n");
    }
}
