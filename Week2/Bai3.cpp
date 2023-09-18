#include <iostream>

using namespace std ;

class Node {
private:
    Node* previous;
    int value;
    Node* next;
public:
    //constructor
    Node(int value) {
        this->value = value;
    }
    // set get Previous
    void setPrevious(Node* previous) { this->previous = previous; }
    Node* getPrevious() { return this->previous; }

    // set get value
    void setValue(int value) { this->value = value; }
    int getValue() { return this->value; }

    // set get next;
    void setNext(Node* next) { this->next = next; }
    Node* getNext() { return this->next; }
};

class DoubleLinkedList {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int totalNode = 0;

public:
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            //List rong
            head = tail = newNode;
        } else {
            newNode->setPrevious(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        totalNode++;
    }

    int count_triplets() {
        if (head == NULL || totalNode < 3) {
            cout << "List rong hoac khong du phan tu." << endl;
            return 0; // Return 0 triplets in these cases
        }

        Node* cur = head->getNext();
        int result = 0;

        while (cur->getNext() != NULL) {
            Node* leftCur = cur->getPrevious();
            Node* rightCur = cur->getNext();

            if (leftCur->getValue() + cur->getValue() + rightCur->getValue() == 0) {
                result++;
            }
            cur = cur->getNext();
        }
        return result;
    }

    void printDoubleLinkedList() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->getValue() << " ";
            cur = cur->getNext();
        }
    }
};

/*
int main() {
    int n; cin >> n;
    DoubleLinkedList dll;
    for (int i = 0; i < n; i++) {
        int value; cin >> value;
        dll.insertEnd(value);
    }
    dll.printDoubleLinkedList();
    cout << endl;
    cout << dll.count_triplets();
    return 0 ;
}
*/