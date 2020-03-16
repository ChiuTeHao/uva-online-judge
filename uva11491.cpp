#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
using namespace std;
const int MAX=1e5+5;
int main()
{
    int n,d;
    char str[MAX];
    while(scanf("%d%d",&n,&d)==2)
    {
        if(n==0&&d==0)
            break;
        scanf(" %s",str);
        int len=strlen(str),out=0;
        stack<int> digits,output;
        for(int i=0;i<len;i++)
        {
            int digit=str[i]-'0';
            while(digits.empty()==0&&digits.top()<digit&&out<d)
            {
                digits.pop();
                out+=1;
            }
            digits.push(digit);
        }
        while(digits.empty()==0&&out<d)
        {
            digits.pop();
            out++;
        }
        while(digits.empty()==0)
        {
            output.push(digits.top());
            digits.pop();
        }
        while(output.empty()==0)
        {
            printf("%d",output.top());
            output.pop();
        }
        printf("\n");
    }
}
