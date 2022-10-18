#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
int main()
{
    string text="LUBIE PLACKI A TY";
   

    char table[3][9] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},{ 'J', 'K', 'L', 'M', 'N', 'O', 'O', 'Q', 'R'},{ 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',' '}};

    string cipher="";
    
    //szyfrowanie
    cout <<"Lenght: " << text.size() << endl;

    for (int i=0; i <= text.size(); i++) {
        for (int k = 0; k < 3; k++) {

        for (int l = 0; l < 9; l++) {
           
            if (table[k][l]==text[i]) {

                cout << table[k][l] << endl;
                
                cipher = cipher + to_string(k) + to_string(l);
                k = l = 14;

            }
        }
    }

    }

    
   
    cout << cipher<<endl;

    //deszyfrowanie
    
    string de_cipher ;

    for (int i = 0; i < (cipher.size() ); i = i + 2) {
        for (int k = 0; k < 3; k++) {

            for (int l = 0; l < 9; l++) {
                
                if (k == int( cipher[i] - '0') && l == int(cipher[i+1] - '0')) {
                    
                    
                    //cout << table[k][l] << endl;
                    de_cipher = de_cipher + table[k][l];

                    k = l = 99;

                }
            }
        }

    }
    cout << de_cipher<<endl;


    
    cout << "Bye World!"<<endl;
    
}

