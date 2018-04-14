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


    int found = 0;
    for(unsigned i = 0, j = 0 ; i < str.length() ;  )
    {
        if( j < key.length() )
        {
            if( key2.find_first_of( key[j] , found) == string::npos )
            {
                key2 += key[j];
                i++;
            }
            j++;
        }
        else
        {
            j = 0;
            string temp;
            for(int c = 97  ; i < str.length() && c < 123 ; c++ )
            {
                temp = char( c );
                if( key.find_first_of( temp ) == string::npos )
                {
                    key2 += temp;
                    i++;
                }
            }
            found += 25;
        }

    }

    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key2[i]) ) % 97 ) % 26 + 97 );
    }

    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    //cout << "key2        : " << key2 << endl;
    cout << "cipher text : " << str2 << endl;

    return 0;
}
