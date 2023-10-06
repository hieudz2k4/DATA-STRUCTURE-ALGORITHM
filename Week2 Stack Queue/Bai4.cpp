#include <iostream>
#include <vector>

using namespace std ;

class Queue {
private:
    vector <int> queue;

public:
    void enqueue(int x) {
        queue.push_back(x);
    }
    void dequeue() {
        queue.erase(queue.begin());
    }
    void printQueue() {
        for (int num : queue) {
            cout << num << " ";
        }
    }
};
/*
int main() {
    int n; cin >> n;
    Queue q1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s ;
        if (s == "enqueue") {
            int x; cin >> x;
            q1.enqueue(x);
        } else if (s == "dequeue") {
            q1.dequeue();
        }
    }
    q1.printQueue();
    return 0;
}
*/