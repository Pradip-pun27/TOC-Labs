/* DFA for strings ending with 01
   Name: Pradip-Pun-Magar | Subject: TOC (4th sem) */

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int state = 0; // Initial state
    cout << "DFA: Accept strings ending with 01\n";
    cout << "Enter string: ";
    cin >> str;
    cout << "\nTransition: q0";
    
    for(size_t i = 0; i < str.length(); i++){ //size_t: an unsigned int type used for rep.sizes and counts
        if(str[i] != '0' && str[i] != '1'){
            cout << "\nInvalid! Only {0,1} allowed\n";
            return 0;
        }
        if(state == 0 && str[i] == '0') state = 1;
        else if(state == 0 && str[i] == '1') state = 0;
        else if(state == 1 && str[i] == '0') state = 1;
        else if(state == 1 && str[i] == '1') state = 2;
        else if(state == 2 && str[i]=='0') state = 1;
        else if(state == 2 && str[i]=='1') state = 0;
        
        cout << " --" << str[i] << "--> ";
        if(state ==0) cout << "q0";
        else if(state == 1) cout <<"q1";
        else if(state == 2) cout << "q2";
    }
    cout << "\n\nResult: ";
    cout << (state == 2 ? "ACCEPTED" : "REJECTED")<<endl;
    return 0;
}
