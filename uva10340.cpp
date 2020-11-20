#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    char str1[100000],str2[100000];
    while(scanf(" %s %s",str1,str2)==2)
    {
        int ptr=0;
        int len1=strlen(str1),len2=strlen(str2);
        bool flag=true;
        for(int i=0;i<len1;i++)
        {
            while(ptr<len2&&str2[ptr]!=str1[i]) ptr++;
            if(ptr==len2||str2[ptr]!=str1[i])
            {
                flag=false;
                break;
            }
            else    ptr++;
        }
        if(flag)    printf("Yes\n");
        else    printf("No\n");
    }
}
