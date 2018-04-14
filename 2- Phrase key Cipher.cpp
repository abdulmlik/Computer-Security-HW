#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, key, key2 = "", str2 = "";

    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    do{
        cout << "enter the key : ";
        cin >> key;
    }while( key.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);


    for(unsigned i = 0, j = 0 ; i < str.length() ; i++, j++)
    {
        if( j == key.length() )
        {
            j = 0;
        }
        key2 += key[j];
    }

    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key2[i]) ) % 97 ) % 26 + 97 );
    }

    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    cout << "cipher text : " << str2 << endl;

    return 0;
}
