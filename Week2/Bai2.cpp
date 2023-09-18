#include <iostream>

using namespace std ;


class Node {
private:
    int value = NULL;
    Node* next = NULL;
public:
    Node(int value, Node* afterNode) {
        this->value = value;
        this->next = afterNode;
    }
    void setValue(int value) {
        this->value = value;
    }
    int getValue() {
        return this->value;
    }
    void setNext(Node* afterNode) {
        this->next = afterNode;
    }
    Node* getNext() {
        return this->next;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int p, int x) {
        if (p < 0) {
            cout << "vi tri khong hop le";
        }
        Node* newNode = new Node(x, NULL);
        if (p == 0) {
            newNode->setNext(head);
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
        } else {
            Node* cur = head;
            int curIndex = 0;

            // cur tien den Node tai vi tri p-2
            while (cur != NULL && curIndex < p - 1) {
                cur = cur->getNext();
                curIndex++;
            }
            if (cur == NULL) {
                delete newNode;
                return;
            }
            newNode->setNext(cur->getNext());
            cur->setNext(newNode);
            if (newNode->getNext() == NULL) {
                tail = newNode;
            }
        }
    }
    void del(int p) {
        if (p < 0 || head == NULL) {
            cout << "vi tri khong hop le hoac linkedlist rong";
        }
        if (p == 0) {
            Node* t = head;
            head = head->getNext();
            delete t;
            // Neu head == NULL thi linkedlist rong
            if (head == NULL) {
                tail = NULL;
            }
        } else {
            Node* cur = head;
            int curIndex = 0;

            // cur -> Node tai index p-2
            while (cur != NULL && curIndex < p - 1) {
                cur = cur->getNext();
                curIndex++;
            }
            if (cur->getNext() == NULL) {
                cout << "Vi tri p khong ton tai node";
                return;
            }

            Node* t = cur->getNext();
            cur->setNext(t->getNext());
            delete t;
            if (cur->getNext() == NULL) {
                tail = cur;
            }
        }
    }
    void printLinkedList() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->getValue() << " ";
            cur = cur->getNext();
        }
    }
};

/*
int main() {
    int n ; cin>>n ;
    LinkedList ll1;
    for(int i = 0 ; i<n ; i++) {
        string s; cin >> s;
        if (s == "insert") {
            int p, x; cin >> p >> x;
            ll1.insert(p, x);
        } else if (s == "delete") {
            int p; cin >> p;
            ll1.del(p);
        }
    }
    ll1.printLinkedList();
}
 */


