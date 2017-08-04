#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int num[550];
        int m,dis=0,address;
        scanf("%d",&m);
        for(int i=1;i<=m;i+=1)
            scanf("%d",&num[i]);
        sort(num+1,num+1+m);
        if(m%2)
            address=num[(m+1)/2];
        else
            address=(num[m/2]+num[m/2+1])/2;
        for(int i=1;i<=m;i+=1)
            dis+=abs(num[i]-address);
        printf("%d\n",dis);
    }
}
