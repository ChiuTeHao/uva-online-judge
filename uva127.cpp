#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
struct Card
{
    char rank_,suit_;
};
bool cmp(stack<Card> s[],int pile1,int pile2)
{
    if(s[pile1].top().suit_==s[pile2].top().suit_)
        return true;
    else if(s[pile1].top().rank_==s[pile2].top().rank_)
        return true;
    else
        return false;
}
int main()
{
    Card tmp;
    while(scanf(" %c",&tmp.rank_)==1)
    {
        if(tmp.rank_=='#') break;
        else scanf("%c",&tmp.suit_);
        stack<Card> pile[52];
        int next[52],last[52],pilecnt=52;
        pile[0].push(tmp);
        next[0]=1;
        last[0]=-1;
        for(int i=1;i<52;i+=1)
        {
            scanf(" %c%c",&tmp.rank_,&tmp.suit_);
            pile[i].push(tmp);
            next[i]=i+1;
            last[i]=i-1;
        }
        next[51]=-1;
        while(1)
        {
            bool finish=1;
            for(int ptr=0;ptr!=-1;ptr=next[ptr])
            {
                int last1,last3=ptr;
                last1=last[ptr];
                for(int i=1;i<=3&&last3!=-1;i+=1,last3=last[last3]);
                if(last3!=-1&&cmp(pile,last3,ptr))
                {
                    pile[last3].push(pile[ptr].top());
                    pile[ptr].pop();
                    finish=0;
                }
                else if(last1!=-1&&cmp(pile,last1,ptr))
                {
                    pile[last1].push(pile[ptr].top());
                    pile[ptr].pop();
                    finish=0;
                }
                if(pile[ptr].empty())
                {
                    pilecnt--;
                    next[last1]=next[ptr];
                    last[next[ptr]]=last1;
                    finish=0;
                }
                if(!finish) break;

            }
            if(finish) break;
        }
        if(pilecnt>1)
        {
            printf("%d piles remaining:",pilecnt);
            for(int i=0;i!=-1;i=next[i])
                printf(" %d",pile[i].size());
        }
        else
        {
            printf("1 pile remaining: 52");
        }
        printf("\n");
    }
}
