#include <iostream>
#include <vector>

using namespace std;

// class Node
class Node {
public:
    int val;
    vector<Node*> childNode;
    Node(int val) {
        this->val = val;
    }

};

// class Tree
class Tree {
    /**
     * root node
     */
    Node* root;

    /**
     * searchNode method.
     * @param curNode : Node*
     * @param val : int
     * @return Node*
     */
    Node* searchNode(Node* curNode, int val) {
        if (curNode == NULL) {
            return NULL;
        } else if (curNode->val == val) {
            return curNode;
        } else {
            for (Node* child : curNode->childNode) {
                searchNode(child, val);
            }
        }
    }

    /**
     * insert method
     * @param val1 : int
     * @param val2 : int
     */
    void insert(int val1, int val2) {
        if (root == NULL) {
            root->val = val1;
            Node* newNode = new Node(val2);
            root->childNode.push_back(newNode);
        } else {
            Node* searchNodeVal1 = searchNode(root, val1);
            searchNodeVal1->childNode.push_back(new Node(val2));
        }
    }

    /**
     * depthOfTree method
     * @param curNode
     * @return
     */
    int depthOfTree(Node* curNode) {
        //base case
        if (curNode == NULL) {
            return 1;
        } else {
            int height = 0;
            for (Node* it : curNode->childNode) {
                height = max(height, depthOfTree(it));
            }
            return height + 1;
        }
    }

    /**
     * heightOfTree method
     * @return : int.
     */
    int heightOfTree() {
        return depthOfTree(root);
    }
    /**
     * printPreorderTraversal method
     */
    void printPreorderTraversal(Node* curNode) {
        //base case
        if (curNode == NULL) {
            return;
        }
        cout << curNode->val << " ";
        for (Node* n : curNode->childNode) {
            printPreorderTraversal(n);
        }
    }

    /**
     * printPostOrderTraversal method
     */
    void printPostOrderTraversal(Node* curNode) {
        //base case
        if (curNode == NULL) {
            return;
        } else {
            for (Node* n : curNode->childNode) {
                printPostOrderTraversal(n); // recursive
            }
            cout << curNode->val;
        }
    }

    /**
     * printInorderTraversal method.
     */
    void printInorderTraversal(Node* curNode) {
        // BaseCase
        if (curNode == NULL) {
            return;
        } else {
            printInorderTraversal(curNode->childNode[0]);
            cout << curNode->val;
            printInorderTraversal(curNode->childNode[1]);
        }
    }

    /**
     * checkBinaryTree method.
     * @param curNode
     * @return bool
     */
    bool checkBinaryTree(Node* curNode) {
        // basecase
        if (curNode->childNode.size() > 2) {
            return false;
        } else {
            for (Node* it : curNode->childNode) {
                checkBinaryTree(it);
            }
        }
        return true;
    }

    /**
     * afterCheckBinaryTree method.
     */
    void afterCheckBinaryTree() {
        if (checkBinaryTree(root) == true) {
            printInorderTraversal(root);
        } else {
            cout << "NOT BINARY TREE";
        }
    }
};

