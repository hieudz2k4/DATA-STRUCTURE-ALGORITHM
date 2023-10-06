#include <iostream>
#include <vector>

using namespace std ;

class Stack {
private:
    vector<int> v ;
public:
    void push(int x) {
        v.push_back(x) ;
    }
    void pop() {
        v.pop_back() ;
    }
    vector<int> getStack() {
        return this->v ;
    }

};

/*
int main() {
    int n ; cin>>n ;
    Stack st1 ;
    for(int i = 0; i<n ;i++) {
        string s ;
        cin >> s ;
        if(s == "push") {
            int n ; cin>>n ;
            st1.push(n) ;
        }
        if(s == "pop") {
            st1.pop() ;
        }
    }
    vector<int> res = st1.getStack() ;
    for(int ele:res) {
        cout << ele << " " ;
    }
    return 0 ;
}
 */

