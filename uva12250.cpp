#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char hello[6][20]={"HELLO\0","HOLA\0","HALLO\0",
                 "BONJOUR\0","CIAO\0","ZDRAVSTVUJTE\0"};
char lang[6][20]={"ENGLISH\0","SPANISH\0","GERMAN\0",
                  "FRENCH\0","ITALIAN\0","RUSSIAN\0"};
int main()
{
    char str[20];
    int kase=0;
    while(scanf(" %s",str)==1)
    {
        if(strcmp(str,"#")==0)
            return 0;
        kase++;
        for(int i=0;i<6;i++)
        {
            if(strcmp(str,hello[i])==0)
            {
                printf("Case %d: %s\n",kase,lang[i]);
                break;
            }
            else if(i==5)
            {
                printf("Case %d: UNKNOWN\n",kase);
            }
        }
    }
}
