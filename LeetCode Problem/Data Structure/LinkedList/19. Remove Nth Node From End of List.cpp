#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n > 0) {
            int length = 0;
            ListNode *cur = head;
            while (cur) {
                length++;
                cur = cur->next;
            }
            cur = head;

            for (int i = 0; i < length - n - 1; i++) {
                cur = cur->next;
            }
            if (cur == head && length - n - 1 < 0) {
                head = cur->next;
                delete(cur);
            } else {
                ListNode *nodeDel = cur->next;
                cur->next = cur->next->next;
            }
        }
        return head;

    }
};

/*
int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    ListNode* res = solution.removeNthFromEnd(head, 1);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
 */