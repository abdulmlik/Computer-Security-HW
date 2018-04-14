/*
/////////// ********************************************************************************************* \\\\\\\\\\\
|                     This program                                                                                  |
|                                                |
|                                                                                                                   |
|                                         Written by Abdulmalik Ben Ali                                  17/10/2107 |
\\\\\\\\\\\ ********************************************************************************************* ///////////
*/
//Have g++ follow the C++14 ISO C++ language standard [-std=c++14]
#include <iostream>
#include <string>
#include <limits> //numeric_limits<streamsize>::max()

using namespace std;



/*-----start function---------*/

void printScreens();                // طباعة الاختيارات على الشاشة
void phrase_cipher();               // الاختيار الاول
void vigenere_cipher();             // الاختيار الثاني
void phrase_key_cipher();           // الاختيار الثالث
void modified_phrase_key_cipher();  // الاختيار الرابع

/*------End function----------*/

int main()
{
    char input;
    do{
        system("cls");
        printScreens();
        cout<<"\n\nEnter number \'1-5\' : ";
        cin>>input;
        /*------------- تجاهل جميع الاحرف او الارقام الزائدة عند الادخال --------------*/
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*------------------------------*/
        switch(input)
        {
            case '1':
            {
                system("cls");
                phrase_cipher();
                system("PAUSE");//يوقف التنفيذ
                break;
            }// end case 1
            case '2':
            {
                system("cls");
                vigenere_cipher();
                system("PAUSE");
                break;
            }// end case 2
            case '3':
            {
                system("cls");
                phrase_key_cipher();
                system("PAUSE");
                break;
            }//end case 3
            case '4':
            {
                system("cls");
                modified_phrase_key_cipher();
                system("PAUSE");
                break;
            }//end case 4
            case '5': return 0;
        }// end switch
    }while(1);
}//end main

void printScreens()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali" << "\n\t\t\tStudent Number : 213010551" << endl;

    cout << "\n\t\t1- Encryption in The Phrase Cipher." << endl;
    cout << "\n\t\t2- Encryption in Vigenere Ciphers." << endl;
    cout << "\n\t\t3- Encryption in Phrase key Cipher." << endl;
    cout << "\n\t\t4- Encryption in modified Phrase key Cipher." << endl;
    cout << "\n\t\t5- End Program." << endl;
}


/*----- start phrase cipher ---------*/

string encryption_p_c(string ,int);

void phrase_cipher()
{
    int n;
    string str, str2, nTemp;
    bool DIGIT_AND_REANG = false, FIRST = true;


    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);


    do{
        if( FIRST ) cout << endl << "Enter a number between 1 and 25 : ";
        if( !FIRST ) cout << endl << "Please Enter a number between 1 and 25 : ";
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


    str2 = encryption_p_c(str,n);

    cout << endl;
    cout << "plain  text : " << str  << endl;
    cout << "cipher text : " << str2 << endl;
}//end phrase_cipher

string encryption_p_c( string str,int n )
{
    int m;
    string str2 = "";
    for(unsigned i = 0 ; i < str.length() ; i++ )
    {
        m = ( int(str[i]) + n );
        if( m > 122 ) m = m % 123 + 97;
        str2 += char( m );
    }
    return str2;
}//fun

/*------ End phrase cipher ----------*/

/*----- start vigenere cipher ---------*/

string create_key_v_c( unsigned );

string encryption_v_c( string , string );

string decryption_v_c( string , string );

void vigenere_cipher()
{
    string str, key, str2,temp;

    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    key  = create_key_v_c( str.length() );

    str2 = encryption_v_c( str, key );

    //temp = decryption_v_c( str2 , key );


    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    cout << "cipher text : " << str2 << endl;

    //cout << "plain text : " << temp << endl;

}//end vigenere_cipher

string create_key_v_c( unsigned length_str )
{
    string key = "";
    for(unsigned i = 0 ; i < length_str ; i++)
    {
        key += char( rand() % 26 + 97 );
    }
    return key;
}

string encryption_v_c( string str, string key )
{
    string str2 = "";
    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key[i]) ) % 97 ) % 26 + 97 );
    }
    return str2;
}

string decryption_v_c( string str2, string key )
{
    string temp = "";
    for(unsigned i = 0 ; i < str2.length() ; i++)
    {
        int n_temp;
        n_temp = int(str2[i]) - int(key[i]);
        if(n_temp < 0) n_temp = 26 + n_temp;
        temp += char( n_temp + 97 );
    }
    return temp;
}

/*------ End vigenere cipher ----------*/

/*----- start phrase key cipher ---------*/

string create_key_p_k_c( string , unsigned );

string encryption_p_k_c( string , string );

void phrase_key_cipher()
{
    string str, key, key2, str2;

    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    do{
        cout << "enter the key : ";
        cin >> key;
    }while( key.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    key2 = create_key_p_k_c( key, str.length());

    str2 = encryption_p_k_c(str , key2);

    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    //cout << "key2        : " << key2 << endl;
    cout << "cipher text : " << str2 << endl;
} //end phrase_key_cipher

string create_key_p_k_c( string key, unsigned n)
{
    string key2 = "";
    for(unsigned i = 0, j = 0 ; i < n ; i++, j++)
    {
        if( j == key.length() )
        {
            j = 0;
        }
        key2 += key[j];
    }
    return key2;
}

string encryption_p_k_c( string str, string key2 )
{
    string str2 = "";
    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key2[i]) ) % 97 ) % 26 + 97 );
    }
    return str2;
}

/*------ End phrase key cipher ----------*/

/*----- start modified phrase key cipher ---------*/

string create_key_m_p_k_c( string , unsigned );

string encryption_m_p_k_c( string , string );

void modified_phrase_key_cipher()
{
    string str, key, key2, str2;

    do{
        system("cls");
        cout << "enter the test string for encryption : ";
        cin >> str;
    }while( str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    do{
        cout << "enter the key : ";
        cin >> key;
    }while( key.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos);

    key2 = create_key_m_p_k_c(key, str.length());

    str2 = encryption_m_p_k_c( str, key2);

    cout << endl;
    cout << "plain text  : " << str  << endl;
    cout << "key         : " << key  << endl;
    //cout << "key2        : " << key2 << endl;
    cout << "cipher text : " << str2 << endl;

}//end modified_phrase_key_cipher

string create_key_m_p_k_c( string key, unsigned n)
{
    int found = 0;
    string key2 = "";
    for(unsigned i = 0, j = 0 ; i < n ;  )
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
            for(int c = 97  ; i < n && c < 123 ; c++ )
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
    return key2;
}

string encryption_m_p_k_c( string str, string key2)
{
    string str2 = "";
    for(unsigned i = 0 ; i < str.length() ; i++)
    {
        str2 += char( ( ( int(str[i]) + int(key2[i]) ) % 97 ) % 26 + 97 );
    }
    return str2;
}

/*------ End modified phrase key cipher ----------*/
