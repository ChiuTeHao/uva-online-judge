#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int MAXSTATION=50;
const int MAXTIME=200;
const int MAXTRAIN=50;
const int INF=1e8;
void solve(int travel_time[],bool has_train[][MAXSTATION+1][2],int ans[][MAXSTATION+1],int station,int time);
int main()
{
    int station;
    int kase=1;
    while(scanf("%d",&station)==1&&station!=0)
    {
        int T,travel_time[MAXSTATION+1],right_train,left_train;
        int left_start[MAXTRAIN+1],right_start[MAXTRAIN+1];
        bool has_train[MAXTIME+1][MAXSTATION+1][2]={};
        int ans[MAXTIME+1][MAXSTATION+1]={};
        scanf("%d",&T);
        for(int i=1;i<station;i++)
            scanf("%d",&travel_time[i]);
        scanf("%d",&right_train);
        for(int i=1;i<=right_train;i++)
        {
            scanf("%d",&right_start[i]);
            int tmp_time=right_start[i];
            for(int j=1;j<=station;j++)
            {
                if(tmp_time<=T)
                    has_train[tmp_time][j][0]=true;
                else
                    break;
                if(j<station)
                    tmp_time+=travel_time[j];
            }
        }
        scanf("%d",&left_train); 
        for(int i=1;i<=left_train;i++)
        {
            scanf("%d",&left_start[i]);
            int tmp_time=left_start[i];
            for(int j=station;j>=1;j--)
            {
                if(tmp_time<=T)
                    has_train[tmp_time][j][1]=true;
                else
                    break;
                if(j>1)
                    tmp_time+=travel_time[j-1];
            }
        }
        /*
        for(int k=0;k<2;k++)
        {
            for(int i=1;i<=station;i++)
            {
                for(int j=0;j<=T;j++)
                {
                    if(has_train[j][i][k]==true)
                        printf("%d ",j);
                }
                printf("\n");
            }
        }
        */
        solve(travel_time,has_train,ans,station,T);
        printf("Case Number %d: ",kase);
        if(ans[0][1]>=INF)
            printf("impossible\n");
        else
            printf("%d\n",ans[0][1]);
        kase++;
    }
}
void solve(int travel_time[],bool has_train[][MAXSTATION+1][2],int ans[][MAXSTATION+1],int station,int time)
{
    for(int i=1;i<station;i++) ans[time][i]=INF;
    ans[time][station]=0;
    for(int i=time-1;i>=0;i--)
    {
        for(int j=1;j<=station;j++)
        {
            ans[i][j]=ans[i+1][j]+1;
            if(j+1<=station&&has_train[i][j][0]&&i+travel_time[j]<=time)
                ans[i][j]=min(ans[i][j],ans[i+travel_time[j]][j+1]);
            if(j-1>=1&&has_train[i][j][1]&&i+travel_time[j-1]<=time)
                ans[i][j]=min(ans[i][j],ans[i+travel_time[j-1]][j-1]);
        }
    }
}
