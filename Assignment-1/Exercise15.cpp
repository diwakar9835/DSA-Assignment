// EXERCISE: 15
// Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

// Solution

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void segregate(Node* head) {
    Node* zero = new Node(0);
    Node* one = new Node(0);
    Node* two = new Node(0);
    Node* zeroHead = zero;
    Node* oneHead = one;
    Node* twoHead = two;

    while (head) {
        if (head->val == 0) {
            zero->next = head;
            zero = zero->next;
        } else if (head->val == 1) {
            one->next = head;
            one = one->next;
        } else {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    two->next = nullptr;
    one->next = twoHead->next;
    zero->next = oneHead->next;

    head = zeroHead->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    
    segregate(head);
    printList(head);

    return 0;
}
