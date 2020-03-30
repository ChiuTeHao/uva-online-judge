#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXSIZE=250;
void print(int DP[][MAXSIZE],char str[],int from,int to);
bool match(char left,char right)
{
    return ((left=='['&&right==']')||(left=='('&&right==')'));
}
int main()
{
    int kase;
    scanf("%d",&kase);
    char str[MAXSIZE];
    getchar();
    fgets(str,MAXSIZE,stdin);
    for(int t=0;t<kase;t++)
    {
        fgets(str,MAXSIZE,stdin);
        
        int DP[MAXSIZE][MAXSIZE]={},len=strlen(str);
        if(strcmp(str,"\n")==0)
        {
            str[0]='\0';
            len=0;
        }
        else
        {
            str[len-1]='\0';
            len=strlen(str);
        }
        for(int i=0;i<len;i++)
            DP[i][i]=1;
        for(int k=1;k<len;k++)
        {
            for(int i=0;i+k<len;i++)
            {
                DP[i][i+k]=len;
                if(match(str[i],str[i+k]))
                    DP[i][i+k]=min(DP[i][i+k],DP[i+1][i+k-1]);
                for(int j=i;j<i+k;j++)
                    DP[i][i+k]=min(DP[i][i+k],DP[i][j]+DP[j+1][i+k]);
            }
        }
        print(DP,str,0,len-1);
        printf("\n");
        if(t<kase-1) printf("\n");
        fgets(str,MAXSIZE,stdin);
    }
}
void print(int DP[][MAXSIZE],char str[],int from,int to)
{
    //printf("%d %d\n",from,to);
    if(from>to) return;
    else if(from==to)
    {
        if(str[from]=='('||str[from]==')') printf("()");
        else printf("[]");
        return;
    }
    if(match(str[from],str[to])&&DP[from][to]==DP[from+1][to-1])
    {
        printf("%c",str[from]);
        print(DP,str,from+1,to-1);
        printf("%c",str[to]);
        return;
    }
    for(int j=from;j<to;j++)
    {
        if(DP[from][j]+DP[j+1][to]==DP[from][to])
        {
            print(DP,str,from,j);
            print(DP,str,j+1,to);
            return;
        }
    }
    
}
