#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int len,kase=0;
    while(scanf("%d",&len)==1)
    {
        if(len==0)  break;
        char str[1000005];
        int f[1000005];
        scanf(" %s",str);
        f[0]=f[1]=0;
        for(int i=1;i<len;i++)
        {
            int j=f[i];
            while(j&&str[i]!=str[j]) j=f[j];
            if(str[i]==str[j])  f[i+1]=j+1;
            else    f[i+1]=0;
        }
        kase++;
        printf("Test case #%d\n",kase);
        for(int i=2;i<=len;i++)
        {
            if(f[i]>0 && (i)%(i-f[i])==0)   printf("%d %d\n",i,i/(i-f[i]));
        }
        printf("\n");
    }
}
