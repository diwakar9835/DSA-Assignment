// EXERCISE: 9
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null. 8 marks
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// Solution

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    Node* newHead = head->next;
    Node* original = head;
    Node* copy = newHead;
    while (original) {
        original->next = original->next->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << "Value: " << head->val;
        if (head->random) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: null";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Node* copiedList = copyRandomList(head);
    printList(copiedList);

    return 0;
}
