#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        } else {
            ListNode* cur = head;
            ListNode* res = new ListNode();
            ListNode* curRes = res;
            while (cur) {
                if (cur->val != val) {
                    curRes->next = new ListNode(cur->val);
                    curRes = curRes->next;
                }
                cur = cur->next;
            }
            return res->next;
        }
    }
};

//int main() {
//    Solution solution;
//    ListNode* l1 = new ListNode(1);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(6);
//    l1->next->next->next = new ListNode(3);
//    l1->next->next->next->next = new ListNode(4);
//    l1->next->next->next->next->next = new ListNode(5);
//    l1->next->next->next->next->next->next = new ListNode(6);
//
//    ListNode* l2 = nullptr;
//
//    ListNode* l3 = new ListNode(7);
//    l3->next = new ListNode(7);
//    l3->next->next = new ListNode(7);
//    l3->next->next->next = new ListNode(7);
//
//    ListNode* res = solution.removeElements(l3, 7);
//
//    while(res) {
//        cout << res->val << " ";
//        res = res->next;
//    }
//    return 0;
//}