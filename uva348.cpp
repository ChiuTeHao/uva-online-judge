#include<stdio.h>
#include<stdlib.h>
const int MAXN=12;
void recursive(int from,int to,int trace[][MAXN],int left[],int right[])
{
    if(to-from==0)
        return;
    else if(to-from==1)
    {
        left[from]+=1;
        right[to]+=1;
    }
    else
    {
        recursive(from,trace[from][to],trace,left,right);
        recursive(trace[from][to]+1,to,trace,left,right);
        left[from]+=1;
        right[to]+=1;
    }
}
int main()
{
    int kase=1;
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int row[MAXN],col[MAXN];
        int DP[MAXN][MAXN]={},trace[MAXN][MAXN]={},left[MAXN]={},right[MAXN]={};
        for(int i=0;i<n;i++)
            scanf("%d%d",&row[i],&col[i]);
        for(int i=0;i<n-1;i++)
            DP[i][i+1]=row[i]*col[i]*col[i+1];
        for(int k=2;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                int bestcnt=2147483647,bestidx=i;
                for(int j=i;j<i+k;j++)
                {
                    if(DP[i][j]+DP[j+1][i+k]+row[i]*col[j]*col[i+k]<bestcnt)
                    {
                        bestcnt=DP[i][j]+DP[j+1][i+k]+row[i]*col[j]*col[i+k];
                        bestidx=j;
                    }
                }
                DP[i][i+k]=bestcnt;
                trace[i][i+k]=bestidx;
            }
        }
        
        recursive(0,n-1,trace,left,right);
        printf("Case %d: ",kase);
        for(int i=0;i<n;i++)
        {
            if(left[i])
            {
                for(int j=0;j<left[i];j++)
                    printf("(");
            }
            printf("A%d",i+1);
            if(right[i])
            {
                for(int j=0;j<right[i];j++)
                    printf(")");
            }
            if(i<n-1)
                printf(" x ");
        }
        printf("\n");
        kase++;
    }
}
