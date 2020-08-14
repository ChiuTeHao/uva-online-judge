#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    
    while(scanf("%d%d",&m,&n)==2)
    {
        int matrix[11][101];
        int sum[11][101],path[11][101];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&matrix[i][j]);
        for(int row=0;row<m;row++)
        {
            sum[row][n-1]=matrix[row][n-1];
            path[row][n-1]=-1;
        }
        for(int col=n-2;col>=0;col--)
        {
            for(int row=0;row<m;row++)
            {
                int lastrow=row-1,nextrow=row+1;
                if(lastrow<0)   lastrow+=m;
                if(nextrow>=m) nextrow=0;
                vector<int> rows;
                rows.push_back(lastrow);
                rows.push_back(row);
                rows.push_back(nextrow);
                sort(rows.begin(),rows.end());
                sum[row][col]=sum[rows[0]][col+1]+matrix[row][col];
                path[row][col]=rows[0];
                for(int i=1;i<3;i++)
                {
                    if(sum[row][col]>sum[rows[i]][col+1]+matrix[row][col])
                    {
                        sum[row][col]=sum[rows[i]][col+1]+matrix[row][col];
                        path[row][col]=rows[i];
                    }
                }
            }
        }
        int pos=0,minsum=sum[0][0];
        for(int i=1;i<m;i++)
        {
            if(minsum>sum[i][0])
            {
                pos=i;
                minsum=sum[i][0];
            }
        }
        vector<int> minpath;
        for(int col=0;col<n;col++)
        {
            printf("%d",pos+1);
            pos=path[pos][col];
            if(col<n-1)
                printf(" ");
        }
        printf("\n");
        printf("%d\n",minsum);
    }
}
