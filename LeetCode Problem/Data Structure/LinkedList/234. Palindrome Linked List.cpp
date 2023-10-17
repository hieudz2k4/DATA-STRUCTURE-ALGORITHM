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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return head;
        } else {
            ListNode* copyList = new ListNode(head->val);
            ListNode* curCopy = copyList;
            ListNode* curHead = head;

            while (curHead) {
                curCopy->next = curHead->next;
                curCopy = curCopy->next;
                curHead = curHead->next;
            }

            ListNode* reverse = reverseList(head);
            delete(head);
            delete(curHead);

            ListNode* curReverse = reverse;
            curCopy = copyList;
            while (curCopy && curReverse) {
                if (curHead->val != curCopy->val) {
                    return false;
                }
                curHead = curHead->next;
                curCopy = curCopy->next;
            }

            delete(copyList);
            delete(reverse);
            delete(curReverse);
            delete(curCopy);

            return true;
        }
    }


    ListNode* reverseList(ListNode* param) {
        ListNode* prev = nullptr;
        ListNode* cur = param;

        while (cur) {
            ListNode* curNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = curNext;
        }
        return prev;
    }
};

//int main() {
//    Solution solution;
//    ListNode* l1 = new ListNode(1);
//    l1->next = new ListNode(1);
//    l1->next->next = new ListNode(2);
//    l1->next->next->next = new ListNode(1);
//    cout << solution.isPalindrome(l1);
//    return 0;
//}