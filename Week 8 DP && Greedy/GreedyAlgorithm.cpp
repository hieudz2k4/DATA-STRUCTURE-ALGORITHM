/**
 * Giải quyết bài toán fraction knapsack bằng giải thuật tham lam.
 */

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
private: double weight, value;
public:
    Item(double weight, double value) : weight(weight), value(value) {}

    double getWeight() const {
        return weight;
    }

    double getValue() const {
        return value;
    }

    void setWeight(double weight) {
        Item::weight = weight;
    }

    void setValue(double value) {
        Item::value = value;
    }

};

/**
 * fractionKnapsack.
 * @param n : int
 * @param items : vector<Item>
 * @param W : double
 * @return : double
 */
double fractionKnapsack(int n, vector<Item> items, double W) {
    double res = 0;

    // sắp xếp theo ti so: value/ weight
    sort(items.begin(), items.end(),
         [](Item &a, Item &b){return a.getValue() / a.getWeight() > b.getValue() / b.getWeight();});

    for(int i = 0; i < n; i++) {
        if (items[i].getWeight() < W) {
            W -= items[i].getWeight();
            res += items[i].getValue();
        } else {
            double fraction = W / items[i].getWeight();
            res += items[i].getValue() * fraction;
            break;
        }
    }

    return res;
}

/**
 * Nhập sô lượng đồ: n
 * Weight của túi đựng: W
 * weight, value của từng item: weight value
 * @return: 0;
 */
int main() {
    int n; double W; cin >> n >> W;

    vector<Item> items;
    for(int i = 0; i < n; i++) {
        double w, v;
        cin >> w >> v;
        items.push_back(Item(w, v));
    }

    cout << fractionKnapsack(n, items, W);
    return 0;
}


