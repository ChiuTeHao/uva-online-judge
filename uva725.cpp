#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
bool check(int num1,int num2)
{
    int use[10]={};
    for(int i=0;i<5;i+=1)
    {
        use[num1%10]+=1;
        use[num2%10]+=1;
        num1/=10;
        num2/=10;
    }
    for(int i=0;i<=9;i++)
    {
        if(use[i]!=1)
            return false;
    }
    return true;
}
int main()
{
    int n;
    bool flag=false;
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        if(flag)
            printf("\n");
        flag=true;
        vector<int>v;
        for(int a=0;a<=9;a++)
            for(int b=0;b<=9;b++)
                for(int c=0;c<=9;c++)
                    for(int d=0;d<=9;d++)
                        for(int e=0;e<=9;e++)
                        {
                            int num=a*10000+b*1000+c*100+d*10+e;
                            if(num%n) continue;
                            if(check(num,num/n))
                                v.push_back(num);
                        }
        if(v.size()>0)
        {
            for(int i=0;i<v.size();i+=1)
            {
                printf("%d / %05d = %d\n",v[i],v[i]/n,n);
            }
        }
        else
            printf("There are no solutions for %d.\n",n);
    }
}
