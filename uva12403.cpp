#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        char act[100];
        int total=0,money;
        for(int i=0;i<n;i+=1)
        {
            scanf(" %s",act);
            if(strcmp(act,"donate")==0)
            {
                scanf("%d",&money);
                total+=money;
            }
            else
                printf("%d\n",total);
        }
    }
}
