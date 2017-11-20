#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
struct Square
{
    double x1,x2,y1,y2;
};
int main()
{
    int n,mp[300][300],kase=0;
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        kase++;
        Square square[150];
        double x[300],y[300];
        int cntx=0,cnty=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&square[i].x1,&square[i].y1,&square[i].x2,&square[i].y2);
            x[cntx++]=square[i].x1;
            x[cntx++]=square[i].x2;
            y[cnty++]=square[i].y1;
            y[cnty++]=square[i].y2;
        }
        sort(x,x+cntx);
        sort(y,y+cnty);
        cntx=unique(x,x+cntx)-x;
        cnty=unique(y,y+cnty)-y;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++)
        {
            int lx,rx,ly,ry;
            lx=lower_bound(x,x+cntx,square[i].x1)-x;
            rx=lower_bound(x,x+cntx,square[i].x2)-x;
            ly=lower_bound(y,y+cnty,square[i].y1)-y;
            ry=lower_bound(y,y+cnty,square[i].y2)-y;
            for(int j=lx;j<rx;j++)
                for(int k=ly;k<ry;k++)
                    mp[j][k]=1;
        }
        double ans=0;
        for(int i=0;i<cntx;i++)
        {
            for(int j=0;j<cnty;j++)
            {
                if(mp[i][j])
                {
                    ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                }
            }
        }
        printf("Test case #%d\n",kase);
        printf("Total explored area: %.2f\n",ans);
        printf("\n");
    }
}
