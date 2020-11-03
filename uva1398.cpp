#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Event
{
    public:
        double time;
        int type;
        bool operator<(const Event &rhs) const;
        Event(double t=0,int e=0):time(t),type(e){}
};
bool Event::operator<(const Event &rhs)const
{
    if( (time<rhs.time) || (time==rhs.time&&type>rhs.type) )    return true;
    return false;
}
void update(int pos,int v,int bound,double &enter,double &leave)
{
    if(v==0)
    {
        if(pos<=0||pos>=bound)  leave=enter-1;
    }
    else if(v<0)
    {
        enter=max(enter,static_cast<double>(bound-pos)/v);
        leave=min(leave,static_cast<double>(-pos)/v);
    }
    else
    {
        enter=max(enter,static_cast<double>(-pos)/v);
        leave=min(leave,static_cast<double>(bound-pos)/v);
    }
}
int main()
{
    int kase;
    scanf("%d",&kase);
    Event events[200005];
    while(kase--)
    {
        int w,h,n;
        scanf("%d%d",&w,&h);
        scanf("%d",&n);
        int eventcnt=0;
        for(int i=0;i<n;i++)
        {
            int x,y,a,b;
            scanf("%d%d%d%d",&x,&y,&a,&b);
            double enter=0,leave=100000;
            update(x,a,w,enter,leave);
            update(y,b,h,enter,leave);
            if(enter<leave)
            {
                events[eventcnt++]=Event(enter,0);
                events[eventcnt++]=Event(leave,1);
            }
        }
        int cnt=0,ans=0;
        sort(events,events+eventcnt);
        for(int i=0;i<eventcnt;i++)
        {
            double t=events[i].time;
            while(i<eventcnt&&events[i].time==t)
            {
                if(events[i].type==0)   cnt++;
                else    cnt--;
                i++;
            }
            ans=max(ans,cnt);
            i--;
        }
        printf("%d\n",ans);
    }
}
