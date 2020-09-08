#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Point
{
    public:
        int pos,fixcost,delaycost;
        bool operator<(const Point &rhs) const
        {
            return pos<rhs.pos;
        }
};
const double MAXCOST=1e9+10;
double cost[10001][1001][2]={};
int main()
{
    int pointno,speed,pos;
    while(scanf("%d%d%d",&pointno,&speed,&pos)==3)
    {
        if(pointno==0&&speed==0&&pos==0)    break;
        Point point[1001];
        int prefixsum[1001]={};
        for(int i=0;i<pointno;i++)
        {
            scanf("%d%d%d",&point[i].pos,&point[i].fixcost,&point[i].delaycost);
        }
        sort(point,point+pointno);
        for(int i=0;i<pointno;i++)
        {
            prefixsum[i]=point[i].delaycost;
            if(i>0) prefixsum[i]+=prefixsum[i-1];
        }
        for(int i=0;i<pointno;i++)
            for(int j=0;j<pointno;j++)
                cost[i][j][0]=cost[i][j][1]=MAXCOST;
        for(int i=0;i<pointno;i++)
        {
            double time=static_cast<double>(abs(pos-point[i].pos))/speed;
            cost[i][i][0]=prefixsum[pointno-1]*time+static_cast<double>(point[i].fixcost);
            cost[i][i][1]=cost[i][i][0];
        }
        for(int i=1;i<pointno;i++)
        {
            for(int j=0;j+i-1<pointno;j++)
            {
                for(int k=0;k<2;k++)
                {
                    int left=j,right=j+i-1,nextleft=left-1,nextright=right+1,idxk;
                    int unfixcost=0;
                    if(nextleft>=0) unfixcost+=prefixsum[nextleft];
                    unfixcost+=prefixsum[pointno-1]-prefixsum[right];
                    //if(i==pointno-1)
                        //printf("unfixcost %d %d %d\n",left,right,unfixcost);
                    if(k==0)    idxk=left;
                    else    idxk=right;
                    if(nextleft>=0)
                    {
                        double &ans=cost[nextleft][right][0];
                        double time=static_cast<double>(abs(point[idxk].pos-point[nextleft].pos))/speed;
                        ans=min(ans,cost[left][right][k]+time*(unfixcost)+point[nextleft].fixcost);
                        
                    }
                    if(nextright<pointno)
                    {
                        double &ans=cost[left][nextright][1];
                        double time=static_cast<double>(abs(point[idxk].pos-point[nextright].pos))/speed;
                        ans=min(ans,cost[left][right][k]+time*(unfixcost)+point[nextright].fixcost);
                    }
                }
            }
        }
        /*
        for(int i=0;i<pointno;i++)
        {
            for(int j=0;j<pointno;j++)
                printf("%.0f ",min(cost[i][j][0],cost[i][j][1]));
            printf("\n");
        }
        */
        printf("%d\n",static_cast<int>(min(cost[0][pointno-1][0],cost[0][pointno-1][1])));
    }
}
