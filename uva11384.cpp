#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int f(int n)
{
    if(n==0)    return 0;
    else if(n==1)   return 1;
    else    return f(n/2)+1;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",f(n));
    }
}
