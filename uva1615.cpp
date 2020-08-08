#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct Point
{
    double start,end;
    bool operator<(const Point &rhs) const
    {
        if(start!=rhs.start) return start<rhs.start;
        else return end<rhs.end;
    }
};
int main()
{
    int L,D,N;
    while(scanf("%d%d%d",&L,&D,&N)==3)
    {
        vector<Point> points;
        points.resize(N);
        for(int i=0;i<N;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            points[i].start=max((double)((-1)*sqrt(D*D-y*y)+x),0.0);
            points[i].end=min((double)L,sqrt(D*D-y*y)+x);
        }
        sort(points.begin(),points.end());
        /*
        for(int i=0;i<points.size();i++)
            printf("%f %f\n",points[i].start,points[i].end);
        */
        int ans=0;
        double last=-1;
        for(int i=0;i<points.size();i++)
        {
            if(last<points[i].start)
            {
                ans+=1;
                last=points[i].end;
            }
            
        }
        printf("%d\n",ans);
    }
}
