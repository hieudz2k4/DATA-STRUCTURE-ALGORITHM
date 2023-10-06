#include <iostream>

using namespace std;

class MaxHeap {
private:
    int arr[1000];
    int totalElement;
public:
    // thao tac them du lieu
    void insertData(int data) {
        totalElement++;
        arr[totalElement - 1] = data;
        heapify(totalElement - 1);
    }

    // thao tac heapify
    void heapify(int n) {
        int n0 = (n - 1) / 2;
        if (arr[n] > arr[n0]) {
            swap(arr[n], arr[n0]);
            heapify(n0); // De quy
        }
    }

    // thao tac in cay
    void printMaxHeap() {
        for (int i = 0; i < totalElement; i++) {
            cout << arr[i] << " ";
        }
    }
};
int main() {
    MaxHeap* maxHeap = new MaxHeap();
    /**
     * insert 10
     * insert 6
     *  10
     * 6
     * -> print: 10 6
     * insert 19
     *      10
     *     6  19
     * heapify: 19
     *         6  10
     * -> print: 19 6 10
     */
    maxHeap->insertData(10);
    maxHeap->insertData(6);
    maxHeap->printMaxHeap();
    cout << endl;
    maxHeap->insertData(19);
    maxHeap->printMaxHeap();
    return 0;
}