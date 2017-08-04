#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int player,num;
        double s,ns,ans;
        cin>>player>>s>>num;
        if(s==0)
        {
            printf("0.0000\n");
            continue;
        }
        ns=1-s;
        ans=s;
        for(int i=1;i<num;i++)
            ans*=ns;
        double tmp=1;
        for(int i=1;i<=player;i+=1)
            tmp*=ns;
        tmp=1-tmp;
        ans/=tmp;
        printf("%.4f\n",ans);
    }
}
