#include <iostream>
#include <map>

using namespace std ;

/*
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq;
    int res = 0;
    for (int num : a) {
        freq[num]++;
    }
    for (auto pair : freq) {
        int frequence = pair.second;
        res += (frequence * (frequence - 1)) / 2;
    }
    cout << res;
}
*/