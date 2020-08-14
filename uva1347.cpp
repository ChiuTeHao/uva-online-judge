#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
struct Point
{
    int x,y;
};
double dist(const Point &lhs,const Point &rhs)
{
    return sqrt( (lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y) );
}
int main()
{
    int N;
    while(scanf("%d",&N)==1)
    {
        vector<Point> p;
        p.resize(N);
        for(int i=0;i<N;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        vector< vector<double> > dp;
        dp.resize(N);
        for(int i=0;i<N;i++)
            dp[i].resize(N);
        dp[1][0]=dist(p[1],p[0]);
        for(int i=1;i<N-2;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[i+1][j]==0)
                    dp[i+1][j]=dp[i][j]+dist(p[i+1],p[i]);
                else
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dist(p[i+1],p[i]));
                if(dp[i+1][i]==0)
                    dp[i+1][i]=dp[i][j]+dist(p[j],p[i+1]);
                else
                    dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dist(p[j],p[i+1]));
            }
        }
        double ans=dp[N-2][0]+dist(p[0],p[N-1])+dist(p[N-2],p[N-1]);
        for(int i=1;i<N-2;i++)
        {
            ans=min(ans,dp[N-2][i]+dist(p[i],p[N-1])+dist(p[N-2],p[N-1]));
        }
        printf("%.2f\n",ans);
    }
}
