#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAXSIZE=1005;
class Point
{
    public:
        int x,y,color;
        double angle;
        Point operator-(const Point &rhs);
        bool operator<(const Point &rhs)const;
};
Point Point::operator-(const Point &rhs)
{
    Point result;
    result.x=x-rhs.x;
    result.y=y-rhs.y;
    return result;
}
bool Point::operator<(const Point &rhs) const
{
    return angle<rhs.angle;
}
int Cross(const Point &lhs,const Point &rhs)
{
    return lhs.x*rhs.y-rhs.x*lhs.y;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        Point point[MAXSIZE];
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].color);
        Point vectors[MAXSIZE];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int k=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    vectors[k]=point[j]-point[i];
                    if(point[j].color==1)
                    {
                        vectors[k].x*=(-1);
                        vectors[k].y*=(-1);
                    }
                    vectors[k].angle=atan2(vectors[k].y,vectors[k].x);
                    k++;
                }
            }
            sort(vectors,vectors+k);
            int l=0,r=0,cnt=1;
            while(l<k)
            {
                if(l==r)
                {
                    r=(r+1)%k;
                    cnt++;
                }
                while(l!=r&&Cross(vectors[l],vectors[r])>=0)
                {
                    r=(r+1)%k;
                    cnt++;
                }
                ans=max(ans,cnt);
                l++;
                cnt--;
            }
        }
        printf("%d\n",ans);
    }
}
