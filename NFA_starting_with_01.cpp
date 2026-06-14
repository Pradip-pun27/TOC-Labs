/* NFA for strings starting with 01
   Name: Pradip-Pun-Magar | Subject: TOC (4th sem) */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int state = 0; // q0

    cout << "Enter the string: ";
    cin >> str;

    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];

        if (c != '0' && c != '1') {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }
        if (state == 0 && c == '0') state = 1;
        else if (state == 1 && c == '1') state = 2;
        else if (state == 2 && (c == '0' || c == '1')) state = 2;
        else {
            cout << "String not accepted";
            return 0;
        }
    }

    if (state == 2)
        cout << "String accepted"<<endl;
    else
        cout << "String not accepted"<<endl;

    return 0;
}