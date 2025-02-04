// EXERCISE: 10
// Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

// Solution

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* removeNodes(Node* head) {
    if (!head) return nullptr;
    
    head = reverseList(head);
    
    Node* maxNode = head;
    Node* current = head->next;
    Node* prev = head;
    
    while (current) {
        if (current->val < maxNode->val) {
            prev->next = current->next;
        } else {
            maxNode = current;
            prev = current;
        }
        current = current->next;
    }
    
    return reverseList(head);
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(13);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(8);

    cout << "Original List: ";
    printList(head);
    
    head = removeNodes(head);
    
    cout << "Modified List: ";
    printList(head);

    return 0;
}
