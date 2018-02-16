#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int lenmax=50;
struct Pos
{
    int x,y;
};
void changepos(Pos &pos,int dir)
{
    if(dir==0)
        pos.x-=1;
    else if(dir==1)
        pos.y+=1;
    else if(dir==2)
        pos.x+=1;
    else
        pos.y-=1;
}
bool outofbound(int l,int w,Pos pos)
{
    if(pos.x<0||pos.y<0)
        return true;
    else if(pos.x>l||pos.y>w)
        return true;
    else
        return false;
}
int main()
{
    int lengh,width;
    scanf("%d%d",&lengh,&width);
    bool scent[lenmax+1][lenmax+1]={};
    Pos pos;
    char c,str[105];
    int dir;
    while(scanf("%d%d %c",&pos.x,&pos.y,&c)==3)
    {
        switch(c)
        {
        case 'W':
            dir=0;
            break;
        case 'N':
            dir=1;
            break;
        case 'E':
            dir=2;
            break;
        case 'S':
            dir=3;
            break;
        }
        scanf(" %s",str);
        bool lost=false;
        for(int i=0;i<strlen(str);i++)
        {
            Pos tmp=pos;
            if(str[i]=='F')
                changepos(tmp,dir);
            else if(str[i]=='L')
                dir=(dir-1+4)%4;
            else
                dir=(dir+1)%4;
            if(outofbound(lengh,width,tmp)&&!scent[pos.y][pos.x])
            {
                lost=true;
                scent[pos.y][pos.x]=true;
                break;
            }
            else if(outofbound(lengh,width,tmp))
                continue;
            else
                pos=tmp;
            //printf("%d %d %d\n",pos.x,pos.y,dir);
        }
        printf("%d %d ",pos.x,pos.y);
        switch(dir)
        {
        case 0:
            printf("W");
            break;
        case 1:
            printf("N");
            break;
        case 2:
            printf("E");
            break;
        case 3:
            printf("S");
            break;
        }
        if(lost)
            printf(" LOST\n");
        else
            printf("\n");
    }
}
