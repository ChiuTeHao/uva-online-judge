#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int k;
    while(cin>>k)
    {
        vector<int> v;
        int cnt=0;
        for(int y=k+1;y<=2*k;y+=1)
        {
            if((y*k)%(y-k)==0)
            {
                v.push_back((y*k)/(y-k));
                v.push_back(y);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i+=1)
        {
            int x=v[i*2],y=v[i*2+1];
            printf("1/%d = 1/%d + 1/%d\n",k,x,y);
        }
    }
}
