#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int n, m;
    string str, str2 = "", nTemp;
    bool DIGIT_AND_REANG = false, FIRST = true;


    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);


    do{
        if( FIRST ) cout << endl << "Enter a number between 1 and 25 : ";
        if( !FIRST ) cout << endl << "please Enter a number between 1 and 25 : ";
        cin >> nTemp;
        if(nTemp.find_first_not_of( "0123456789" ) == string::npos)
        {
            n = stof(nTemp);
            if( n <= 25 && n >= 1)
            {
                DIGIT_AND_REANG = true;
            }
        }
        FIRST = false;
    }while( !DIGIT_AND_REANG );

    for(unsigned i = 0 ; i < str.length() ; i++ )
    {
        m = ( int(str[i]) + n );
        if( m > 122 ) m = m % 123 + 97;
        str2 += char( m );
    }

    cout << endl;
    cout << "plain  text : " << str  << endl;
    cout << "cipher text : " << str2 << endl;
    return 0;
}
