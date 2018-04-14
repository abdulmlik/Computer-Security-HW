/*
/////////// ********************************************************************************************* \\\\\\\\\\\
|                     This program                                                                                  |
|                     Checks whether input is a decimal digit character                                             |
|                     and Restricted from 0 to 100                                                                  |
|                                                                                                                   |
|                                         Written by Abdulmalik Ben Ali                                  11/10/2107 |
\\\\\\\\\\\ ********************************************************************************************* ///////////
*/
//Have g++ follow the C++14 ISO C++ language standard [-std=c++14]
#include <iostream>
#include <string>


using namespace std;

int main()
{
    float n;
    string s;
    bool DIGIT_AND_REANG = true;
    do{
        system("cls");
        cout << "Enter Grade (0-100) : ";
        cin >> s;
        if(s.find_first_not_of( "0123456789." ) == string::npos) // يجب ان يدخل رقم
        {
            if(s.find_first_not_of( "." ) == string::npos)
            {
            }
            else
            {
                n = stof(s); // يحول من السلسلة الى رقم صحيح
                if( n <= 100 && n >= 0)
                {
                    DIGIT_AND_REANG = false;
                }
            }
        }
    }while( DIGIT_AND_REANG );

    cout << "Grade is : " << n << endl;
    system("pause");
    return 0;
}
