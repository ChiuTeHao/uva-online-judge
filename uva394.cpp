#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
using namespace std;
struct Array
{
    string name;
    int base,elementsize,dimension;
    int lowerbound[1001],upperbound[1001];
};
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        Array arr[100];
        map<string,int> maptable;
        for(int i=0;i<n;i+=1)
        {
            cin>>arr[i].name;
            maptable[arr[i].name]=i;
            cin>>arr[i].base>>arr[i].elementsize;
            cin>>arr[i].dimension;
            for(int j=1;j<=arr[i].dimension;j+=1)
            {
                cin>>arr[i].lowerbound[j];
                cin>>arr[i].upperbound[j];
            }
        }
        int c[1001],id[1001];
        for(int i=0;i<m;i+=1)
        {
            string str;
            cin>>str;
            int index=maptable[str];
            for(int j=1;j<=arr[index].dimension;j+=1)
                cin>>id[j];
            c[arr[index].dimension]=arr[index].elementsize;
            for(int j=arr[index].dimension-1;j>0;j--)
                c[j]=c[j+1]*(arr[index].upperbound[j+1]-arr[index].lowerbound[j+1]+1);
            c[0]=arr[index].base;
            for(int j=1;j<=arr[index].dimension;j+=1)
            {
                c[0]-=arr[index].lowerbound[j]*c[j];
            }
            int ans=c[0];
            for(int j=1;j<=arr[index].dimension;j+=1)
                ans+=c[j]*id[j];
            cout<<arr[index].name;
            cout<<"[";
            for(int j=1;j<=arr[index].dimension;j++)
            {
                if(j!=1)
                    cout<<" ";
                cout<<id[j];
                if(j<arr[index].dimension)
                    cout<<",";
            }
            cout<<"] = "<<ans<<endl;
        }
    }
}
