/*Program to Validate the C Identifier and Keyword
   Name: Pradip-Pun-Magar | Subject: TOC (4th sem) */
// Input Alphabet: L for A-Z and a-z , D for 0-9, _ and O for others
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isKeyword(const string& str){
    const vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    for(const string& keyword : keywords){
        if(str == keyword){
            return true;
        }
    }
    return false;
}

int main(){
    string str;
    int state = 0; // Initial state
    cout << "C Identifier and Keyword Checker\n";
    cout << "Enter string: ";
    cin >> str;

    if(isKeyword(str)){
        cout << "\nResult: \"" << str << "\" is a C keyword\n";
        return 0;
    }

    cout << "\nResult: \"" << str << "\" is not a C keyword\n";
    cout << "Now checking whether it is a valid identifier...\n";
    cout << "\nTransition: q0";
    
    for(size_t i = 0; i < str.length(); i++){ //size_t: an unsigned int type used for rep.sizes and counts
        if(str[i] != 'L' && str[i] != 'D' && str[i]!='_' && str[i]!='O'){
            cout << "\nInvalid! Only {L,D,_,O} allowed\n";
            return 0;
        }
        if(state == 0 && (str[i] == 'L' || str[i] == '_')) state = 1;
        else if(state == 0 && (str[i] == 'D' || str[i]== 'O')) state = -1;
        else if(state == 1 && (str[i] == 'L' || str[i] == 'D' || str[i] == '_')) state = 1;
        else if(state == 1 && str[i]=='O') state = -1;
        
        cout << " --" << str[i] << "--> ";
        if(state == 1) cout << "q1";
        else cout << "D";
    }
    cout << "\n\nResult: ";
    if (state == 1)
        cout << "Valid C identifier"<<endl;
    else
        cout << "Not a valid C identifier"<<endl;

    return 0;
}
