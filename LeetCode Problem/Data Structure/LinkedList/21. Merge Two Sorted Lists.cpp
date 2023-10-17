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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* curRes = res;

        ListNode* curL1 = list1;
        ListNode* curL2 = list2;

        while (curL1 and curL2) {
            if (curL1->val <= curL2->val) {
                curRes->next = new ListNode(curL1->val);
                curL1 = curL1->next;
                curRes = curRes->next;
            } else {
                curRes->next = new ListNode(curL2->val);
                curL2 = curL2->next;
                curRes = curRes->next;
            }
        }

        while (curL1) {
            curRes->next = new ListNode(curL1->val);
            curL1 = curL1->next;
            curRes = curRes->next;
        }

        while (curL2) {
            curRes->next = new ListNode(curL2->val);
            curL2 = curL2->next;
            curRes = curRes->next;
        }
        return res->next;
    }
};

//int main() {
//    Solution solution;
//    ListNode* l1 = new ListNode(1);
////    l1->next = new ListNode(2);
////    l1->next->next = new ListNode(4);
//
//    ListNode* l2 = new ListNode(1);
//    l2->next = new ListNode(3);
//    l2->next->next = new ListNode(4);
//
//    ListNode* res = solution.mergeTwoLists(l1, l2);
//    while(res) {
//        cout << res->val << " ";
//        res = res->next;
//    }
//}