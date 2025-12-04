#include<iostream>
#include<stack>
#include<algorithm>
#include<cctype>

using namespace std;

char matchingClosing(char open) {
    switch (open) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        default:  return '\0'; // invalid input
    }
}


int main() {
    string bracket = "[(2 + (3 * 5))";
    bool valid = true;
    bracket.erase(remove_if(bracket.begin(), bracket.end(), ::isspace), bracket.end());

    stack<char> checker;
    for (int i = 0; i < bracket.length(); i++) {
        if (bracket[i] == '[' || bracket[i] == '(' || bracket[i] == '{') {
            checker.push(bracket[i]);

        }else if (bracket[i] == ']' || bracket[i] == ')' || bracket[i] == '}') {
            if (checker.empty()) { 
                valid = false; 
                break; 
            }
            char value = checker.top();
            checker.pop();
            if (bracket[i] != matchingClosing(value)) {
                valid = false;
                break;
            }
        }
    }

    valid = true;

    if (!checker.empty()) {
        valid = false;
    }

    if (valid) {
        cout << "Valid string" << endl;
    }else {
        cout << "Not valid string" << endl;
    }

    cout << bracket.length() << endl;
    return 0;
}