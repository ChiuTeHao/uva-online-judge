#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int maxlen=600;
void getPermutation(int targetseq[],int cnt,int first,int asc)
{
    int step;
    if(asc==0)
        step=-1;
    else
        step=1;
    int num=first;
    for(int i=0;i<cnt;i++)
    {
        targetseq[i]=num;
        num+=step;
        if(num<=0)
            num+=cnt;
        else if(num==cnt+1)
            num=1;
    }
}
int main()
{
    int n;
    int num[maxlen];
    while(scanf("%d",&n)==1&&n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int ans=n*n+1;
        int targetseq[maxlen];
        for(int asc=0;asc<=1;asc++)
        {
            for(int first=1;first<=n;first++)
            {
                getPermutation(targetseq,n,first,asc);
                int step=0;
                int original[maxlen];
                memcpy(original,num,n*sizeof(int));
                /*
                printf("target ");
                for(int i=0;i<n;i++)
                    printf("%d ",targetseq[i]);
                printf("\n");
                printf("original ");
                for(int i=0;i<n;i++)
                    printf("%d ",original[i]);
                printf("\n");
                */
                for(int i=0;i<n;i++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(original[j]==targetseq[i])
                        {
                            swap(original[i],original[j]);
                            step+=1;
                        }
                    }
                }
                if(ans>step)
                    ans=step;
            }
        }
        printf("%d\n",ans);
    }
}
