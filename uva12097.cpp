#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double pi=acos(-1);
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        double radius[10001],area[10001],maxa=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&radius[i]);
            area[i]=radius[i]*radius[i]*pi;
            maxa=max(area[i],maxa);
        }
        double left=0,right=maxa;
        while(abs(right-left)>1e-7)
        {
            double mid=(left+right)/2;
            int ptr=0,cnt=0;
            bool flag=true;
            for(int i=0;i<n;i++)
                cnt+=(int)(area[i]/mid);
            if(cnt>=m+1)    left=mid;
            else    right=mid;
        }
        printf("%.4f\n",left);
    }
}
