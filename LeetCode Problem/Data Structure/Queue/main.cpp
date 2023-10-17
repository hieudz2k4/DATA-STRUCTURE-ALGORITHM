#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        q1.push(x);
        while (!q1.empty()) {

        }
    }

    int pop() {

    }

    int top() {

    }

    bool empty() {
        return q2.empty();
    }
};

int main() {
    return 0;
}