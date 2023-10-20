#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) {
            if (root->left) inorderTraversal(root->left);
            result.push_back(root->val);
            if (root->right) inorderTraversal(root->right);
        }
        return result;
    }
};

//int main() {
//    Solution solution;
//    TreeNode* treeNode = new TreeNode(1);
//    treeNode->right = new TreeNode(0);
//    treeNode->right->left = new TreeNode(3);
//    TreeNode* treeNode1 = nullptr;
//    vector<int> res = solution.inorderTraversal(treeNode);
//    for (int i : res) cout << i << " ";
//    return 0;
//}