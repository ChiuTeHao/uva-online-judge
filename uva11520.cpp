#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char Map[11][11];
    for(int t=1;t<=n;t++)
    {
        int len;
        scanf("%d",&len);
        for(int i=0;i<len;i++)
            scanf(" %s",Map[i]);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(Map[i][j]!='.')  continue;
                for(int alpha=0;alpha<26;alpha++)
                {
                    bool ok=true;
                    if(i-1>=0&&Map[i-1][j]-'A'==alpha)  ok=false;
                    if(i+1<len&&Map[i+1][j]-'A'==alpha) ok=false;
                    if(j-1>=0&&Map[i][j-1]-'A'==alpha)  ok=false;
                    if(j+1<len&&Map[i][j+1]-'A'==alpha) ok=false;
                    if(ok)
                    {
                        Map[i][j]='A'+alpha;
                        break;
                    }
                }
            }
        }
        printf("Case %d:\n",t);
        for(int i=0;i<len;i++)
            printf("%s\n",Map[i]);
    }
}
