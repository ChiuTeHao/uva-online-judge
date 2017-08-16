#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int Row,Col,M,N;
        int cnt[101][101]={};
        bool water[101][101]={},visit[101][101]={};
        int W;
        scanf("%d%d%d%d",&Row,&Col,&M,&N);
        scanf("%d",&W);
        int dif_row[8]={M,M,-1*M,-1*M,N,N,-1*N,-1*N};
        int dif_col[8]={N,-1*N,N,-1*N,M,-1*M,M,-1*M};
        for(int i=1;i<=W;i+=1)
        {
            int row,col;
            scanf("%d%d",&row,&col);
            water[row][col]=1;
        }
        int row,col;
        queue<int>Q;
        Q.push(0);
        Q.push(0);
        visit[0][0]=true;
        while(!Q.empty())
        {
            row=Q.front();
            Q.pop();
            col=Q.front();
            Q.pop();
            set<pair<int,int> > s;
            for(int i=0;i<8;i+=1)
            {
                int newrow=row+dif_row[i];
                int newcol=col+dif_col[i];
                if(newrow<0||newcol<0||newrow>=Row||newcol>=Col)
                    continue;
                if(!water[newrow][newcol]&&s.count(make_pair(newrow,newcol))==0)
                {
                    cnt[row][col]+=1;
                    s.insert(make_pair(newrow,newcol));
                }
                if(!water[newrow][newcol]&&!visit[newrow][newcol])
                {
                    Q.push(newrow);
                    Q.push(newcol);
                    visit[newrow][newcol]=true;
                }
            }
        }
        int even=0,odd=0;
        if(cnt[0][0]==0) cnt[0][0]=2;
        for(int i=0;i<Row;i++)
        {
            for(int j=0;j<Col;j++)
            {
                if(visit[i][j]&&cnt[i][j]%2==0)
                    even++;
                else if(visit[i][j]&&cnt[i][j]%2)
                    odd++;
            }
        }
        printf("Case %d: %d %d\n",a,even,odd);
    }
}
