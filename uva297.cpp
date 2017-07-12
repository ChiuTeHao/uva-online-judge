#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
void Draw(string str,int pixel[][32],int &ptr,int r,int c,int w)
{
    char ch=str[ptr];
    ptr+=1;
    if(ch=='p')
    {
        Draw(str,pixel,ptr,r,c+w/2,w/2);
        Draw(str,pixel,ptr,r,c,w/2);
        Draw(str,pixel,ptr,r+w/2,c,w/2);
        Draw(str,pixel,ptr,r+w/2,c+w/2,w/2);
    }
    else if(ch=='f')
    {
        for(int i=r;i<r+w;i+=1)
        {
            for(int j=c;j<c+w;j+=1)
            {
                pixel[i][j]=1;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    string pic1,pic2;
    while(n--)
    {
        int pic1pixel[32][32]={};
        int pic2pixel[32][32]={};
        cin>>pic1>>pic2;
        int ptr=0;
        Draw(pic1,pic1pixel,ptr,0,0,32);
        ptr=0;
        Draw(pic2,pic2pixel,ptr,0,0,32);
        int cnt=0;
        for(int i=0;i<32;i+=1)
        {
            for(int j=0;j<32;j+=1)
            {
                if(pic1pixel[i][j]+pic2pixel[i][j]>0)
                    cnt++;
            }
        }
        printf("There are %d black pixels.\n",cnt);
    }
}
