#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAX=(1e5)+10;
const double eps=1e-9;
struct Line
{
    int start,end;
    bool operator<(const Line &rhs)const;
};
bool Line::operator<(const Line &rhs)const
{
    if(start!=rhs.start) 
        return start<rhs.start;
    return end<rhs.end;
}
bool check(Line line[],int n,double len)
{
    double pos=line[0].start;
    for(int i=0;i<n;i++)
    {
        if(pos+len>line[i].end)
            return false;
        if(i+1<n)
            pos=max(static_cast<double>(line[i+1].start),len+static_cast<double>(pos));
    }
    return true;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        Line line[MAX];
        double left=0,right=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&line[i].start,&line[i].end);
        }
        sort(line,line+n);
        right=line[n-1].end-line[0].start;
        while(fabs(right-left)>eps)
        {
            double mid=(left+right)/2;
            if( check(line,n,mid))
                left=mid;
            else
                right=mid;
        }
        int ansp=0,ansq=1;
        for(int i=1;i<=n;i++)
        {
            int tmpp=round(left*i);
            if(fabs(tmpp/static_cast<double>(i)-left)<fabs(ansp/static_cast<double>(ansq)-left))
            {
                ansp=tmpp;
                ansq=i;
            }
        }
        printf("%d/%d\n",ansp,ansq);
    }
}
