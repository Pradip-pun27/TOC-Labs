/* NFA for accepting string containing 001 as a substring
   Name: Pradip-Pun-Magar | Subject: TOC (4th sem) */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<pair<char, int>>> transitions = {
    {{'0', 0}, {'1', 0}, {'0', 1}}, // q0 --0--> q0, q0 --1--> q0, q0 --0--> q1
    {{'0', 2}},                     // q1 --0--> q2
    {{'1',3}},
    {{'0',3},{'1',3}}
};
bool simulate_nfa(string input) {
    vector<int> current_states = {0}; // start from q0
    for (char c : input) {
        if (c != '0' && c != '1') {
            return false; 
        }
        vector<int> next_states;
        for (int state : current_states) {
            for (auto transition : transitions[state]) {
                if (transition.first == c) {
                    next_states.push_back(transition.second);
                }
            }
        }

        if (next_states.empty()) {
            return false;
        }

        current_states = next_states;
    }
    for (int state : current_states) {
        if (state == 3) {
            return true;
        }
    }
    return false;
}
int main() {
    string input;

    cout << "Enter the string: ";
    cin >> input;

    if (simulate_nfa(input)) {
        cout << "String accepted";
    } else {
        cout << "String not accepted";
    }

    return 0;
}
