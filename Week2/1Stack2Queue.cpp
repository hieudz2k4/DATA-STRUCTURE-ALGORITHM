#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
public:
    void getStack() {
        while (!q1.empty()) {
            cout << q1.front() << " ";
            q1.pop();
        }
    }
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack rong";
        } else {
            q1.pop();
        }
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.getStack();
}
