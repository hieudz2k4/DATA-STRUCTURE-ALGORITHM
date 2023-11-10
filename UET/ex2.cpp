//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int p[1001];
//
//int findSet(int x) {
//    if (p[x] == x) {
//        return x;
//    }
//    return findSet(p[x]);
//}
//
//void unionSet(int x, int y) {
//    x = findSet(x);
//    y = findSet(y);
//    if (x != y ) {
//        p[y] = x;
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++) {
//        p[i] = i;
//    }
//
//    int u, v;
//    int last_u, last_v;
//
//    for (int i = 0; i < n - 1; i++) {
//        cin >> u >> v;
//        if (findSet(u) == findSet(v)) {
//            last_u = u;
//            last_v = v;
//        } else {
//            unionSet(u, v);
//        }
//    }
//
//    cout << endl;
//    cout << last_u << " " << last_v << endl;
//
//    return 0;
//}
