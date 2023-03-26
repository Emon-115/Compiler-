#include<iostream>
#include <string>
#include <stack>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int prefix_eval(char[]);
int postfix_eval(char[]);

int n=1,i=0,j=0,k=0;
char a[10][10],f[10];

using namespace std;

string lr,lf,pre, post,tar;


void LeftRecursion()
{
    int i=0,z;
    char c,ch;

        printf("Enter your Left Recursion:");
        for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);



     c=a[0][0];
     if(a[0][2] == c)
        {
        printf("Left recursion found: \n");
        printf("%c' -> ",c);
           for(k=3;k<strlen(a[0]) && a[0][k] != '|';k++)
           {
             printf("%c",a[0][k]);
           }
               printf("%c' | e",c);
               n=k; i=0;
               printf("\n%c ->",c);
               for(k=n+1; k<strlen(a[0]) && a[0][k]!='\0'; k++)
               {
                printf("%c",a[0][k]);
               }
               printf("%c'",c);
            printf("\n");
        }

             else{
                printf("No left recursion!!");
             }


}

void LeftFactoring( )
{
  char gram[20],part1[20],part2[20],modifiedGram[20],newGram[20],tempGram[20];
       int i,j=0,k=0,l=0,pos;
       printf("Enter your LeftFactoring :A-> ");
      cin >> gram;
      for(i=0;gram[i]!='|';i++,j++)
            part1[j]=gram[i];
       part1[j]='\0';
       for(j=++i,i=0;gram[j]!='\0';j++,i++)
           part2[i]=gram[j];
       part2[i]='\0';
       for(i=0;i<strlen(part1)||i<strlen(part2);i++)
       {
            if(part1[i]==part2[i])
            {
                 modifiedGram[k]=part1[i];
                 k++;
                 pos=i+1;
            }
       }
       for(i=pos,j=0;part1[i]!='\0';i++,j++){
            newGram[j]=part1[i];
       }
       newGram[j++]='|';
       for(i=pos;part2[i]!='\0';i++,j++){
            newGram[j]=part2[i];
       }
       modifiedGram[k]='X';
       modifiedGram[++k]='\0';
       newGram[j]='\0';
       printf("\n A->%s",modifiedGram);
       printf("\n X->%s\n",newGram);
}

int prefix_eval(char a[]) {

	 stack<int>s;
    for(int i=strlen(a)-1;i>=0;i--)
    {
        int num=0;
        if(isdigit(a[i]))
        {
             while(a[i]!=' ')
             {
                num=10*num+(a[i]-'0');
                i--;
             }
             s.push(num);
        }
        if(a[i]=='*'||a[i]=='+'||a[i]=='-'||a[i]=='/')
        {
            char b,c;
            c=s.top();
            s.pop();
            b=s.top();
            s.pop();
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

void ThreeAddressRepression(string tar)
{

}


int main()
{
	string s1,s2;
	do {

		cout << "Enter input by(console/exit): ";
		cin >> s1;

		if (s1 == "console")
		{
		    cout <<"Enter choice Left Factoring/Left Recursion/Prefix/Postfix/Three Address Repression:";
			cin >> s2;

			 if (s2 == "lr")
			{
				LeftRecursion( );
			}

            else if (s2 == "lf")
			{
				LeftFactoring( );
			}


			else if (s2 == "pre")
            {
                char a[20];
                cout <<"Enter Prefix Expression:";
                cin >> a;
                cout<<"Result::"<<prefix_eval(a);
                return 0;

			}

			else if (s2 == "post")
			{
                char a[20];
                cout <<"Enter Postfix Expression:";
                cin >> a;
                cout<<"Result::"<<postfix_eval(a);
                return 0;
			}

            else if (s2 == "tar")
			{
				cout << "Enter a Three Address Repression Expression: ";
				cin >> tar;
				ThreeAddressRepression(tar);
				cout << "\n" << "The Three Address Repression: ";

			}
		}
		else if (s1 == "exit")
		{
			break;
		}
	} while (true);
}
