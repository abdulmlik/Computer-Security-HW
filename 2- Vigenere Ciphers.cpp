#include <iostream>
#include <cstdlib> //rand()

using namespace std;

int main()
{
    string str, key = "", str2 = "",temp ="";

    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        key += char( rand() % 26 + 97 );
    }

    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key[i]) ) % 97 ) % 26 + 97 );
    }
/*
    for(unsigned i = 0 ; i < str2.length() ; i++)
    {
        int n_temp;
        n_temp = int(str2[i]) - int(key[i]);
        if(n_temp < 0) n_temp = 26 + n_temp;
        temp += char( n_temp + 97 );
    }
*/
    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    cout << "cipher text : " << str2 << endl;

    //cout << "plain text : " << temp << endl;

    return 0;
}
