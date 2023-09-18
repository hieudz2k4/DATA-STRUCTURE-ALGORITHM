#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> st1, st2;
public:
    void getQueue() {
        while (!st1.empty()) {
            cout << st1.top() << " ";
            st1.pop();
        }
    }
    void enqueue(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void dequeue() {
        if (st1.empty()) {
            cout << "Queue rong";
        } else {
            st1.pop();
        }
    }

};

int main() {
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.dequeue();
    q1.getQueue();
}