#include <iostream>
#include <set>

using namespace std;

class MyHashSet {
public:
    set<int> set;
    MyHashSet() {}

    void add(int key) {
        set.insert(key);
    }

    void remove(int key) {
        set.erase(key);
    }

    bool contains(int key) {
        for (int i : set) {
            if (i == key) return true;
        }
        return false;
    }
};


int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);
    cout << myHashSet.contains(1) << endl;
    cout << myHashSet.contains(3) << endl;
    myHashSet.remove(1);
    cout << myHashSet.contains(1);
    return 0;
}