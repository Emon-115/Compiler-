#include<iostream>
#include<string.h>
#include <string>

using namespace std;
string s[100][100];
int sz = 1;

void func1(string s1) {
	int l = 0;	
	
	l = s1.length();
	
	if (s1[l - 1] == ';')
	{
		string r1;
		for (int i = 0; i < l - 1; i++)
		{
			if (s1[i] == ' ')
				break;
			else	r1.push_back(s1[i]);
		}
		int l1 = r1.length();
		string r2;
		int k = (l - 1) - (l1 + 1);
		string r3;
		
		if (r1 == "int" || r1 == "float" || r1 == "double" || r1 == "char" || r1 == "string")
		{
			r2 = s1.substr(l1+1, k);
			int l2 = r2.length();
			string r3;
			int flag = 0;
			
			string pre, post;
			for (int i = 0; i < l2; i++)
			{

				r3.push_back(r2[i]);
				int rl = r3.length();

				if (r2[i + 1] == NULL)
				{
					int jl = 0;

					for (int j = 0; j < r3.length(); j++)
					{

						if (r3[j] == '=')              //input2
						{
							jl = j;
							flag = 1;

						}
					}
					if (flag == 1) {
						pre = r3.substr(0, jl);
						post = r3.substr(jl + 1, rl);
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == pre)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable "+ pre + " already used.\n";
							i++;
							flag--;
							r3.clear();
							pre.clear();
							post.clear();
						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = pre;
								s[sz][2] = r1;
								s[sz][3] = post;
								i++;
								sz++;
								flag--;
								r3.clear();
								pre.clear();
								post.clear();

							}
						

					}
					else {

						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == r3)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + r3 + " already used.\n";
							i++;
							r3.clear();

						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = r3;
								s[sz][2] = r1;
								s[sz][3] = "NULL";
								i++;
								sz++;
								r3.clear();

							}

						

					}
				}

				else if (r2[i + 1] == ',') {            //input3

					int cl = 0;

					for (int j = 0; j < r3.length(); j++)
					{

						if (r3[j] == '=')
						{
							cl = j;
							flag = 1;

						}
					}
					if (flag == 1) {
						pre = r3.substr(0, cl);
						post = r3.substr(cl + 1, rl);
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == pre)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + pre + " already used.\n";
							i++;
							flag--;
							r3.clear();

						}
							else {
								
									
									
										s[sz][0] = to_string(sz);
										s[sz][1] = pre;
										s[sz][2] = r1;
										s[sz][3] = post;
										i++;
										sz++;
										flag--;
										r3.clear();

									
								

							}
						
					}
					else
					{
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == r3)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + r3 + " already used.\n";
							i++;
							
							r3.clear();

						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = r3;
								s[sz][2] = r1;
								s[sz][3] = "NULL";
								i++;
								sz++;
								r3.clear();


							}



						
					}

				}
			}
			
			cout << "\nData inserted successfully....\n";
		}
		else
			cout << "Wrong input!! Data-type error...\n";
	}
	else
		cout << "Wrong input!! semicolon needed...\n";
}


void func2(string del) {
	int flag = 0,m=0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == del)
			{
				m = i;
				
				flag = 1;
				
			}
		}
	}
	
	if (flag == 1) {
		for (int i = m; i < sz; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				s[i][j] = s[i + 1][j];

			}
		}
		cout << "Delete successfully...\n";
	}
	else
		cout << "Variable not found...\n";

}


void func3(string x, string y) {
	int flag = 0, m = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == x)
			{
				m = i;

				flag = 1;

			}
		}
	}

	if (flag == 1) {
			s[m][3] = y;
			cout << "Update successfully...\n";
		}
	
	else
		cout << "Variable not found!!!\n";

}


void func4(string x) {

    int flag = 0, m = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == x)
			{
				m = i;

				flag = 1;

			}
		}
	}


if(flag == 1){
    for (int i = m; i < sz; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			cout << s[i][j];
			cout << "\t";
			cout << "\t";
		}
		cout << "\n";
        break;
	}
}
	
}





int main() {
	int n;
	
	s[0][0] = "SL";
	s[0][1] = "NAME";
	s[0][2] = "TYPE";
	s[0][3] = "VALUE";
for(int i=0;i<10;i++){
    string input;
    cout<<"Enter :";
    //cin.ignore();
    getline(cin,input);

    string a;
    int sk;
    int len = input.length(); 

    for(int i=0;i<len;i++){
        if (input[i] == '('){
            sk = i;
            break;
        }
				
			else	a.push_back(input[i]);
    }
    
    string b;
    for(int i=sk+1;i<len;i++){
        if (input[i] == ')'){
            sk = i;
            break;
        }
				
			else	b.push_back(input[i]);
    }
   

    if(a == "insert"){
        func1(b);
    }
    else if(a == "drop"){
        func2(b);
    }
    else if(a == "update"){
        string x,y;
        int track;
        int b_size = b.length(); 
        for(int i=0;i<b_size;i++){
             if (b[i] == ','){
            track = i;
            break;
        }
				
			else	x.push_back(b[i]);
        }
        
        for(int i=track+1;i<b_size;i++){
        				
			y.push_back(b[i]);
        }
       func3(x,y);
    }
    else if(a == "lookup"){
        func4(b);
    }
    else {
        return 0;
    }

}

}