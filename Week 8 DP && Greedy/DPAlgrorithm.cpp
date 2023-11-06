/**
 * Giải quyết bài toán 0-1 knapsack bằng giải thuật quy hoạch động
 */

#include<iostream>
#include <vector>
#include <cstring>

using namespace std;

class Item {
private: int weight, value;
public:
    Item(int weight, int value) : weight(weight), value(value) {}

    int getWeight() const {
        return weight;
    }

    int getValue() const {
        return value;
    }

    void setWeight(int weight) {
        Item::weight = weight;
    }

    void setValue(int value) {
        Item::value = value;
    }

};

/**
 * zeroOneKnapsack
 * @param n : int.
 * @param items : vector<Item>
 * @param W : double
 * CT Đệ Quy:
 * @return : double
 */
int zeroOneKnapsack(int n, vector<Item> items, int W) {
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (items[i-1].getWeight() <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].getWeight()] + items[i-1].getValue());
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

/**
 * Nhập sô lượng đồ: n
 * Weight của túi đựng: W
 * weight, value của từng item: weight value
 * @return: 0;
 */
int main() {
    int n, W; cin >> n >> W;

    vector<Item> items;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        items.push_back(Item(w, v));
    }

    cout << zeroOneKnapsack(n, items, W);
    return 0;
}