
#include <iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int postfix_eval(char[]);
using namespace std;

int main()
{
    char a[20];
    cout <<"Enter Postfix Expression::";
    gets(a);
    cout<<"Result::"<<postfix_eval(a);
    return 0;
}
int postfix_eval(char a[])
{
    stack<int>s;
    for(int i=0;i<strlen(a);i++)
    {
        int num=0;
        if(isdigit(a[i]))
        {
             while(a[i]!=' ')
             {
                num=10*num+(a[i]-'0');
                i++;
             }
             s.push(num);
        }
        if(a[i]=='*'||a[i]=='+'||a[i]=='-'||a[i]=='/')
        {
            char b,c;
            b=s.top();
            s.pop();
            c=s.top();
            s.pop();
            if(a[i]=='^')
                s.push(pow(c,b));
            if(a[i]=='*')
                s.push(b*c);
            if(a[i]=='/')
                s.push(c/b);
            if(a[i]=='-')
                s.push(c-b);
            if(a[i]=='+')
                s.push(b+c);
        }
    }
    return s.top();
}
