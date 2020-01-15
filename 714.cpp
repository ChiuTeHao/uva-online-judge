#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long int findMin(int bookcnt,int pages[],int scribercnt)
{
    long long int sum=0;
    for(int i=0;i<bookcnt;i++)
        sum+=pages[i];
    long long int left=1,right=sum,mid;
    while(left<right)
    {
        bool flag=true;
        mid=(left+right)/2;
        int scriberneed=0,tmpsum=0;
        for(int i=0;i<bookcnt;i++)
        {
            if(tmpsum+pages[i]>mid)
            {
                if(tmpsum>mid)
                {
                    tmpsum=0;
                    flag=false;
                    break;
                }
                tmpsum=pages[i];
                scriberneed+=1;
            }
            else
                tmpsum+=pages[i];
        }
        scriberneed+=1;
        if(tmpsum>mid)
            flag=false;
        if(scriberneed>scribercnt||flag==false)
            left=mid+1;
        else
            right=mid;
    }
    return left;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int bookcnt,scribercnt;
        scanf("%d%d",&bookcnt,&scribercnt);
        int pages[600];
        for(int i=0;i<bookcnt;i++)
        {
            scanf("%d",&pages[i]);
        }
        long long int minpage=findMin(bookcnt,pages,scribercnt);
        bool flag[600]={};
        int scriberneed=scribercnt-1;
        long long int sum=0;
        for(int i=bookcnt-1;i>=0;i--)
        {
            sum+=pages[i];
            if(sum>minpage&&scriberneed)
            {
                flag[i]=true;
                sum=pages[i];
                scriberneed-=1;
            }
        }
        for(int i=0;i<bookcnt;i++)
        {
            if(flag[i]==false&&scriberneed)
            {
                scriberneed-=1;
                flag[i]=true;
            }
            if(scriberneed==0)
                break;
        }
        for(int i=0;i<bookcnt;i++)
        {
            if(i>0)
                printf(" ");
            printf("%d",pages[i]);
            if(flag[i]==true)
                printf(" /");
        }
        printf("\n");
    }
}
