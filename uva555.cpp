#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Card
{
    public:
        char suit,Rank;
        bool operator<(const Card &rhs)
        {
            map<char,int> suitorder,rankorder;
            suitorder['C']=0;
            suitorder['D']=1;
            suitorder['S']=2;
            suitorder['H']=3;
            rankorder['T']=10;
            rankorder['J']=11;
            rankorder['Q']=12;
            rankorder['K']=13;
            rankorder['A']=14;
            if(suit!=rhs.suit)
                return suitorder[suit]<suitorder[rhs.suit];
            else
            {
                int left,right;
                if(Rank>='2'&&Rank<='9')
                    left=Rank-'0';
                else
                    left=rankorder[Rank];
                if(rhs.Rank>='2'&&rhs.Rank<='9')
                    right=rhs.Rank-'0';
                else
                    right=rankorder[rhs.Rank];
                return left<right;
            }
        }
};
int main()
{
    char dealer[4]={'N','E','S','W'};
    char c;
    while(scanf(" %c",&c)==1)
    {
        if(c=='#') break;
        char line1[60],line2[60];
        int first;
        scanf(" %s %s",line1,line2);
        for(int i=0;i<4;i++)
        {
            if(c==dealer[i])
            {
                first=(i+1)%4;
                break;
            }
        }
        vector<Card>own[4];
        for(int i=0;i<52;i+=2)
        {
            Card tmp;
            tmp.suit=line1[i];
            tmp.Rank=line1[i+1];
            own[first].push_back(tmp);
            first=(first+1)%4;
        }
        for(int i=0;i<52;i+=2)
        {
            Card tmp;
            tmp.suit=line2[i];
            tmp.Rank=line2[i+1];
            own[first].push_back(tmp);
            first=(first+1)%4;
        }
        for(int i=0;i<4;i+=1)
        {
            int now=(i+2)%4;
            sort(own[now].begin(),own[now].begin()+own[now].size());
            printf("%c:",dealer[now]);
            for(int j=0;j<13;j++)
                printf(" %c%c",own[now][j].suit,own[now][j].Rank);
            printf("\n");
        }
    }
}
