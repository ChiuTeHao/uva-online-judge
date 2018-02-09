#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            printf(">");
        else if(a==b)
            printf("=");
        else
            printf("<");
        printf("\n");
    }
}
