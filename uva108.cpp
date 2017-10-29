#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int square[501][501]={};
        int presum[501][501]={};
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&square[i][j]);
        ans=square[1][1];
        for(int i=0;i<=n;i++)
        {
            int tmp=0;
            for(int j=0;j<=n;j++)
            {
                tmp+=square[i][j];
                presum[i][j]=tmp;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int tmp=presum[1][i]-presum[1][j];
                for(int k=2;k<=n;k++)
                {
                    tmp=max(presum[k][i]-presum[k][j],tmp+presum[k][i]-presum[k][j]);
                    ans=max(ans,tmp);
                }
            }
        }
        printf("%d\n",ans);
    }
}
