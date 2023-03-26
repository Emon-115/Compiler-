
/*  Emon Ahmed
    Id:011181115
    Section:A
    Compiler Assignment 01
    Date:08-03-2022 && 15-03-2022
*/

 #include<iostream>
 #include<string.h>
 using namespace std;


 int menu() {

     int n;

     cout<<" Press KEY-->\n";
     cout<<"(1)Validate a password : \n " ;
     cout<<"(2)Validate UIU CSE/EEE/BBA faculty email address : \n " ;
     cout<<"(3)Validate the following string using the following criteria start with your actual first name in capital characters :\n " ;
     cout<<"(4)Validate the following string using the following criteria Start with @ or # :\n " ;
     cout<<"(5)Validate UIU student ID :\n " ;
     cout<<"(6)Exit : \n" ;
     cout<< "Enter your KEY number:";
     cin>> n;

     return n;
}

    void checkID() {
	string id;

	cout << "Enter UIU Student ID: ";
	cin >> id;

	string s1 = "011";
	string s2 = "021";
	string s3 = "111";
	string s4 = "031";

	string r1 = id.substr(0, 3);

	if (s1 == r1 || s2==r1 || s3==r1 || s4==r1)
	{
		string r2 = id.substr(3, 2);

		if (r2 >= "05" && r2 <= "22")
		{
			string r3 = id.substr(5,1);

			if (r3 >= "1" && r3 <= "3")
			{
				string r4 = id.substr(6, 3);
				if (r4 >= "001" && r4 <= "999")
					cout << "Your ID is Valid\n";
				else
					cout << "Your ID not valid\n";
			}
			else
			cout << "Your ID not valid\n";

		}
		else
			cout << "Your ID not valid\n";

	}
	else
		cout << "Your ID is not valid\n";
        cout << '\n';
}


    void checkString_02()
    {


     cout << '\n';
    }


    void checkString_01()
    {
	string name;
    string p1 = "EMON";
    string p2 = "CSE";
    string p3 = "UIU";
    string p4 = "COM";


    cout << "Enter Your string: ";
	cin >> name;

            int middle=0,l=0;
            l = name.length();

            string r1 = name.substr(0, 3);
                 if(l == 12){
                   if(p1 == r1){
                        for(int i=0;i<=11;i++){
                        if (name[i]>=97 && name[i]<=122)
                            {
                              cout << "Your Password is valid";
                            }
                            else{

                                cout << "Your Password is Notvalid";
                            }
                        }
                    string r2 = name.substr(3, 3);
                    for(int i=3;i<=11;i++){
                    if (r2 >= "300" && r2 <= "400")
                        {
                             cout << "Your Password is valid";
                        }
                            else{

                                cout << "Your Password is Notvalid";
                            }
                    }
                    string r3 = name.substr(6,3);
                    for(int i=6;i<=11;i++){
                    if (p2 == r3 || p3== r3 || p4 == r3)
                        {
                             cout << "Your Password is valid";
                        }
                            else{

                                cout << "Your Password is notvalid";
                            }
                            }
                    string r4 = name.substr(9,1);
                     for(int i=9;i<=11;i++){
						if (name[i] == '+' || name[i] == '-' || name[i] == 'NULL')
						{
							middle = 1;
							 cout << "Your Password is valid";

						}
						else {
							middle = 0;
							break;
						}
					}

					for(int i=10;i<=11;i++){
                    string r4 = name.substr(10,1);
						if (name[i]>=65 && name[i]<=90)
						{

							cout << "Your Password valid\n";
						}
                        else{

                                cout << "Your Password is notvalid";
                            }
					}

             cout << '\n';
}


                 }
    }


    void checkMail()
    {
	string email,id, domain;
	int index = 0, length = 0;;
	cout << "Enter an Email:: ";
	cin >> email;

	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			index = i;
			break;
		}
	}

	if (index != 0) {
		for (int i = 0; i < index; i++)
			if (email[i] >= 48 && email[i] <= 57)
				id.push_back(email[i]);

		for (int i = (index + 1); i < email.length(); i++)
			domain.push_back(email[i]);

            string cseMail = "cse.uiu.ac.bd";
            string eeeMail = "eee.uiu.ac.bd";
            string bbaMail = "bba.uiu.ac.bd";

						if (domain == cseMail || domain == eeeMail || domain == bbaMail)
							cout << " Your Email is Valid.\n";
						else
                        {
                             cout << " Your Email is Invalid.\n";
                        }

	}
	cout << '\n';
}

     void checkPassword()
    {
        string pass;

        string p1 = "P";
        string p2 = "A";
        string p3 = "S";

        cout << "Enter Your Password: ";
        cin >> pass;


        string r1 = pass.substr(0, 1);
        string r2 = pass.substr(1, 2);
        string r3 = pass.substr(2, 3);

        int flag=0;
        int i=1;

        int n = pass.length();

        if(n == 9){
           if(p1 == r1 && p2 ==r2 && p3 == r3){
                for(i=3;i<=9;i++){
                        if ((pass[i]>=48 && pass[i]<=57)||
                            (pass[i]>=65 && pass[i]<=90)||
                            (pass[i]>=97 && pass[i]<=122))
                            {
                              cout << "Your Password is Invalid";
                            }
                        else
                        {
                          if((pass[i]) != (pass[i+1]))
                            {
                            flag = 1;
                          }
                        }
                }
           }
        }

        if(flag == 0){
            printf("Your Password is Invalid ");
        }
        else{
            printf(" Your Password is Valid ");
        }

      cout << '\n';
    }


    int main() {
	do {
		int m = menu();
		if (1 == m)
        checkPassword();
		else if (2 == m)
        checkMail();
		else if (3 == m)
        checkString_01();
		else if (4 == m)
        checkString_02();
        else if (5 == m)
        checkID();
		else if (6 == m)
			break;
		else
			cout << " Your key is wrong ";
	} while (true);
}






