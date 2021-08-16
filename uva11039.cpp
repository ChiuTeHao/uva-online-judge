#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int &a,int &b)
{
    return abs(a)<abs(b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,cur=1000000000;
        scanf("%d",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            int num;
            scanf("%d",&num);
            arr.push_back(num); 
        }
        sort(arr.begin(),arr.end(),cmp);
        int ans=1;
        cur=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(abs(cur)<abs(arr[i]) && cur/abs(cur)*arr[i]/abs(arr[i])<0)
            {
                cur=arr[i];
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}
