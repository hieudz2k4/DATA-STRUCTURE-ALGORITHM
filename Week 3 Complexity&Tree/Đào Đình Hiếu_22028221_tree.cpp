#include <iostream>
#include <stack>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextNode;

public:
    Node() : data(0), fatherNode(NULL), firstChild(NULL), nextNode(NULL) {}
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data) : data(data), fatherNode(NULL), firstChild(NULL), nextNode(NULL) {}

    Node(int data, Node *fatherNode, Node *firstChild, Node *nextNode) : data(data), fatherNode(fatherNode),
                                                                         firstChild(firstChild), nextNode(nextNode) {}

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Node *getRoot() const {
        return root;
    }

    Tree() {}
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if (root == NULL) { // cây rỗng
            root = new Node(father);
            root->firstChild = new Node(data);
            root->firstChild->fatherNode = root;
            return true;
        } else {
            Node* fatherNode = findNode(root, father); // tìm Node có data = father.
            if (fatherNode  != NULL) { // nếu tìm được fatherNode.
                if (fatherNode->firstChild == NULL) {
                    fatherNode->firstChild = new Node(data);
                    return true;
                }
                else {
                    Node* siblingNode = fatherNode->firstChild;
                    while (siblingNode) {
                        siblingNode = siblingNode->nextNode;
                        if (siblingNode->data == data) return false;
                    }
                    siblingNode = new Node(data);
                    return true;
                }
            }
        }
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        int removeCount = 0; // đếm số lượng Node
        Node* nodeData = findNode(root, data); // tìm node data
        if (nodeData == NULL) removeCount = 0; // nếu data không tồn tại
        else {
            if (nodeData->firstChild == NULL) {
                removeCount = 1; // data là node lá
                nodeData = NULL;
            }
            else {
                removeCount++;
                remove(nodeData->firstChild->data); // xoa firstChild
                remove(nodeData->firstChild->nextNode->data); // xoa nextNode
                nodeData = NULL;
            }
        }
        return removeCount;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* curNode) {
        if (root == NULL) {
            cout << "Cây rống";
        }
        if (curNode == NULL) {
            return;
        }
        cout << curNode->data << " ";
        Node* childNode = curNode->firstChild;
        while (childNode) {
            preorder(childNode);
            childNode = childNode->nextNode;
        }

    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* curNode) {
        if (root == NULL) {
            cout << "Cây trống";
        }
        if (curNode == NULL) {
            return;
        }
        Node* childNode = curNode->firstChild;
        while (childNode) {
            postorder(childNode);
            childNode = childNode->nextNode;
        }
        cout << curNode->data;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree(Node* curNode) {
        int n;
        Node* curNodeChild = curNode->firstChild;
        while (curNodeChild) {
            n++;
            if (!isBinaryTree(curNodeChild)) {
                return false;
            }
            curNodeChild = curNodeChild->nextNode;
        }
        return n <= 2;

    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree(Node* curNode) {
        if (isBinaryTree(root)) {
            int dataCurNode = curNode->data;
            int dataFirstNode = curNode->firstChild->data;
            int dataNextNode = curNode->firstChild->nextNode->data;
            if (dataCurNode <= dataFirstNode || dataCurNode >= dataNextNode) return false;
            else {
                isBinaryTree(curNode->firstChild);
                isBinaryTree(curNode->firstChild->nextNode);
            }
        }
    };

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree(Node* curNode) {
        if (isBinaryTree(root)) {
            int dataCurNode = curNode->data;
            int dataFirstNode = curNode->firstChild->data;
            int dataNextNode = curNode->firstChild->nextNode->data;
            if (dataNextNode > dataCurNode && dataCurNode < dataFirstNode) return false;
            isMaxHeapTree(curNode->firstChild);
            isMaxHeapTree(curNode->nextNode);
            return true;
        }
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node* curNode) {
        if (isBinaryTree(root)) {
            if (curNode == NULL) return;
            else {
                inorder(curNode->firstChild);
                cout << curNode->data << " ";
                inorder(curNode->firstChild->nextNode);
            }
        }
    };

    // Hàm trả về độ cao của cây
    int height() {
        return depth(root);
    }

    // Hàm trả về độ sâu của một Node
    int depth(Node* curNode) {
        if (curNode == NULL) return 0;
        int depthTree = 0;
        Node* childNode = curNode->firstChild;
        while (childNode) {
            int childDepth = depth(childNode);
            depthTree = max(depthTree, childDepth);
            childNode = childNode->nextNode;
        }
        return depthTree + 1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves(Node* curNode) {
        if (curNode->firstChild == NULL) {
            return 1;
        }
        int leaves = 0;
        Node* childNode = curNode->firstChild;
        while (childNode) {
            leaves += numOfLeaves(childNode);
            childNode = childNode->nextNode;
        }
        return leaves;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(Node* curNode) {
        if (curNode == NULL) {
            return INT_MIN; // nếu root rỗng trả về INT_MIN
        }
        int maxVal = curNode->data;
        Node* childNode = curNode->firstChild;
        while (childNode) {
            int childMax = findMax(childNode);
            maxVal = max(maxVal, childMax);
            childNode = childNode->nextNode;
        }
        return maxVal;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild(Node* curNode) {
        int maxChild;
        if (curNode == NULL) return 0;
        else {
            maxChild = totalChildNode(curNode);
            Node* childNode = curNode->firstChild;
            while (childNode) {
                int maxChildNode = totalChildNode(childNode);
                maxChild = max(maxChild, maxChildNode);
                findMaxChild(childNode);
                childNode = childNode->nextNode;
            }
            return maxChild;
        }


    }

    //Hàm tìm Node
    Node* findNode(Node* curNode, int data) {
        //base case
        if (curNode->data) {
            return curNode;
        } else if (curNode == NULL) { // base case
            return NULL;
        } else { // recursive
            if (curNode->firstChild) {
                findNode(curNode->firstChild, data);
            }
            if (curNode && curNode->nextNode) {
                findNode(curNode->nextNode, data);
            }
        }
    }

    int totalChildNode(Node* curNode) {
        int total = 0;
        if (curNode == NULL) return 0;
        else {
            Node* childNode = curNode->firstChild;
            while (childNode) {
                total++;
                childNode = childNode->nextNode;
            }
            return total;
        }
    }
};

/*
int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree tree;
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(1, 4);
    tree.insert(1, 5);
    tree.insert(1, 6);
    tree.insert(1, 7);
    tree.insert(1, 8);
    tree.insert(1, 9);
    tree.insert(1, 10);
    tree.insert(2, 11);
    tree.insert(2, 12);
    tree.insert(3, 15);
    tree.insert(3, 16);
    tree.insert(16, 17);
    tree.insert(17, 18);
    tree.insert(5, 19);
    tree.insert(5, 20);
    tree.insert(5, 21);
    tree.insert(5, 22);
    tree.insert(5, 23);
    tree.insert(5, 24);
    tree.insert(5, 25);
    tree.insert(5, 26);
    tree.insert(5, 27);
    tree.insert(28, 29);
    tree.insert(30, 41);
    tree.insert(30, 32);
    tree.insert(100, 100);
    tree.insert(1000, 101);
    tree.insert(1000, 1);

    // Test thử các hàm của lớp cây
    cout << "Preorder Traversal: ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.getRoot());
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder(tree.getRoot());

    cout << "Height of Tree: " << tree.height() << endl;
    cout << "Depth of Tree: " << tree.depth(tree.getRoot()) << endl;
    cout << "Number of Leaves: " << tree.numOfLeaves(tree.getRoot()) << endl;
    cout << "Maximum Value: " << tree.findMax(tree.getRoot()) << endl;
    cout << "Maximum Child of Node : " << tree.findMaxChild(tree.getRoot()) << endl;

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    tree.insert(1, 2);
    tree.insert(1, 0);
    tree.insert(2, 5);
    tree.insert(5, 3);

    cout << "Binary Tree: " << tree.isBinaryTree(tree.getRoot()) << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.getRoot());
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder(tree.getRoot());

    cout << "Height of Tree: " << tree.height() << endl;
    cout << "Depth of Tree: " << tree.depth(tree.getRoot()) << endl;
    cout << "Number of Leaves: " << tree.numOfLeaves(tree.getRoot()) << endl;
    cout << "Maximum Value: " << tree.findMax(tree.getRoot()) << endl;
    cout << "Maximum Child of Node : " << tree.findMaxChild(tree.getRoot()) << endl;

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    tree.insert(10, 5);
    tree.insert(10, 7);
    tree.insert(7, 6);
    tree.insert(6, 5);

    cout << "MaxHeap" << tree.isMaxHeapTree(tree.getRoot()) << endl;
    cout << "Preorder Traversal: ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.getRoot());
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder(tree.getRoot());

    cout << "Height of Tree: " << tree.height() << endl;
    cout << "Depth of Tree: " << tree.depth(tree.getRoot()) << endl;
    cout << "Number of Leaves: " << tree.numOfLeaves(tree.getRoot()) << endl;
    cout << "Maximum Value: " << tree.findMax(tree.getRoot()) << endl;
    cout << "Maximum Child of Node : " << tree.findMaxChild(tree.getRoot()) << endl;

    cout << "MaxHeap" << tree.isMaxHeapTree(tree.getRoot()) << endl;

    return 0;
}
*/