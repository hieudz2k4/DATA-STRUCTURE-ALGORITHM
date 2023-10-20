#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int tN = 0;
    int countNodes(TreeNode* root) {
        if (root) {
            tN++;
            countNodes(root->left);
            countNodes(root->right);
        }
        return tN;
    }
};

//int main() {
//    Solution solution;
//    TreeNode* treeNode = new TreeNode(1);
//
//    cout << solution.countNodes(treeNode);
//}