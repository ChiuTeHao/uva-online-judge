#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<utility>
using namespace std;
const int maxn=1000+10;
int rows,cols;
bool outOfBound(int row,int col)
{
    return (row<0 || row>=rows || col<0 || col>=cols);
}
bool onBorder(int row,int col)
{
    return row==0 || col==0 || row==rows-1 || col==cols-1;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    char maze[maxn][maxn];
    int fire[maxn][maxn];
    while(kase--)
    {
        queue<pair<int,int> > fireq;
        queue<int> firetq;
        scanf("%d%d",&rows,&cols);
        int inirow,inicol;
        int maxt=rows*cols+10;
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                scanf(" %c",&maze[row][col]);
                fire[row][col]=maxt;
                if(maze[row][col]=='J')
                {
                    inirow=row;
                    inicol=col;
                }
                if(maze[row][col]=='F')
                {
                    fireq.push(make_pair(row,col) );
                    firetq.push(1);
                    fire[row][col]=1;
                }
            }
        }
        int drow[4]={0,-1,1,0},dcol[4]={-1,0,0,1};
        while(fireq.empty()==false)
        {
            int row=fireq.front().first,col=fireq.front().second,t=firetq.front();
            fireq.pop();
            firetq.pop();
            for(int i=0;i<4;i++)
            {
                int newrow=row+drow[i],newcol=col+dcol[i];
                if(!outOfBound(newrow,newcol)&&maze[newrow][newcol]=='.'&&fire[newrow][newcol]==maxt)
                {
                    fireq.push(make_pair(newrow,newcol) );
                    firetq.push(t+1);
                    fire[newrow][newcol]=t+1;
                }
            }
        }
        queue<pair<int,int> > pos;
        queue<int> t;
        pos.push(make_pair(inirow,inicol) );
        t.push(1);
        int ans=-1;
        bool visit[maxn][maxn]={};
        while(pos.empty()==false)
        {
            int row=pos.front().first,col=pos.front().second,time=t.front();
            pos.pop();
            t.pop();
            if(onBorder(row,col))
            {
                ans=time;
                break;
            }
            for(int i=0;i<4;i++)
            {
                int newrow=row+drow[i],newcol=col+dcol[i];
                if(!outOfBound(newrow,newcol)&&visit[newrow][newcol]==false&&maze[newrow][newcol]=='.'&&fire[newrow][newcol]>time+1)
                {
                    pos.push(make_pair(newrow,newcol) );
                    t.push(time+1);
                    visit[newrow][newcol]=true;
                }
            }
        }
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
}
