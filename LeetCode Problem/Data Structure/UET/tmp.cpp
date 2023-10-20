#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char element : s) {
        if (element == '(' or element == '[' or element == '{') {
            st.push(element);
        } else {
            if (st.empty() ||
                (st.top() == '(' and element != ')') ||
                (st.top() == '[' and element != ']') ||
                (st.top() == '{' and element != '}')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
/*
int main() {
    string s;
    cin >> s;
    if (isValid(s)) cout << "VALID" << endl;
    else cout << "INVALID" << endl;
}
 */