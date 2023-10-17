#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curRes = res;
        ListNode* curL1 = l1;
        ListNode* curL2 = l2;
        int temp = 0;
        while (curL1 != nullptr or curL2 != nullptr or temp) {
            int sum = (curL1 != nullptr ? curL1->val : 0) + (curL2 != nullptr ? curL2->val : 0) + temp;
            temp = sum / 10;
            curRes->next = new ListNode(sum % 10);
            curRes = curRes->next;

            if (curL1 != nullptr) curL1 = curL1->next;

            if (curL2 != nullptr) curL2 = curL2->next;
        }
        return res->next;
    }
};
/*
int main() {
    Solution solution;

    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);

    ListNode* res = solution.addTwoNumbers(l1, l2);

    ListNode* curRes = res;
    while (curRes != nullptr) {
        cout << curRes->val << " ";
        curRes = curRes->next;
    }
    return 0;
}
 */