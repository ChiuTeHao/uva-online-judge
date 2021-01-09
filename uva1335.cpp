#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAX=100000+10;
bool test(int nums[],int n,int k)
{
    int left[MAX],right[MAX];
    int x=nums[1],y=k-nums[1];
    left[1]=x;
    right[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==1)
        {
            right[i]=min(y-right[i-1],nums[i]);
            left[i]=nums[i]-right[i];
        }
        else
        {
            left[i]=min(x-left[i-1],nums[i]);
            right[i]=nums[i]-left[i];
        }
    }
    return left[n]==0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        int nums[MAX]={};
        for(int i=1;i<=n;i++)   scanf("%d",&nums[i]);
        if(n==1)
        {
            printf("%d\n",nums[1]);
            continue;
        }
        nums[n+1]=nums[1];
        nums[0]=nums[n];
        int L=0,R=0;
        for(int i=1;i<=n;i++)   L=max(L,nums[i]+nums[i+1]);
        if(n%2)
        {
            R=L*3;
            while(L<R)
            {
                int mid=(L+R)/2;
                if( test(nums,n,mid) ) R=mid;
                else    L=mid+1;

            }
        }
        printf("%d\n",L);
    }
}
